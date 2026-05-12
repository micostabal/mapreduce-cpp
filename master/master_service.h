#include "master.grpc.pb.h"

namespace mapreduce::master::service {

class MasterServiceImpl final : public MasterService::Service {
public:
  grpc::Status Heartbeat(
      grpc::ServerContext* context,
      const HeartbeatRequest* request,
      HeartbeatResponse* response) override;
      
  grpc::Status RegisterWorker(
      grpc::ServerContext* context,
      const google::protobuf::Empty* request,
      RegisterResponse* response) override;
};

}