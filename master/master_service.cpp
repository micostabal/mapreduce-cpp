#include <master_service.h>
#include <vector>
#include <iostream>
#include <state.h>

int new_worker_id=0;

mapreduce::master::state::MasterState master_state;


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

grpc::Status MasterServiceImpl::RegisterWorker(
    grpc::ServerContext* context,
    const google::protobuf::Empty* request,
    RegisterResponse* response) {

  std::cout << "Registering worker" << std::endl;

  response->set_worker_id(new_worker_id);
  
  mapreduce::master::state::WorkerState worker_state(new_worker_id);
  
  master_state.add_worker_state(worker_state);
  
  new_worker_id++;
  
  std::cout << "Worker" << worker_state.get_worker_id() << "Registered" << std::endl;
  
  return grpc::Status::OK;
}

}