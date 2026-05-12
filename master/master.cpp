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
        
        mapreduce::master::task::MasterTask task1(
            1,
            mapreduce::master::task::MasterTask::TaskType::MAP
        );

        mapreduce::master::task::MasterTask task2(
            2,
            mapreduce::master::task::MasterTask::TaskType::MAP
        );

        mapreduce::master::task::MasterTask task3(
            3,
            mapreduce::master::task::MasterTask::TaskType::MAP
        );

        this->state.add_map_task(task1);
        this->state.add_map_task(task2);
        this->state.add_map_task(task3);
    };

    void Master::start() {
        std::cout << "Starting master" << std::endl;

        this->server.get()->Wait();
    };

    std::string Master::to_string() {
        return this->state.to_string();
    }
}