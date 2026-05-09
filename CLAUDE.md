# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

Configure and build (Ninja backend, first time or after CMakeLists changes):
```bash
cmake -S . -B build -G Ninja
cmake --build build
```

Use the helper scripts for common workflows:
```bash
./scripts/run_master.sh       # build + run master (gRPC server on :50051)
./scripts/run_worker.sh       # build + run worker (connects to localhost:50051)
./scripts/run_tests.sh        # build + run all tests via ctest
```

Run a single test suite:
```bash
cd build && ctest -R common_tests --output-on-failure   # or worker_tests, master_tests
```

Regenerate protobuf/gRPC code after editing `proto/master.proto`:
```bash
make master_proto   # outputs to generated/, commit the result
```

## Architecture

Two separate processes communicate over gRPC:

**Master** (`master/`) — gRPC server on `0.0.0.0:50051`.
- `MasterServiceImpl` (extends generated `MasterService::Service`) handles `Heartbeat` and `RegisterWorker` RPCs.
- `MasterState` owns a map of `WorkerState` objects keyed by worker ID and tracks the job phase (`MAP → REDUCE → DONE`). Each `WorkerState` records the last heartbeat timestamp and alive status.

**Worker** (`worker/`) — connects to `localhost:50051` on startup.
- Calls `RegisterWorker()` to obtain an integer `worker_id`, then spawns a thread that calls `SendHeartbeat(worker_id)` every second indefinitely.
- `MasterClient` wraps the generated gRPC stub.
- `Worker` and `WorkerTask` model the in-process task state (not yet wired to actual map/reduce logic).

**Shared proto contract** (`proto/master.proto` → `generated/`).
- Generated `.pb.cc/.h` and `.grpc.pb.cc/.h` files are committed to `generated/` and compiled into the `proto_master` CMake library, which both `master_lib` and `worker_lib` link against.
- The `generated/` directory is added as a public include path by `proto/CMakeLists.txt`, so headers are included as `#include "master.grpc.pb.h"`.

**Common library** (`common/`).
- Public headers live in `include/common/` (not alongside the `.cpp`). Include as `#include <common/utils/string_utils.h>`.

**Tests** (`tests/`).
- GoogleTest is fetched at configure time via `FetchContent` (v1.14.0). Test executables mirror the source tree: `tests/common/`, `tests/worker/`, `tests/master/`.
