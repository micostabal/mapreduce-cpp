#include <chrono>
#include <state.h>

namespace mapreduce::master::state {
  WorkerState::WorkerState(int id): worker_id(id) {
    this->last_heartbeat=std::chrono::steady_clock::now();
    this->alive=true;
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
}