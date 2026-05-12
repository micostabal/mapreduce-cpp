#include <task.h>
#include <optional>
#include <vector>
#include <string>

namespace mapreduce::master::task {

    MasterTask::MasterTask(
        int id,
        mapreduce::master::task::MasterTask::TaskType type
    ): task_id(id), type(type) {
        this->status = mapreduce::master::task::MasterTask::TaskStatus::TODO;
    }

    std::string MasterTask::to_string() {
        return "[id: "+std::to_string(this->task_id) +
            "] type:"+std::to_string(this->type)+
            " status: "+std::to_string(this->status);
    }
}