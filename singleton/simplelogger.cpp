#include <iostream>
#include <mutex>
class Logger
{
    public:
    static Logger& instance()
    {
        return instance_;
    }
    void LogError(const char* msg)
    {
        std::lock_guard<std::mutex> guard(lock_);
        std::cerr<<" ERROR: "<<msg<<std::endl;
        ++error_count_;
    }
    private:
    Logger(): error_count_(0) {std::cout<<"Start"<<std::endl;}
    ~Logger() {std::cout<<"End"<<std::endl;}
    Logger(const Logger&)=delete;
    Logger& operator=(const Logger&) = delete;

    static Logger instance_;
    std::mutex lock_;
    size_t error_count_;

};
Logger Logger::instance_;
int main()
{
    Logger::instance().LogError("Hwww");
    return 0;
}