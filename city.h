#pragma once
#include <iostream>
#include <sstream>
#include <vector>

//class CitiesList;
class City {
private:
    int cityID;
    std::string Name;
    int population;
    int areaId;
    int seaLevel;

public:
    // Constructor that accepts a std::stringstream&
    explicit City(std::stringstream&& data);
    City() : cityID(0), Name(""), population(0), areaId(0), seaLevel(0) {}
    // Getter methods
    int getId() const;
    std::string getName() const;
    int getPopulation() const;
    int getAreaId() const;
    int getSeaLevel() const;

    // Setter methods
    void setId(int newId);
    void setName(const std::string& newName);
    void setPopulation(int newPopulation);
    void setAreaId(int newAreaId);
    void setSeaLevel(int newSeaLevel);
    // Copy constructor
    City(const City& other) = default;

    // Copy assignment operator
    City& operator=(const City& other) = default;

    // Movable
    City(City&& other) noexcept;
    City& operator=(City&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const City& city);
    std::ostream& print(std::ostream& os) const noexcept;
    
    friend std::istream& operator>>(std::istream& is, City& city) {
        is >> city.cityID >> city.Name >> city.population >> city.areaId >> city.seaLevel;
        return is;
    }
};
    
std::ostream& operator<<(std::ostream& os, const City& city);


