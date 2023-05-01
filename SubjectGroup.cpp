#include "SubjectGroup.h"
#include <iostream>
#include <stdio.h>
#include <random>

namespace corsim {

    // moves the subjects
    void SubjectGroup::move(double dt) {
        for(Subject& subject : this->_subjects){
            subject.move(dt);
        }
    }

    // sets the movement strategies of the subjects
    void SubjectGroup::setMovementStrategy(MovementStrategy *movementStrategy){
        for(Subject& subject : this->_subjects){
            subject.setMovementStrategy(movementStrategy);
        }
    }

    // generates a new time alive
    void SubjectGroup::generateTimeAlive() {
        static std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, 300);
        this->_timeAlive = dist(rng);
    }
}