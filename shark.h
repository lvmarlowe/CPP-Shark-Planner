/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This header file defines the Shark class, which inherits from the Animal class.
    It provides implementations for the pure virtual methods declared in Animal,
    specific to the behavior of a shark, including methods for eating, sleeping,
    swimming, printing the schedule, and performing scheduled activities.
-------------------------------------------------- */

#ifndef SHARK_H
#define SHARK_H

#include "animal.h"

using namespace std;

class Shark : public Animal {
public:
    // Constructor with default values for hunger, sleepiness, and coldness
    Shark(int hunger = 0, int sleepiness = 0, int coldness = 0);

    // Virtual destructor
    virtual ~Shark() = default;

    // Override base class methods
    void eat() override;
    void sleep() override;
    void swim() override;
    void printSchedule() const override;
    void performSchedule() override;

private:
    // Prevent copying of Shark object for resource management
    Shark(const Shark&) = delete;
    Shark& operator=(const Shark&) = delete;
};

#endif // SHARK_H
