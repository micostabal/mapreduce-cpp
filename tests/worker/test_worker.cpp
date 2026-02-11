#include <gtest/gtest.h>
#include <string>
#include "worker.h"

TEST(WorkerSuiteTest, WorkerBasicTest) {
    mapreduce::Worker worker(1, "my_worker");
    ASSERT_EQ("Worker: my_worker (id: 1)", worker.to_string());
}

TEST(WorkerSuiteTest, WorkerWorkTest) {
    mapreduce::Worker worker(1, "my_worker");

    ASSERT_EQ(0, worker.get_amount_tasks());
    
    worker.work();

    ASSERT_EQ(1, worker.get_amount_tasks());
}