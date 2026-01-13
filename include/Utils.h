#ifndef UTILS_H
#define UTILS_H

#include "Vec3.h"
#include <cstdlib>
#include <cmath>

// Utility functions for random number generation
inline double random_double() {
    return (double)rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

inline Vec3 random_in_unit_sphere() {
    while (true) {
        Vec3 p = Vec3(
            random_double(-1, 1),
            random_double(-1, 1),
            random_double(-1, 1)
        );
        if (p.length_squared() < 1.0) {
            return p;
        }
    }
}

inline Vec3 random_unit_vector() {
    return random_in_unit_sphere().normalized();
}

inline Vec3 random_in_unit_disk() {
    while (true) {
        Vec3 p = Vec3(
            random_double(-1, 1),
            random_double(-1, 1),
            0
        );
        if (p.length_squared() < 1.0) {
            return p;
        }
    }
}

#endif
