#include "master_client.h"

namespace mapreduce::worker {

MasterClient::MasterClient(std::shared_ptr<grpc::Channel> channel)
    : stub_(mapreduce::master::MasterService::NewStub(channel)) {}

bool MasterClient::SendHeartbeat(int worker_id) {
  mapreduce::master::HeartbeatRequest request;
  request.set_worker_id(worker_id);

  mapreduce::master::HeartbeatResponse response;
  grpc::ClientContext context;

  grpc::Status status = stub_->Heartbeat(&context, request, &response);

  return status.ok() && response.ok();
}

}