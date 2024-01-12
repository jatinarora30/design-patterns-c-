#include <iostream>
#include <benchmark/benchmark.h>

void BM_Malloc(benchmark::State& state)
{
    for(auto _ :state)
    {g
        void* p=malloc(64);
        benchmark::DoNotOptimize(p);
    }
    state.SetItemsProcessed(state.iterations());
}
void BM_Malloc_free(benchmark::State& state)
{
    const size_t S= state.range(0);
    for(auto _ :state)
    {
        void* p=malloc(S);
        benchmark::DoNotOptimize(p);
        free(p);
    }
    state.SetItemsProcessed(state.iterations());
}

BENCHMARK(BM_Malloc);
BENCHMARK(BM_Malloc_free)->RangeMultiplier(2)->Range(2709880,182010192);
int main(int argc, char **argv) {


  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();

  return 0; 
}