#include "RegularMovementStrategy.h"

namespace corsim {

    double RegularMovementStrategy::runStrategy(double pos, double speed, double dt) {
        return pos + speed * dt;
    }
}