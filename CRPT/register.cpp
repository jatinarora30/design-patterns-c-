#include <iostream>
template <typename D> class registery
{
    public:
    static size_t count;
    static D* head;
    D* prev;
    D* next;
    protected:
    registery()
    {
        ++count;
        prev=nullptr;
        next=head;
        head = static_cast<D*>(this);
        if(next) next->prev=head;
    }
    registery(const registery&)
    {
        ++count;
        prev=nullptr;
        next=head;
        head = static_cast<D*>(this);
        if(next) next->prev=head;
    }
    ~registery()
    {
        --count;
        if(prev) prev->next=next;
        if(next) next->prev=prev;
        if(head==this) head=next;
    }
};


    template<typename D> size_t registery<D>::count(0);
    template<typename D> D* registery<D>::head(nullptr);
