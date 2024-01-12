#include <iostream>
class Unit
{
    public:
    Unit(double strength,double armor) : strength_(strength),armor_(armor) {}
    virtual bool hit(Unit& target) {return attack()> target.defence();}
    virtual double attack()=0;
    virtual double defence()=0;
    protected:
    double strength_;
    double armor_;
};

class Knight: public Unit
{
    public:
    using Unit::Unit;
    double attack() {return strength_+ sword_bonus_;}
    double defence() {return armor_+plate_bonus_;}
    protected:
    static constexpr double sword_bonus_=2;
    static constexpr double plate_bonus_=3;
};


class Ogre: public Unit
{
    public:
    using Unit::Unit;
    double attack() {return strength_+ club_penalty_;}
    double defence() {return armor_+leather_penalty_;}
    protected:
    static constexpr double club_penalty_=-1;
    static constexpr double leather_penalty_=-1;
};

class VeteranUnit: public Unit
{
    public:
    VeteranUnit(Unit& unit,double strength_bonus,double armor_bonus): unit_(unit), Unit(strength_bonus,armor_bonus) {}
    double attack() {return unit_.attack()+ strength_;}
    double defence() { return unit_.defence()+ armor_;}

    private:
    Unit& unit_;
};

int main()
{
    Knight k(10,5);
    Ogre o(8,2);
    std::cout<<k.hit(o)<<std::endl;
    VeteranUnit vo(o,1,9);
    VeteranUnit vk(k,7,2);
    std::cout<<vk.hit(vo)<<std::endl;
    VeteranUnit vvo(vo,1,9);
    std::cout<<vk.hit(vvo)<<std::endl;
    return 0;
}