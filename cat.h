#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal {
public:
    Cat();
    virtual ~Cat() {}

    // Override methods from Animal
    void setHunger(int level) override;
    void setSleepiness(int level) override;
    void setPlayfulness(int level);  // Add this line
    void sortActivities() override;
    void printSchedule() const override;

private:
    int playfulness;
};

#endif
