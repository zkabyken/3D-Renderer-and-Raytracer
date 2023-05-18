#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

// In simple terms, a ray object is a vector with a specific direction towards which 
// the ray "particle will flow to"

class ray {
    public:
        point3 orig;
        vec3 dir;

        ray() {}
        ray(const point3& origin, const vec3& direction) 
            : orig(origin), dir(direction)
        {}

        point3 origin() const { return orig; }
        vec3 direction() const { return dir; }

        point3 at(double t) const {
            return orig + t * dir;
        }
};

#endif