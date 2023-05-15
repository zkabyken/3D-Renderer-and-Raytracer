#ifndef COLOR_H
#define COLOR_H

#include "vec3.hpp"

#include <iostream>

using namespace std;

void write_color(ostream &out, color pixel_color) {
    // Write the translated [0, 255] values of each color component
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif