#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <grpcpp/grpcpp.h>

#include "master_client.h"
#include <common/utils/string_utils.h>


int main() {
    
    std::vector<std::string> words = common::utils::string_utils::split_words("Jesus is King!");
    std::cout << "Word count: " << words.size() << std::endl;
    std::cout << "MapReduce Worker" << std::endl;
    
    auto channel = grpc::CreateChannel(
      "localhost:50051",
      grpc::InsecureChannelCredentials());

    mapreduce::worker::MasterClient client(channel);

    bool ok = client.SendHeartbeat(1);

    std::cout << "Heartbeat result: " << ok << std::endl;
    return 0;
}