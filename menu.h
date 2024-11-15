/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This header file defines the Menu class for the Shark Planner application.
    It includes methods for displaying the main menu, handling user input,
    and setting shark levels based on user input.
-------------------------------------------------- */

#ifndef MENU_H
#define MENU_H

#include "shark.h"
#include <memory> // For smart pointers

using namespace std;

class Menu {
public:
    // Displays the main menu to the user
    void showMainMenu() const;

    // Handles user input and interacts with the Shark object
    void interactWithUser() const;

private:
    // Sets the shark's level for a specified need
    void setNeed(Shark& shark, const string& needName) const; // Function takes Shark by reference
};

#endif // MENU_H
