#pragma once

#include <vector>
#include "subject.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace corsim {
    class SubjectGroup {
        public: 
             SubjectGroup(std::vector<std::reference_wrapper<Subject>> subjects)
                : _subjects(subjects) {
                    this->generateTimeAlive();
            }
            ~SubjectGroup() {};

            int timeAlive() { return this->_timeAlive; }
            void setMovementStrategy(MovementStrategy *movementStrategy);
            void move(double dt);
            void generateTimeAlive();
            void increaseTimeAlive() {
                this->_timeAlive++;
            }
        private:
            int _timeAlive;
            std::vector<std::reference_wrapper<Subject>> _subjects;
    };
}