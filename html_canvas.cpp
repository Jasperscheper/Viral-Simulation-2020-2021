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

#include <emscripten.h>
#include <random>
#include <iostream>
#include "html_canvas.h"

namespace corsim
{

std::string generate_unique_name()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    std::string id = "";
    for (int i=0; i<16; ++i)
    {
        int cast = dist(mt);
        id.append(std::to_string(cast));
    }
    return id;
}

std::string canvas_color_to_string(CanvasColor c)
{
    switch (c)
    {
    case RED:
        return "red";
    case GREEN:
        return "green";
    case BLUE:
        return "blue";
    case BLACK:
        return "black";
    
    default:
        return "ERROR";
    }
}

HTMLCanvas::HTMLCanvas(int x, int y, int width, int height)
{
    this->_canvas_id = generate_unique_name();
    this->_width = width;
    this->_height = height;

    EM_ASM({
        var canvas = document.createElement('canvas');
        canvas.id = Module.AsciiToString($0);
        canvas.style.position = 'absolute';
        canvas.style.left = $1 + "px";
        canvas.style.top = $2 + "px";
        canvas.style.width = $3 + "px";
        canvas.style.height = $4 + "px";
        canvas.width = $3;
        canvas.height = $4;
        document.body.append(canvas);
        var context = canvas.getContext('2d');
        window[canvas.id] = context;
    }, this->_canvas_id.c_str(), x, y, width, height);
}

HTMLCanvas::~HTMLCanvas(){std::cout << "HTML Canvas destroyed" << std::endl; }

void HTMLCanvas::clear()
{
    EM_ASM({
        var context = window[Module.AsciiToString($0)];
        context.clearRect(0,0,$1,$2);
    }, _canvas_id.c_str(), _width, _height);
}

void HTMLCanvas::draw_pixel(double x, double y, CanvasColor color)
{
    this->draw_rectangle(x, y, 1, 1, color);
}

void HTMLCanvas::draw_rectangle(double x, double y, double width, double height, CanvasColor color)
{
    EM_ASM({
       var context = window[Module.AsciiToString($0)];
       context.fillStyle = Module.AsciiToString($1);
       context.fillRect($2, $3, $4, $5);
    }, _canvas_id.c_str(),canvas_color_to_string(color).c_str(),x, y, width, height);
}

void HTMLCanvas::draw_ellipse(double x, double y, double radius, CanvasColor color)
{
    EM_ASM({
       var context = window[Module.AsciiToString($0)];
       context.fillStyle = Module.AsciiToString($1);
       context.beginPath();
       context.arc($2, $3, $4, 0, Math.PI * 2, true);
       context.fill();
    }, _canvas_id.c_str(),canvas_color_to_string(color).c_str(),x, y, radius);
}

}