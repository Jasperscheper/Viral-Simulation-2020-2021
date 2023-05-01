#pragma once

namespace corsim {

    class MovementStrategy {
        public:
            virtual double runStrategy(double pos, double speed, double dt) = 0;
    };
}