#ifndef __SPINOR_HPP__
#define __SPINOR_HPP__

#include <iRRAM/lib.h>
#include "complex.hpp"
#include "vec4.hpp"

class spinor
{
    iRRAM::COMPLEX x[2];

public:

    spinor() { x[0] = x[1] = iRRAM::COMPLEX(0); }
    spinor(iRRAM::COMPLEX x0, iRRAM::COMPLEX x1) { x[0] = x0; x[1] = x1; }

    spinor(vec4 v)
    {
        iRRAM::REAL theta = acos(v[3]/v[0]);
        iRRAM::REAL phi = atan(v[2]/v[1]);
        x[0] = sqrt(2 * v[0]) * cos(theta/2),
        x[1] = sqrt(2 * v[0]) * sin(theta/2) * exp(iRRAM::COMPLEX(0,1) * phi);
    }

    iRRAM::COMPLEX& operator[](std::size_t idx)       { return x[idx]; }
    const iRRAM::COMPLEX& operator[](std::size_t idx) const { return x[idx]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const spinor& v)
{
    return os << "[" << v[0] << ", " << v[1] << "]";
}

static spinor conjugate(const spinor& s)
{
    return spinor(conjugate(s[0]), conjugate(s[1])); 
}

#endif