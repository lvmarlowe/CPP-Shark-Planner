/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This source file implements the methods for the Animal class.
    It includes constructors, setters, getters, and a method to sort
    activities based on their priority.
-------------------------------------------------- */

#include "animal.h"
#include <algorithm> // For sort

using namespace std;

// Constructor with default values for hunger, sleepiness, and coldness
Animal::Animal(int hunger, int sleepiness, int coldness)
    : hungerLevel(hunger), sleepinessLevel(sleepiness), coldnessLevel(coldness) {}

// Getters
int Animal::getHunger() const {
    return hungerLevel;
}

int Animal::getSleepiness() const {
    return sleepinessLevel;
}

int Animal::getColdness() const {
    return coldnessLevel;
}

// Setters
void Animal::setHunger(int hunger) {
    hungerLevel = hunger;
}

void Animal::setSleepiness(int sleepiness) {
    sleepinessLevel = sleepiness;
}

void Animal::setColdness(int coldness) {
    coldnessLevel = coldness;
}

// Method to sort activities by priority
vector<Animal::Activity> Animal::getSortedActivities() const {
    vector<Activity> activities = {
        {"Eat", hungerLevel},
        {"Sleep", sleepinessLevel},
        {"Swim", coldnessLevel}
    };

    // Sort activities based on priority (highest first)
    sort(activities.begin(), activities.end(), [](const Activity& a, const Activity& b) {
        return a.priority > b.priority;
        });

    return activities;
}
