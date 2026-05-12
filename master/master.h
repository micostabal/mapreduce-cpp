#pragma once
#include <string>
#include <grpcpp/grpcpp.h>
#include <state.h>

using grpc::Server;

void master_some_function();

namespace mapreduce::master {

    class Master {
        private:
            std::unique_ptr<Server> server;
            mapreduce::master::state::MasterState state;
        public:
            Master(std::unique_ptr<Server> server);
            void init();
            void start();
            std::string to_string();
    };
}