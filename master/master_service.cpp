#include <master_service.h>
#include <vector>
#include <iostream>
#include <state.h>



namespace mapreduce::master::service {

MasterServiceImpl::MasterServiceImpl(mapreduce::master::state::MasterState& master_state): master_state(master_state) {};

grpc::Status MasterServiceImpl::Heartbeat(
    grpc::ServerContext*,
    const HeartbeatRequest* request,
    HeartbeatResponse* response) {
    
    this->master_state.state_mutex.lock();
    
    std::cout << "Heartbeat from worker "
              << request->worker_id() << std::endl;

    response->set_ok(true);

    mapreduce::master::state::WorkerState worker_state = this->master_state.get_worker_state_by_id(
      request->worker_id());

    worker_state.update_last_heartbeat();
    
    this->master_state.state_mutex.unlock();

  return grpc::Status::OK;
}

grpc::Status MasterServiceImpl::RegisterWorker(
    grpc::ServerContext* context,
    const RegisterRequest* request,
    RegisterResponse* response) {

  std::cout << "Registering worker" << std::endl;

  this->master_state.state_mutex.lock();
  
  mapreduce::master::state::WorkerState new_worker_state = this->master_state.add_worker(request->address());
  
  int new_worker_id = new_worker_state.get_worker_id();

  response->set_worker_id(new_worker_id);
  
  std::cout << "Worker registered" << new_worker_state.to_string() << std::endl;

  this->master_state.state_mutex.unlock();
  
  return grpc::Status::OK;
}

}