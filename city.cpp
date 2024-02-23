#include "city.h"
City::City(std::stringstream&& data) {
    // Assuming the format of the stringstream is: "CityID CityName Population AreaID SeaLevel"
    data >> cityID >> Name >> population >> areaId >> seaLevel;
}

// Getter method implementations
int City::getId() const {return cityID;}
std::string City::getName() const {return Name;}
int City::getPopulation() const {return population;}
int City::getAreaId() const {return areaId;}
int City::getSeaLevel() const {return seaLevel;}

// Setter method implementations
void City::setId(int newId) { cityID = newId;}
void City::setName(const std::string& newName) {Name = newName;}
void City::setPopulation(int newPopulation) {population = newPopulation;}
void City::setAreaId(int newAreaId) {areaId = newAreaId;}
void City::setSeaLevel(int newSeaLevel) {seaLevel = newSeaLevel;}
 
// Move constructor implementation
City::City(City&& other) noexcept: 
    cityID(std::move(other.cityID)),
    Name(std::move(other.Name)),
    population(std::move(other.population)),
    areaId(std::move(other.areaId)),
    seaLevel(std::move(other.seaLevel)) {
}

// Move assignment operator implementation
City& City::operator=(City&& other) noexcept {
    if (this != &other) {
        cityID = std::move(other.cityID);
        Name = std::move(other.Name);
        population = std::move(other.population);
        areaId = std::move(other.areaId);
        seaLevel = std::move(other.seaLevel);
    }
    return *this;
}


std::ostream& City::print(std::ostream& os) const noexcept {
    os << "Name: " << Name << ", number of residents : " << population << ", CityID : " << cityID;
    return os;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
    return city.print(os);
}





