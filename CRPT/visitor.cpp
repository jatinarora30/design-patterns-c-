#include <iostream>
#include <vector>
struct Animal
{
    public:
    enum Type {CAT, DOG, RAT};
    Animal(Type t,const char* n) : type(t),name(n) {}
    const Type type;
    const char* const name;
};

template<typename D>class GeneralVisitor
{
    public:
    template<typename it>void visit(it from,it to)
    {
        for(it i=from; i!=to;i++)
        {
            this->visit(*i);
        }
    }
    private:
    D& derived() {return *static_cast<D*>(this);}
    void visit(const Animal& animal)
    {
        switch (animal.type)
        {
            case Animal::CAT:
            derived().visit_cat(animal);
            break;
            case Animal::DOG:
            derived().visit_dog(animal);
            break;
            case Animal::RAT:
            derived().visit_rat(animal);
            break;
        default:
            break;
        }
    }
    void visit_cat(const Animal& animal)
    {
        std::cout<<"Feed the cat "<<animal.name<<std::endl;
    }
    void visit_dog(const Animal& animal)
    {
        std::cout<<"Wash the dog "<<animal.name<<std::endl;
    }
    void visit_rat(const Animal& animal)
    {
        std::cout<<"Ewww "<<animal.name<<std::endl;
    }
    friend D;
    GeneralVisitor() {}
};

class DefaultVisitor: public GeneralVisitor<DefaultVisitor>
{};

int main()
{
    std::vector<Animal> animals {{Animal::CAT,"Fluffy"},{Animal::DOG,"Fido"},{Animal::RAT,"Hww"}};
    DefaultVisitor().visit(animals.begin(),animals.end());
    return 0;
}