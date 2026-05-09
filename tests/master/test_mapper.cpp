#include <gtest/gtest.h>
#include <state.h>

TEST(MapperTest, BasicTruth) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(MapperTest, MasterStateShouldStartWithZeroWorkers) {
  
  mapreduce::master::state::MasterState master_state;
  
  EXPECT_EQ(master_state.get_amount_workers(), 0);
  
  mapreduce::master::state::WorkerState worker_state(1);
  
  master_state.add_worker_state(worker_state);
  
  EXPECT_EQ(master_state.get_amount_workers(), 1);

  mapreduce::master::state::WorkerState worker_state_two(2);
  
  master_state.add_worker_state(worker_state_two);
  
  EXPECT_EQ(master_state.get_amount_workers(), 2);
}