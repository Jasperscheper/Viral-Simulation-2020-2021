#include "MovementStrategy.h"

namespace corsim {

    class LockdownMovementStrategy : public MovementStrategy {
        public:
            double runStrategy(double pos, double speed, double dt) override;
    };
}