#pragma once

// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <vector>
#include <memory>
#include "subject.h"
#include "canvas.h"
#include "statistics_handler.h"

namespace corsim
{

/**
 * The simulation class controls the simulation. It has a list of all the subjects that being simulated and
 * can be run. Its constructor takes a canvas to draw the simulation on and a statistics handler to give an
 * update of the number of infected every second during the simulation.
 */
class Simulation
{
    public:
        Simulation(int width, int height, std::unique_ptr<Canvas> canvas, std::unique_ptr<StatisticsHandler> sh);
        void add_subject(Subject&& s);
        void assign_strategies();
        void run(); //This method starts the simulation but locks execution because theading is not supported in WASM
    private:
        void wall_collision(Subject& s);
        void subject_collision(Subject& s1, Subject& s2);
        void static_collision(Subject& s1, Subject& s2, bool emergency);
        void tick();
        void draw_to_canvas();

        std::unique_ptr<Canvas> _canvas;
        std::vector<Subject> _subjects;
        std::unique_ptr<StatisticsHandler> _sh;
        bool running = false;
        int tick_speed = 1000/30;
        int _sim_width = 800, _sim_height = 500;
};

}