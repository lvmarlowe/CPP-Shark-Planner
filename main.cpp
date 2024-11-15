/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This source file contains the implementation of the main function
    for the Shark Planner application. It initializes the Menu object and
    starts the user interaction loop.
-------------------------------------------------- */

#include "main.h"
#include <iostream>

using namespace std;

// Entry point of the application
int main() {
    // Create a Menu object
    Menu menu;

    // Start interacting with the user
    menu.interactWithUser();

    return 0;
}
