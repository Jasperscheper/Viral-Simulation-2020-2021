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

#include "canvas.h"
#include <string>

namespace corsim
{

/**
 * This HTMLCanvas class is the implementation of the canvas interface to suit the
 * canvas a HTML interface provides. It can draw directly to the web page's canvas.
 */
class HTMLCanvas : public Canvas
{
    public:
    HTMLCanvas(int x, int y, int width, int height);
    ~HTMLCanvas() override;
    void clear() override;
    void draw_pixel(double x, double y, CanvasColor color) override;
    void draw_rectangle(double x, double y, double width, double height, CanvasColor color) override;
    void draw_ellipse(double x, double y, double radius, CanvasColor color) override;

    private:
    std::string _canvas_id;
    int _width, _height;
};

}