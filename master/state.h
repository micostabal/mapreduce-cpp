#pragma once
#include <chrono>
#include <string>
#include <optional>
#include <mutex>
#include <task.h>
#include <unordered_map>

namespace mapreduce::master::state {
    
class WorkerState {
private:
int worker_id;
std::string address;
std::chrono::time_point<std::chrono::steady_clock> last_heartbeat;
bool alive;
std::optional<int> current_task_id;
public:
    WorkerState(int id, std::string address);
    std::string to_string();
    int get_worker_id();
    std::string get_address();
    void update_last_heartbeat();
};

struct MasterState {
    private:
int new_worker_id;
std::unordered_map<int, mapreduce::master::state::WorkerState> workers;
std::unordered_map<int, mapreduce::master::task::MasterTask> map_tasks;
std::unordered_map<int, mapreduce::master::task::MasterTask> reduce_tasks;
public:
    std::mutex state_mutex;
    MasterState();
    WorkerState add_worker(std::string new_address);
    int get_amount_workers();
    mapreduce::master::state::WorkerState& get_worker_state_by_id(int worker_id);
    void add_map_task(mapreduce::master::task::MasterTask& new_map_task);
    void add_reduce_task(mapreduce::master::task::MasterTask& new_reduce_task);
    std::string to_string();
};



}