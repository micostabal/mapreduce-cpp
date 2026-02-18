#include <chrono>
#include <unordered_map>

namespace mapreduce::master::state {
    
class WorkerState {
private:
    int worker_id;
    std::chrono::time_point<std::chrono::steady_clock> last_heartbeat;
    bool alive;
public:
    WorkerState(int id);
    void to_string();
    int get_worker_id();
};

struct MasterState {
private:
    std::unordered_map<int, mapreduce::master::state::WorkerState> workers;

    enum Phase { MAP, REDUCE, DONE } phase;
public:
    MasterState();
    void add_worker_state(mapreduce::master::state::WorkerState &new_worker_info);
};



}