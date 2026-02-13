#pragma once

#include <memory>

#include <grpcpp/grpcpp.h>
#include "master.grpc.pb.h"

namespace mapreduce::worker {

class MasterClient {
public:
  explicit MasterClient(std::shared_ptr<grpc::Channel> channel);

  bool SendHeartbeat(int worker_id);

private:
  std::unique_ptr<mapreduce::master::MasterService::Stub> stub_;
};

}