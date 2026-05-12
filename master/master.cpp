#include <iostream>
#include <master.h>
#include <master_service.h>

void master_some_function() {
    std::cout<< "From master here" <<std::endl;
}

using grpc::Server;

namespace mapreduce::master {
    Master::Master(std::unique_ptr<Server> server) {
        this->server=std::move(server);
    };

    void Master::init() {
        
        int MAP_TASKS = 5;
        int REDUCE_TASKS = 3;

        for (int i=0;i<MAP_TASKS;i++) {
            mapreduce::master::task::MasterTask task_m(
                i,
                mapreduce::master::task::MasterTask::TaskType::MAP
            );
            this->state.add_map_task(task_m);
        }

        for (int i=0;i<REDUCE_TASKS;i++) {
            mapreduce::master::task::MasterTask task_r(
                i,
                mapreduce::master::task::MasterTask::TaskType::MAP
            );
            this->state.add_reduce_task(task_r);
        }

    };

    void Master::start() {
        std::cout << "Starting master" << std::endl;

        this->server.get()->Wait();
    };

    std::string Master::to_string() {
        return this->state.to_string();
    }
}