#include <gtest/gtest.h>
#include <state.h>

TEST(MapperTest, BasicTruth) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(MapperTest, MasterStateShouldStartWithZeroWorkers) {
  
  mapreduce::master::state::MasterState master_state;
  
  EXPECT_EQ(master_state.get_amount_workers(), 0);
  
  master_state.add_worker("address1");
  
  EXPECT_EQ(master_state.get_amount_workers(), 1);
  
  master_state.add_worker("address2");
  
  EXPECT_EQ(master_state.get_amount_workers(), 2);
}