/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 1: Assignment
    31 Aug. 2024
    This source file implements the methods of the Menu class defined in menu.h.
    It includes functionality for displaying the menu, handling user input,
    and updating the Shark object's hunger, sleepiness, and coldness levels.
-------------------------------------------------- */

#include "menu.h"
#include <iostream>
#include <limits> // For numeric_limits

using namespace std;

// Display the main menu to the user
void Menu::showMainMenu() const {
    cout << "\n==============================\n";
    cout << "  Shark Planner Menu\n";
    cout << "==============================\n";
    cout << "1. Set Shark's Hunger Level\n";
    cout << "2. Set Shark's Sleepiness Level\n";
    cout << "3. Set Shark's Coldness Level\n";
    cout << "4. Show Shark's Recommended Schedule\n";
    cout << "5. Perform Shark's Schedule\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
}

// Handle user input and interact with the shark object
void Menu::interactWithUser() const {
    unique_ptr<Shark> shark = make_unique<Shark>();

    int choice;

    // Perform actions based on user input until user exits the program
    do {
        showMainMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1:
            setNeed(*shark, "hunger"); // Passing Shark by reference
            break;
        case 2:
            setNeed(*shark, "sleepiness"); // Passing Shark by reference
            break;
        case 3:
            setNeed(*shark, "coldness"); // Passing Shark by reference
            break;
        case 4:
            cout << "\n==============================\n";
            cout << "  Shark's Recommended Schedule\n";
            cout << "==============================\n";
            shark->printSchedule();
            break;
        case 5:
            shark->performSchedule();
            shark->printSchedule();
            break;
        case 6:
            cout << "\n==============================\n";
            cout << "Thank you for using Shark Planner. \nExiting program.\n";
            cout << "==============================\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            break;
        }
    } while (choice != 6);
}

// Set shark levels based on user input
void Menu::setNeed(Shark& shark, const string& needName) const {
    int level;
    cout << "Enter " << needName << " level (0-10): ";

    // Input validation
    while (!(cin >> level) || level < 0 || level > 10) {
        cout << "Invalid input. Please enter a number between 0 and 10: ";
        cin.clear(); // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    if (needName == "hunger") {
        shark.setHunger(level);
    }
    else if (needName == "sleepiness") {
        shark.setSleepiness(level);
    }
    else if (needName == "coldness") {
        shark.setColdness(level);
    }

    // Update confirmation message
    cout << "Shark's " << needName << " level has been updated to " << level << ".\n";
}
