#include <iostream>
#include <memory>
#include <vector>
class Building;
typedef Building *(*BuildingFactory)();
int building_type_count = 0;
std::vector<std::pair<int, BuildingFactory>> building_registry;
void RegisterBuilding(BuildingFactory factory) {
  building_registry.push_back(std::make_pair(building_type_count++, factory));
}

class Building {
public:
  static std::unique_ptr<Building> MakeBuilding(int building_type) {
    BuildingFactory factory = building_registry[building_type].second;
    return std::unique_ptr<Building>(factory());
  }
};

class Farm : public Building {
public:
  static Building *MakeBuilding() {
    std::cout << "Make Farm" << std::endl;
    return new Farm;
  }
  static void Register() {
    std::cout << "Register Farm" << std::endl;
    RegisterBuilding(Farm::MakeBuilding);
  }
};
class Forge : public Building {
public:
  static Building *MakeBuilding() {
    std::cout << "Make Forge" << std::endl;
    return new Forge;
  }
  static void Register() {
    std::cout << "Register Forge" << std::endl;
    RegisterBuilding(Forge::MakeBuilding);
  }
};

int main() {
  Farm::Register();
  Forge::Register();
  std::unique_ptr<Building> new_building = Building::MakeBuilding(1);
  std::unique_ptr<Building> new_building2 = Building::MakeBuilding(0);
  std::unique_ptr<Building> new_building3 = Building::MakeBuilding(1);
  return 0;
}