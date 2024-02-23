#pragma once
#include <sstream>
#include <string>

class Street {
private:
    int startCityId;
    int endCityId;
    double distance;

public:
    // Constructor that accepts std::stringstream&& as argument
    explicit Street(std::stringstream&& data);
    Street() : startCityId(0), endCityId(0), distance(0) {}
    // Getter methods
    int getStartCityId() const;
    int getEndCityId() const;
    double getDistance() const;

    // Setter methods
    void setStartCityId(int newStartCityId);
    void setEndCityId(int newEndCityId);
    void setDistance(double newDistance);

    // Copy constructor
    Street(const Street& other) = default;

    // Copy assignment operator
    Street& operator=(const Street& other) = default;

    // Movable
    Street(Street&& other) noexcept;
    Street& operator=(Street&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Street& street) {
        os << street.startCityId << "-" << street.endCityId << " " << street.distance;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Street& street) {
        is >> street.startCityId >> street.endCityId >> street.distance;
        return is;
    }

};