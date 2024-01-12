#include <iostream>

class ScopeGuardImplBase
{
public:
    ScopeGuardImplBase() : commit_(false) {}
    void commit() const { commit_ = true; }  // Remove const from this line

    ScopeGuardImplBase(const ScopeGuardImplBase& other)
        : commit_(other.commit_) { other.commit(); }
    ~ScopeGuardImplBase() {}
    mutable bool commit_;  // Remove mutable specifier from this line
private:
    ScopeGuardImplBase& operator=(const ScopeGuardImplBase&){ return *this; }
};

template<typename Func, typename Arg>
class ScopeGuardImpl : public ScopeGuardImplBase
{
public:
    ScopeGuardImpl(const Func& func, Arg& arg) : func_(func), arg_(arg) {}
    ~ScopeGuardImpl() { if (!commit_) func_(arg_); 
    std::cout<<commit_ <<" des"<<std::endl;}
private:
    const Func& func_;
    Arg& arg_;
};

template<typename Func, typename Arg>
ScopeGuardImpl<Func, Arg> MakeGuard(const Func& func, Arg& arg)
{
    return ScopeGuardImpl<Func, Arg>(func, arg);
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
          try {
        // Your code here
        throw std::runtime_error("This is a custom error message.");
    } catch (const std::exception& e) {
        std::cerr << "Caught an error S: " << e.what() << std::endl;
}
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
        int i = 0;
        try {
        // Your code here
        throw std::runtime_error("This is a custom error message.");
    } catch (const std::exception& e) {
        std::cerr << "Caught an error: I" << e.what() << std::endl;
}
        
    }

    I() {}
    ~I()
    {
        std::cout << "I::Des" << std::endl;
    }
};

void undo(S&)
{
    std::cout << "UNdo" << std::endl;
}

class Database
{
public:
    void insert(const Record&)
    {
         S s;
        I i;
        s.insert();
        const ScopeGuardImplBase SG = MakeGuard(undo, s);
        i.insert();
        SG.commit();  // Don't forget to release the memory
    }
};

int main()
{
    Database d;
    Record r;
    d.insert(r);
    return 0;
}
