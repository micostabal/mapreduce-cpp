#include <iostream>
#include <string>
#include <vector>
#include "mapreduce/worker.h"
#include "mapreduce/worker_task.h"

namespace mapreduce {

Worker::Worker(int id, std::string name) : name(std::move(name)), id(id) {}

int Worker::get_amount_tasks() {
    return this->completed_tasks.size();
}

std::string Worker::to_string() {
    return "Worker: "+this->name + " (id: "+std::to_string(this->id)+")";
}

void Worker::work() {
    std::cout << "I'm working" << std::endl;

    mapreduce::WorkerTask new_task(1, "/tmp/file_1.txt");

    this->completed_tasks.push_back(new_task);

    std::cout << "Finished working" << std::endl;
}
}