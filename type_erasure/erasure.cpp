#include <iostream>
#include <memory>

class Heap {
public:
  void *allocate(size_t size) {
    return ::operator new(
        size); // Use the global operator new to allocate memory.
  }

  void deallocate(void *p) {
    ::operator delete(
        p); // Use the global operator delete to deallocate memory.
  }
};

void *operator new(size_t size, Heap *h) { return h->allocate(size); }

class Deleter {
  Heap* heap_;

public:
Deleter(Heap* heap) :heap_(heap) {}

  template <typename T> void operator()(T *p) {
    p->~T();
    heap_->deallocate(p);
    std::cout<<"Delete"<<std::endl;
  }
};

int main() {
  Heap h;
  Deleter fd(&h);
  std::unique_ptr<int,Deleter> p(new (&h) int(0), fd);
  return 0;
}
