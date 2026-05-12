#pragma once
#include <chrono>
#include <string>
#include <optional>
#include <task.h>
#include <unordered_map>

namespace mapreduce::master::state {
    
class WorkerState {
private:
    int worker_id;
    std::chrono::time_point<std::chrono::steady_clock> last_heartbeat;
    bool alive;
    std::optional<int> current_task_id;
public:
    WorkerState(int id);
    std::string to_string();
    int get_worker_id();
};

struct MasterState {
private:
    std::unordered_map<int, mapreduce::master::state::WorkerState> workers;
    std::unordered_map<int, mapreduce::master::task::MasterTask> map_tasks;
    std::unordered_map<int, mapreduce::master::task::MasterTask> reduce_tasks;
public:
    MasterState();
    void add_worker_state(mapreduce::master::state::WorkerState &new_worker_info);
    int get_amount_workers();
    void add_map_task(mapreduce::master::task::MasterTask& new_map_task);
    void add_reduce_task(mapreduce::master::task::MasterTask& new_reduce_task);
    std::string to_string();
};



}