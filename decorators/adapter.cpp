#include <iostream>
#include<memory>
#include <mutex>
#include <queue>
template<typename T> class locking_queue
{
    public:
    using mutex=std::mutex;
    using lock_guard=std::lock_guard<mutex>;
    using value_type=typename std::queue<T>::value_type;
    void push(const value_type& value)
    {
        lock_guard l(m_);
        q_.push(value);
    }
    void push(const value_type&& value)
    {
        lock_guard l(m_);
        q_.push(value);
    }
    private:
    std::mutex m_;
    std::queue<T> q_;
};

int main()
{
    locking_queue<int> q;
    q.push(5);
    if(!q.empty())
    {
        int i = q.front();
        q.pop();
    }
    return 0;
}