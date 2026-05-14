#include "master.grpc.pb.h"
#include "state.h"

namespace mapreduce::master::service {

class MasterServiceImpl final : public MasterService::Service {
private:
    mapreduce::master::state::MasterState& master_state;
public:
    MasterServiceImpl(mapreduce::master::state::MasterState& master_state);
  
    grpc::Status Heartbeat(
        grpc::ServerContext* context,
        const HeartbeatRequest* request,
        HeartbeatResponse* response) override;
      
    grpc::Status RegisterWorker(
        grpc::ServerContext* context,
        const RegisterRequest* request,
        RegisterResponse* response) override;
};

}