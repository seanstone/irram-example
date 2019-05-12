#ifndef __SPINOR_HPP__
#define __SPINOR_HPP__

#include <iRRAM/lib.h>
#include "complex.hpp"
#include "vec4.hpp"

class SPINOR
{
    iRRAM::COMPLEX x[2];

public:

    SPINOR() { x[0] = x[1] = iRRAM::COMPLEX(0); }
    SPINOR(iRRAM::COMPLEX x0, iRRAM::COMPLEX x1) { x[0] = x0; x[1] = x1; }

    SPINOR(VEC4 v)
    {
        // Probably problem with acos and atan
        iRRAM::REAL theta = acos(v[3]/v[0]);
        iRRAM::REAL phi = atan(v[2]/v[1]);
        x[0] = sqrt(2 * v[0]) * cos(theta/2),
        x[1] = sqrt(2 * v[0]) * sin(theta/2) * exp(iRRAM::COMPLEX(0,1) * phi);
    }

    iRRAM::COMPLEX& operator[](std::size_t idx)       { return x[idx]; }
    const iRRAM::COMPLEX& operator[](std::size_t idx) const { return x[idx]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const SPINOR& v)
{
    return os << "[" << v[0] << ", " << v[1] << "]";
}

static SPINOR conjugate(const SPINOR& s)
{
    return SPINOR(conjugate(s[0]), conjugate(s[1])); 
}

#endif