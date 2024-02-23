#include "street.h"
// Constructor implementation
Street::Street(std::stringstream&& data) {
    // Assuming the format of the stringstream is: "StreetName Length"
    data >> startCityId >> endCityId >> distance;
}

int Street::getStartCityId() const {
    return startCityId;
}

int Street::getEndCityId() const {
    return endCityId;
}

double Street::getDistance() const {
    return distance;
}

// Setter method implementations
void Street::setStartCityId(int newStartCityId) {
    startCityId = newStartCityId;
}

void Street::setEndCityId(int newEndCityId) {
    endCityId = newEndCityId;
}

void Street::setDistance(double newDistance) {
    distance = newDistance;
}

// Move constructor implementation
Street::Street(Street&& other) noexcept
    : startCityId(std::move(other.startCityId)),
    endCityId(std::move(other.endCityId)),
    distance(std::move(other.distance)) {
}

// Move assignment operator implementation
Street& Street::operator=(Street&& other) noexcept {
    if (this != &other) {
        startCityId = std::move(other.startCityId);
        endCityId = std::move(other.endCityId);
        distance = std::move(other.distance);
    }
    return *this;
}