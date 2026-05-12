#include <chrono>
#include <state.h>
# include <task.h>


namespace mapreduce::master::state {
  // Worker State

  WorkerState::WorkerState(int id): worker_id(id) {
    this->last_heartbeat=std::chrono::steady_clock::now();
    this->alive=true;
    this->current_task_id=std::nullopt;
  }
  
  std::string WorkerState::to_string() {
    std::string repr = "Worker: id="+std::to_string(this->worker_id);

    repr = repr + ", alive="+std::to_string(this->alive);

    if (this->current_task_id.has_value()) {
      repr = repr + ", " + std::to_string(this->current_task_id.value());
    }
    return repr;
  }
  
  int WorkerState::get_worker_id() {
    return this->worker_id;
  }

  // Master State
  
  MasterState::MasterState() {}
  
  void MasterState::add_worker_state(mapreduce::master::state::WorkerState &new_worker_state) {
    this->workers.emplace(new_worker_state.get_worker_id(), new_worker_state);
  };
  
  int MasterState::get_amount_workers() {
    return this->workers.size();
  };

  void MasterState::add_map_task(mapreduce::master::task::MasterTask& new_map_task) {
    this->map_tasks.insert({new_map_task.task_id, new_map_task});
  };

  void MasterState::add_reduce_task(mapreduce::master::task::MasterTask& new_reduce_task) {
    this->reduce_tasks.insert({new_reduce_task.task_id, new_reduce_task});
  };

  std::string MasterState::to_string() {
    std::unordered_map<int, mapreduce::master::task::MasterTask>::iterator map_tasks_iterator;

    int task_count = 0;
    for (auto iterator = this->map_tasks.begin();iterator!=this->map_tasks.end();iterator++) {
      task_count++;
    };
    for (auto iterator = this->reduce_tasks.begin();iterator!=this->reduce_tasks.end();iterator++) {
      task_count++;
    };
    
    return "Workers: " + std::to_string(this->workers.size()) + ", total tasks: "+std::to_string(task_count);
  };
}