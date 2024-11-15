#include "cat.h"
#include <iostream>
#include <algorithm>

Cat::Cat() : playfulness(0) {
    // Constructor code
}

void Cat::setHunger(int level) {
    hunger = level;
}

void Cat::setSleepiness(int level) {
    sleepiness = level;
}

void Cat::setPlayfulness(int level) {
    playfulness = level;  // Set the playfulness level
}

void Cat::sortActivities() {
    // Sorting logic, if any
    std::sort(activities.begin(), activities.end());
}

void Cat::printSchedule() const {
    std::cout << "Cat's Daily Schedule:\n";
    std::cout << "1. Eat\n";
    std::cout << "2. Sleep\n";
    std::cout << "3. Play\n";
}
