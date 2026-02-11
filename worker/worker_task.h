#pragma once
#include <string>

namespace mapreduce {

class WorkerTask {
    private:
        int id;
        std::string file_path;
    public:
        WorkerTask(int id, std::string path);
        std::string to_string();
};

}