#include <iostream>
class City
{
    public:
    class DayEvents
    {
        public:
        DayEvents() : flood(false), fire(false) {}
        DayEvents& Setfire() { fire = true; return (*this);}
        DayEvents& Setfood() { flood = true; return (*this);}
        private:
        bool flood;
        bool fire;
    };
    
    void Day(DayEvents events);
};
int main()
{
    City capital;
    capital.Day(City::DayEvents().Setfire());
    return 0;
}