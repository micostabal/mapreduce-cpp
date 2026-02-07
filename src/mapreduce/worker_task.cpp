#include <iostream>
#include <string>
#include "mapreduce/worker_task.h"

namespace mapreduce {

WorkerTask::WorkerTask(int id, std::string path) : id(id), file_path(path) {}

std::string WorkerTask::to_string() {
    return "WorkerTask: "+this->file_path+" (id: "+std::to_string(this->id)+")";
}
}