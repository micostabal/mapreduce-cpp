#include "worker.grpc.pb.h"

namespace mapreduce::worker::service {

class WorkerServiceImpl final : public WorkerService::Service {

public:
  grpc::Status AssignMapTask(
      grpc::ServerContext* context,
      const AssignMapTaskRequest* request,
      AssignMapTaskResponse* response) override;
};

}