#include <iostream>
#include <memory>
#include <grpcpp/grpcpp.h>
#include "master_service.h"
#include <common/utils/string_utils.h>

using grpc::Server;
using grpc::ServerBuilder;

int main() {
    std::cout << "MapReduce Master" << std::endl;
    
    const std::string address = "0.0.0.0:50051";

    mapreduce::master::MasterServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Master listening on " << address << std::endl;
    
    server->Wait();
    return 0;
}