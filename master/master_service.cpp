#include "master_service.h"
#include <iostream>

namespace mapreduce::master {

grpc::Status MasterServiceImpl::Heartbeat(
    grpc::ServerContext*,
    const HeartbeatRequest* request,
    HeartbeatResponse* response) {

  std::cout << "Heartbeat from worker "
            << request->worker_id() << std::endl;

  response->set_ok(true);
  return grpc::Status::OK;
}

}