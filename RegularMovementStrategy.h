#pragma once
#include "MovementStrategy.h"

namespace corsim {

    class RegularMovementStrategy : public MovementStrategy {
        public:
            double runStrategy(double pos, double speed, double dt) override;
    };
}