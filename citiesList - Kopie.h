#pragma once
#include "City.h"
#include "Street.h"
#include <list>
#include <vector>
#include <optional>
#include <string_view>


class CitiesList {
private:
    std::list<City> cities;
    std::vector<Street> streets;
   
   

public:
    explicit CitiesList(std::string_view fileName);
    void readStreet(std::string_view fileName) noexcept;  // Method to read street information from a file
    std::optional<City> seekAndDestroy(const std::string& name) noexcept;  // Method to find and delete a city  
    void updatePopulation(const City& city) noexcept;  // Method to update population
    CitiesList(CitiesList&& other) noexcept;  // Move constructor
    CitiesList& operator=(CitiesList&& other) noexcept;  // Move assignment operator
    friend std::ostream& operator<<(std::ostream& os, const CitiesList& citiesList);
};

