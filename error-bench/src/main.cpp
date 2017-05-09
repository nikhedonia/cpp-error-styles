#include "benchmark/benchmark.h"
#include <memory>

int test(int x, int& out) {
  if(x>0) {
    out = 1;
    return 0;
  } else {
    return 1;
  }
}

int test2(int x) {
  if(x<=0) throw 1;
  return 1;
}

static void error_code(benchmark::State& state) {
  int result = 0;
  while (state.KeepRunning()) {
    int x=0;

    if(test(1, x)) {

    } else {
      result += x;
    }

    if(test(0, x)) {
      result -= x;

    } else {

    }
  }
  (void)result;
}

static void throwing(benchmark::State& state) {
  int result = 0;
  while (state.KeepRunning()) {
    int x=0;
    try {
      result+= test2(1);
      result+= test2(0);
    } catch(int& e) {
      result-= 1;
    }
  }
  (void)result;
}





BENCHMARK(error_code)->Range(8, 8<<10);
BENCHMARK(throwing)->Range(8, 8<<10);
BENCHMARK_MAIN();
