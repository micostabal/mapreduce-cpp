#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>
#include <master.h>
#include <master_service.h>
#include <common/utils/string_utils.h>

using grpc::Server;
using grpc::ServerBuilder;

int main() {
    const std::string address = "0.0.0.0:50051";
    
    std::cout << "MapReduce Master" << std::endl;

    mapreduce::master::service::MasterServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Master listening on " << address << std::endl;
    
    mapreduce::master::Master master(std::move(server));

    master.init();

    std::cout << master.to_string() << std::endl;

    master.start();
    return 0;
}