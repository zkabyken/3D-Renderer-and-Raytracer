#ifndef VEC3_H
#define VEC3_H

// including a guard block to prevent multiple inclusions

#include <cmath>
#include <iostream>

using namespace std;

class vec3 {
    public:

        // defining an array e that will store the values of points

        double e[3];

        // two constructors for the vec3 class:
        // * default one with 0, 0, 0 for x, y and z
        // * prepolutating with given variables 

        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        // member functions for returning values of each x, y and z point
        // using const as we cannot modify the values

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // negation of all coordinate values

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        // access of coordinate values at certain indexes 
        // using const and non-const for access of values with and without modifications

        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // addition of different vectors to current vector

        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // multiplication of different vectors to current vector

        vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // division of the current vector by different vectors

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        // length of the current vector

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        inline static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }   

        inline static vec3 random(double min, double max) {
            return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
        }

        bool near_zero() const {
            // Return true if the vector is close to zero in all dimensions
            const auto s = 1e-8;
            return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
        }
};

// vec3 Utility Functions (using inline for optimization purposes)

// printing the coordinate values to the output stream

inline ostream& operator<<(ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// addition of vectors

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// substraction of vectors

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// multiplication of vectors

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// scaling a vector by a factor of t

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

// normalization of the vector

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

// dot product of two vectors

inline double dot (const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];   
}

// cross products of two vectors

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Making a unit vector

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

// inline double random_double() {
//     // Returns a random real in [0, 1).
//     return rand() / (RAND_MAX + 1.0);
// }

// inline double random_double(double min, double max) {
//     // Returns a random real in [min, max).
//     return min + (max - min) * random_double();
// }

vec3 random_in_unit_sphere() {
    while (true) {
        vec3 p = vec3::random(-1, 1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

vec3 random_in_unit_desk() {
    while (true) {
        vec3 p = vec3(random_double(-1, 1), random_double(-1, 1), 0);
        if (p.length_squared() >= 1) {
            continue;
        }
        return p;
    }
}

vec3 random_in_hemisphere(const vec3& normal) {
    vec3 in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as normal
        return in_unit_sphere;
    else 
        return -in_unit_sphere;
}

vec3 reflect(const vec3& v, const vec3& n) {
        return v - 2 * dot(v, n) * n;
}

vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
    double cos_theta = fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}


// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif