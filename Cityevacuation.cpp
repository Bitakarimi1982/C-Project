
#include "city.h"
#include"citiesList.h"
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    CitiesList cities("stadt.txt");
    std::cout << "City List:\n" << cities << "\n";
    std::cout << "***********************************************************" << "\n";
    cities.readStreet("strasse.txt");

    if (auto deletedCity = cities.seekAndDestroy("Salzburg"); deletedCity) {

        cities.updatePopulation(*deletedCity);
    }
    else {
        std::cout << "City not found.\n";
    }
    std::cout << "***********************************************************" << "\n";
    std::cout << "\nCities after update:\n" << cities << "\n";

    return 0;
}