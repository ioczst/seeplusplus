#include <gtest/gtest.h>
#include "example.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  int ret = Sum(1,2);  
  EXPECT_EQ(ret, 3);
}

TEST(HelloTest, BasicAssertions2) {
  int ret = Sum(1,2);  
  EXPECT_EQ(ret, 5);
}