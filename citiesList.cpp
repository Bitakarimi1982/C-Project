#include "citiesList.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include<ranges>

CitiesList::CitiesList(std::string_view fileName) {
    // Assuming the file contains city information in the format described in City.h
    std::ifstream file(fileName.data());
    std::copy(std::istream_iterator<City>(file), std::istream_iterator<City>(), std::back_inserter(cities));
    file.close();
}

void CitiesList::readStreet(std::string_view fileName) noexcept {
    // Assuming the file contains street information in the format described in Street.h
    std::ifstream file(fileName.data());
    std::copy(std::istream_iterator<Street>(file), std::istream_iterator<Street>(), std::back_inserter(streets));
    file.close();
}

std::optional<City> CitiesList::seekAndDestroy(const std::string& name) noexcept {
    auto it = std::ranges::find_if(cities, [&name](const City& city) { return city.getName() == name; });

    if (it != cities.end()) {
        City deletedCity = std::move(*it);
        cities.erase(it);
        return deletedCity;
    }
    else {
        // Return an empty optional if city is not found
        return std::nullopt;
    }
}

void CitiesList::updatePopulation(const City& deletedCity) noexcept {
    // Find neighboring cities based on streets
    auto getNeighboringCities = [&deletedCity, this](const Street& street) {
        if (street.getStartCityId() == deletedCity.getId()) {
            return street.getEndCityId();
        }
        else if (street.getEndCityId() == deletedCity.getId()) {
            return street.getStartCityId();
        }
        else {
            return -1; // No neighbor
        }
        };

    std::vector<int> neighboringCityIds;
    std::transform(streets.begin(), streets.end(), std::back_inserter(neighboringCityIds), getNeighboringCities);

    // Remove duplicates
    std::sort(neighboringCityIds.begin(), neighboringCityIds.end());
    neighboringCityIds.erase(std::unique(neighboringCityIds.begin(), neighboringCityIds.end()), neighboringCityIds.end());

    int totalPopulation = 0;
    for (const auto& id : neighboringCityIds) {
        auto it = std::find_if(cities.begin(), cities.end(), [id](const City& city) { return city.getId() == id; });
        if (it != cities.end()) {
            totalPopulation += it->getPopulation();
        }
    }

    // Distribute the evacuated population based on neighboring cities' populations
    for (const auto& id : neighboringCityIds) {
        auto it = std::find_if(cities.begin(), cities.end(), [id](const City& city) { return city.getId() == id; });
        //std::cout << "Name: " << it->getName() << ", number of residents: " << it->getPopulation() << ", cityID: " << it->getId() << std::endl;
        if (it != cities.end()) {
            double populationFraction = static_cast<double>(it->getPopulation()) / totalPopulation;
            std::cout << "Name: " << it->getName() << ", number of residents: " << it->getPopulation() << ", cityID: " << it->getId() << std::endl;
            int redistributedPopulation = static_cast<int>(populationFraction * deletedCity.getPopulation());

            // Update population of the neighboring city
            it->setPopulation(it->getPopulation() + redistributedPopulation);
            
            std::cout << "Sum: " << totalPopulation << ", Diff: " << redistributedPopulation << std::endl;
            std::cout << "Name: " << it->getName() << ", number of residents: " << it->getPopulation() << ", cityID: " << it->getId() << std::endl;
        }
        
    }

}


CitiesList::CitiesList(CitiesList&& other) noexcept
    : cities(std::move(other.cities)), streets(std::move(other.streets)) {
}

CitiesList& CitiesList::operator=(CitiesList&& other) noexcept {
    if (this != &other) {
        cities = std::move(other.cities);
        streets = std::move(other.streets);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CitiesList& citiesList) {
    for (const auto& city : citiesList.cities) {
        os << city << std::endl;
    }
    return os;
}
