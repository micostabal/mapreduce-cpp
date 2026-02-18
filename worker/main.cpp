#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <thread>
#include <chrono>
#include <grpcpp/grpcpp.h>

#include "master_client.h"
#include <common/utils/string_utils.h>


void heartbeat_thread(mapreduce::worker::MasterClient &client, int worker_id) {
    std::cout << "Starting to emit heartbeats every 1 second" << std::endl;
    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bool ok = client.SendHeartbeat(worker_id);

        std::cout << "Heartbeat result: " << ok << std::endl;
    }
}

int main() {
    std::vector<std::string> words = common::utils::string_utils::split_words("Jesus is King!");
    std::cout << "Word count: " << words.size() << std::endl;
    std::cout << "MapReduce Worker" << std::endl;
    
    auto channel = grpc::CreateChannel(
      "localhost:50051",
      grpc::InsecureChannelCredentials());

    mapreduce::worker::MasterClient client(channel);
    
    int worker_id = client.RegisterWorker();
    
    std::cout << "Successfully registered worker, id " << worker_id << std::endl;
    
    std::vector<std::thread> threads;
    
    threads.push_back(std::thread(heartbeat_thread, std::ref(client), worker_id));
    
    threads[0].join();
    
    return 0;
}