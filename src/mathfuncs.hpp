#ifndef MATHFUNCS_H
#define MATHFUNCS_H

#include <cmath>
#include <limits>
#include <memory>

#include "ray.hpp"
#include "vec3.hpp"

using namespace std;

// Constants

const double infinity = numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif