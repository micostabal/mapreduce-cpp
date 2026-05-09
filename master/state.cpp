#include <chrono>
#include <state.h>

namespace mapreduce::master::state {
  WorkerState::WorkerState(int id): worker_id(id) {
    this->last_heartbeat=std::chrono::steady_clock::now();
    this->alive=true;
  }
  
  std::string WorkerState::to_string() {
    return "Worker: id="+std::to_string(this->worker_id)+", alive="+std::to_string(this->alive);
  }
  
  int WorkerState::get_worker_id() {
    return this->worker_id;
  }
  
  MasterState::MasterState() {
    this->phase=MasterState::Phase::MAP;
  }
  
  void MasterState::add_worker_state(mapreduce::master::state::WorkerState &new_worker_state) {
    this->workers.emplace(new_worker_state.get_worker_id(), new_worker_state);
  }
  
  int MasterState::get_amount_workers() {
    return this->workers.size();
  }
}