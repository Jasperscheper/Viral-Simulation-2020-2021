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

#pragma once

namespace corsim
{

/**
 * The StatisticsHandler interface is a description of the way statistics from the
 * simulation can be communicated with code outside of the simulation.
 */
class StatisticsHandler
{
    public:
    virtual ~StatisticsHandler(){};
    virtual void communicate_number_infected(int time, int infected) = 0;
};

}