#include <iostream>

class ScopeGuardImplBase
{
public:
    ScopeGuardImplBase() : commit_(false) {}
    void commit()   noexcept{ commit_ = true; }  // Remove const from this line

    ScopeGuardImplBase(ScopeGuardImplBase&& other)
        : commit_(other.commit_) { other.commit(); }
    ~ScopeGuardImplBase() {}
    bool commit_;  // Remove mutable specifier from this line
private:
    ScopeGuardImplBase& operator=(const ScopeGuardImplBase&)= delete;
};

template<typename Func>
class ScopeGuardImpl : public ScopeGuardImplBase
{
public:
    ScopeGuardImpl(Func&& func) : func_(func) {}
    ScopeGuardImpl(const Func&& func) : func_(func) {}
    ~ScopeGuardImpl() { if (!commit_) func_(); 
    std::cout<<commit_ <<" des"<<std::endl;}
    ScopeGuardImpl(ScopeGuardImpl&& other) : ScopeGuardImplBase(std::move(other)),func_(other.func_) {}
private:
    Func func_;
};

template<typename Func>
ScopeGuardImpl<Func> MakeGuard(Func&& func)
{
    return ScopeGuardImpl<Func>(std::forward<Func>(func));
}

class Record
{

};

class S
{
public:
    void insert()
    {
        std::cout << "S::insert" << std::endl;
       
    }
    void undo()
{
    std::cout << "UNdo" << std::endl;
}
    S() {}
    ~S()
    {
        std::cout << "S::Des" << std::endl;
    }
};

class I
{
public:
    void insert()
    {
        std::cout << "I::insert" << std::endl;
      
           try {
       
        throw std::runtime_error("This is a custom error message.");
    } catch (const std::exception& e) {
        std::cerr << "Caught an error I: " << e.what() << std::endl;
}

    }

    I() {}
    ~I()
    {
        std::cout << "I::Des" << std::endl;
    }
};



class Database
{
public:
    void insert(const Record&)
    {
         S s;
        I i;
        s.insert();
        auto  SG = MakeGuard([&] {s.undo();});
        i.insert();
       SG.commit(); 
 
       
       // std::terminate();
    }
};

int main()
{
    Database d;
    Record r;
    d.insert(r);

    return 0;
}