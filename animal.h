/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This header file defines the Animal class, which is an abstract base class
    for all animals. It declares pure virtual methods that must be overridden
    by derived classes, along with member variables and methods for managing
    hunger, sleepiness, and coldness levels.
-------------------------------------------------- */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>
#include <string>

using namespace std;

class Animal {
public:
    // Default constructor
    Animal();

    // Overloaded constructor with default values for hunger, sleepiness, and coldness
    Animal(int hunger = 0, int sleepiness = 0, int coldness = 0);

    // Virtual destructor
    virtual ~Animal() = default;

    // Pure virtual methods to be implemented by derived classes
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void swim() = 0;
    virtual void printSchedule() const = 0;
    virtual void performSchedule() = 0;

    // Setters
    void setHunger(int hunger);
    void setSleepiness(int sleepiness);
    void setColdness(int coldness);

protected:
    // Member variables to store current levels
    int hungerLevel;
    int sleepinessLevel;
    int coldnessLevel;

    // Getters
    int getHunger() const;
    int getSleepiness() const;
    int getColdness() const;

    // Structure to hold activity name and priority
    struct Activity {
        string name;
        int priority;
    };

    // Helper method to get activities sorted by priority
    vector<Activity> getSortedActivities() const;

private:
    // Prevent copying of Animal object for resource management
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;
};

#endif // ANIMAL_H
