/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This source file implements the methods of the Shark class defined in shark.h.
    It includes the constructor, as well as the overridden methods for eating, sleeping,
    swimming, printing the schedule, and performing scheduled activities specific
    to the shark.
-------------------------------------------------- */

#include "shark.h"
#include <iostream>
#include <iomanip> // For setw
#include <algorithm> // For sort

using namespace std;

// Constructor with default values for hunger, sleepiness, and coldness
Shark::Shark(int hunger, int sleepiness, int coldness)
    : Animal(hunger, sleepiness, coldness) {}

// Shark eats and decreases hunger level
void Shark::eat() {
    cout << "Shark eats and feels a little less hungry.\n";
    hungerLevel = max(hungerLevel - 2, 0);
}

// Shark sleeps and decreases sleepiness level
void Shark::sleep() {
    cout << "Shark sleeps and feels much more rested.\n";
    sleepinessLevel = max(sleepinessLevel - 5, 0);
}

// Shark swims and decreases coldness level
void Shark::swim() {
    cout << "Shark swims and feels moderately warmer.\n";
    coldnessLevel = max(coldnessLevel - 3, 0);
}

// Print the recommended schedule based on current levels
void Shark::printSchedule() const {
    vector<pair<int, string>> needs = {
        {getHunger(), "EAT"},
        {getSleepiness(), "SLEEP"},
        {getColdness(), "SWIM"}
    };

    // Sort the vector descending by need level and ascending alphabetically for tie-breaker
    sort(needs.begin(), needs.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
        });

    int index = 1;
    if (needs.empty()) {
        cout << "No activities scheduled.\n";
    }
    else {
        for (const auto& need : needs) {
            string priority;
            if (need.first == 0) {
                priority = "(Very Low Priority)";
            }
            else if (need.first >= 1 && need.first <= 3) {
                priority = "(Low Priority)";
            }
            else if (need.first >= 4 && need.first <= 6) {
                priority = "(Medium Priority)";
            }
            else {
                priority = "(High Priority)";
            }
            cout << index++ << ". " << left << setw(10) << need.second << " " << priority << '\n';
        }
    }
    cout << "==============================\n";
}

// Perform the scheduled activities in order
void Shark::performSchedule() {
    vector<Activity> sortedActivities = getSortedActivities();

    cout << "\n==============================\n";
    for (const auto& activity : sortedActivities) {
        if (activity.name == "Eat") {
            eat();
        }
        else if (activity.name == "Sleep") {
            sleep();
        }
        else if (activity.name == "Swim") {
            swim();
        }
    }
    cout << "==============================\n";
}
