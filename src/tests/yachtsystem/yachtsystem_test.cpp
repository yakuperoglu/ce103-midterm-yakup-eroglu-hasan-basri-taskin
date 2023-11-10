//#define ENABLE_YACHTSYSTEM_TEST  // Uncomment this line to enable the Yachtsystem tests

#include "gtest/gtest.h"
#include "../../yachtsystem/header/yachtsystem.h"  // Adjust this include path based on your project structure

using namespace Coruh::Yachtsystem;

class YachtsystemTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Setup test data
  }

  void TearDown() override {
    // Clean up test data
  }
};

TEST_F(YachtsystemTest, TestAdd) {
  double result = Yachtsystem::add(5.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(YachtsystemTest, TestSubtract) {
  double result = Yachtsystem::subtract(5.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(YachtsystemTest, TestMultiply) {
  double result = Yachtsystem::multiply(5.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(YachtsystemTest, TestDivide) {
  double result = Yachtsystem::divide(6.0, 3.0);
  EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(YachtsystemTest, TestDivideByZero) {
  EXPECT_THROW(Yachtsystem::divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char **argv) {
#ifdef ENABLE_YACHTSYSTEM_TEST
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  return 0;
#endif
}
