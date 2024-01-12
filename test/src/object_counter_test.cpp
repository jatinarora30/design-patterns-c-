#include "object_counter.h" // Include the object_counter class header
#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
#define REPEAT() for (int i = 0; i < 10; i++)
TEST(AClassTest, NumReturnTest) {
  A a;

  // Test the return value
  EXPECT_EQ(a.num_return(3), 6); // Expecting 3 * 2 = 6

  // Optionally, you can also capture and check the output to std::cout
  testing::internal::CaptureStdout();
  a.num_return(4);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "8\n"); // Expecting "4 * 2 = 8\n"
}

TEST(Scoped_ptr, Construct) {
  object_counter::all_count = object_counter::count = 0;
  object_counter *p = new object_counter;
  EXPECT_EQ(1, object_counter::count);
  EXPECT_EQ(1, object_counter::all_count);
  delete p;
  EXPECT_EQ(0, object_counter::count);
  EXPECT_EQ(1, object_counter::all_count);
}
TEST(RAII, AcquireRelease) {
  object_counter::all_count = object_counter::count = 0;
  {
    raii<object_counter> p(new object_counter);
    EXPECT_EQ(1, object_counter::count);
    EXPECT_EQ(1, object_counter::all_count);
  }
  EXPECT_EQ(0, object_counter::count);
  EXPECT_EQ(1, object_counter::all_count);
}

TEST(Scoped_PTR, AcquireRelease) {
  object_counter::all_count = object_counter::count = 0;
  {
    scoped_ptr<object_counter> p(new object_counter);
    EXPECT_EQ(1, object_counter::count);
    EXPECT_EQ(1, object_counter::all_count);
  }
  EXPECT_EQ(0, object_counter::count);
  EXPECT_EQ(1, object_counter::all_count);
}
TEST(Scoped_PTR, EarlyReturn) {
  object_counter::all_count = object_counter::count = 0;
  do {
    scoped_ptr<object_counter> p(new object_counter);
    break;
  } while (false);
  EXPECT_EQ(0, object_counter::count);
  EXPECT_EQ(1, object_counter::all_count);
}

TEST(Scoped_PTR, THrowNoLeak) {
  object_counter::all_count = object_counter::count = 0;
  try {
    scoped_ptr<object_counter> p(new object_counter);
    throw 1;
  } catch (...) {
  }
  EXPECT_EQ(0, object_counter::count);
  EXPECT_EQ(1, object_counter::all_count);
}

void BM_rawptr_derefenrence(benchmark::State &state) {
  int *p = new int;
  for (auto _ : state) {
   // for(int i=0;i<100;i++)
    benchmark::DoNotOptimize(*p);
  }
  delete p;
  state.SetItemsProcessed(32*state.iterations());
}

void BM_scoped_derefenrence(benchmark::State &state) {
  scoped_ptr<int> p(new int);
  for (auto _ : state) {
   // for(int i=0;i<100;i++)
    benchmark::DoNotOptimize(*p);
  }
  
  state.SetItemsProcessed(32*state.iterations());
}
void BM_unique_derefenrence(benchmark::State &state) {
  std::unique_ptr<int> p(new int);
  for (auto _ : state) {
  //  for(int i=0;i<100;i++)
    benchmark::DoNotOptimize(*p);
  }
  
  state.SetItemsProcessed(32*state.iterations());
}
BENCHMARK(BM_rawptr_derefenrence);
BENCHMARK(BM_scoped_derefenrence);
BENCHMARK(BM_unique_derefenrence);
int main(int argc, char **argv) {
//   testing::InitGoogleTest(&argc, argv);
//   int gtest_result = RUN_ALL_TESTS();

  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();

  return 0; // Return the result of Google Test
}