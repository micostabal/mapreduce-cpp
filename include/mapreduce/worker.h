#pragma once
#include "mapreduce/worker.h"
#include "mapreduce/worker_task.h"
#include <string>
#include <vector>

namespace mapreduce {

class Worker {
    private:
        int id;
        std::string name;
        std::vector<mapreduce::WorkerTask> completed_tasks;
    public:
        Worker(int id, std::string);
        std::string to_string();
        int get_amount_tasks();
        void work();
};

}
