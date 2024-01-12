#include <iostream>
#include <benchmark/benchmark.h>
class B
{
    public:
    virtual void f(int i)=0;
    int get() const {return i_;}
    protected:
    int i_=0;
};
class D: public B
{
    public:
    void f(int i) {i_+=i;}
};

template<typename D> class E
{
    public:
    E() : i_(0) {}
    void f(int i) {static_cast<D*>(this)->f(i);}
    int get() const {return i_;}
    protected:
    int i_;
};

class F :public E<F>
{
public:
    void f(int i) {i_+=i;}
};
class A
{
    public:
    A() : i_(0) {}
    void f(int i) { i_+=i;}
    int get() const {return i_;}
    
    int i_=0;
};

void BM_None(benchmark::State &state) {
A* a =new A;
int i=0;
  for (auto _ : state) {
    for(int i=0;i<100;i++)
  a->f(++i);
  }
  state.SetItemsProcessed(32*state.iterations());
  benchmark::DoNotOptimize(a->get());
  delete a;
  
}

void BM_Dynamic(benchmark::State &state) {
B* b =new D;
int i=0;
  for (auto _ : state) {
for(int i=0;i<100;i++)
  b->f(++i);
  }
  state.SetItemsProcessed(32*state.iterations());
  benchmark::DoNotOptimize(b->get());
  delete b;
  
}

void BM_Static(benchmark::State &state) {
E<F>* b =new F;
int i=0;
  for (auto _ : state) {
for(int i=0;i<100;i++)
  b->f(++i);
  }
  state.SetItemsProcessed(32*state.iterations());
  benchmark::DoNotOptimize(b->get());
  delete b;
  
}
BENCHMARK(BM_None);
BENCHMARK(BM_Dynamic);
BENCHMARK(BM_Static);
int main(int argc, char **argv)
{
    benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();

    return 0;
}