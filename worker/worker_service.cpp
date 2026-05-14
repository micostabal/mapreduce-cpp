#include <string>
#include <worker_service.h>


namespace mapreduce::worker::service {
    grpc::Status WorkerServiceImpl::AssignMapTask(grpc::ServerContext*,
    const AssignMapTaskRequest* request,
    AssignMapTaskResponse* response) {
        
        int task_id = request->task_id();
        std::string file_name = request->file_name();


        // update inner state

        response->set_ok(true);

        return grpc::Status::OK;
    }
}