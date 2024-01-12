#include <iostream>
#include <cstring>
#include <cstdlib>
#include <benchmark/benchmark.h>

class simple_string
{
public:
    simple_string() : s_(nullptr) {}
    explicit simple_string(const char* s) : s_(strdup(s)) {}
    simple_string(const simple_string& s) : s_(strdup(s.s_)) {}
    simple_string& operator=(const char* s)
    {
        free(s_);
        s_ = strdup(s);
        return *this;
    }
    simple_string& operator=(const simple_string& s)
    {
        free(s_);
        s_ = strdup(s.s_);
        return *this;
    }
    bool operator==(const simple_string& rhs) const
    {
        return strcmp(s_, rhs.s_) == 0;
    }
    ~simple_string() { free(s_); }

private:
    char* s_;
};

class small_string
{
public:
    small_string() : s_(), buf_() {}
    explicit small_string(const char* s) : s_()
    {
        if (strlen(s) + 1 < sizeof(buf_))
        {
            strcpy(buf_, s);
            s_ = buf_;
        }
        else
        {
            s_ = strdup(s);
        }
    }
    small_string(const small_string& s) : s_()
    {
        if (strlen(s.s_) + 1 < sizeof(buf_))
        {
            strcpy(buf_, s.s_);
            s_ = buf_;
        }
        else
        {
            s_ = strdup(s.s_);
        }
    }
    small_string& operator=(const char* s)
    {
        if (s_ != buf_)
            free(s_);
        if (strlen(s) + 1 < sizeof(buf_))
        {
            strcpy(buf_, s);
            s_ = buf_;
        }
        else
        {
            s_ = strdup(s);
        }
        return *this;
    }
    small_string& operator=(const small_string& s)
    {
        if (s_ != buf_)
            free(s_);
        if (strlen(s.s_) + 1 < sizeof(buf_))
        {
            strcpy(buf_, s.s_);
            s_ = buf_;
        }
        else
        {
            s_ = strdup(s.s_);
        }
        return *this;
    }
    bool operator==(const small_string& rhs) const
    {
        return strcmp(s_, rhs.s_) == 0;
    }
    ~small_string()
    {
        if (s_ != buf_)
            free(s_);
    }

private:
    char* s_;
    char buf_[16];
};
template<typename T>
void BM_string_create_short(benchmark::State & state)
{
    const char* s = "Simple string";
    for(auto _ : state)
    {
        for(int i=0;i<32;i++)
        {
        T S(s);
        benchmark::DoNotOptimize(S);
        }
    }
    state.SetItemsProcessed(32*state.iterations());
}
BENCHMARK_TEMPLATE1(BM_string_create_short,simple_string);
BENCHMARK_TEMPLATE1(BM_string_create_short,small_string);
int main(int argc, char **argv) {


  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();

  return 0; 
}
\


