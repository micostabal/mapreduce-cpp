#pragma once
#include <optional>
#include <vector>
#include <string>

namespace mapreduce::master::task {

    class MasterTask {
        public:
            int task_id;
            enum TaskType { MAP, REDUCE };
            enum TaskStatus { TODO, IN_PROGRESS, DONE };
            MasterTask(int id, TaskType type);
            std::string to_string();
        private:
            enum TaskType type;
            enum TaskStatus status;
            std::optional<int> current_worker;
            std::vector<std::string> results;
    };
}