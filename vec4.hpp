#ifndef __VEC4_HPP__
#define __VEC4_HPP__

#include <iRRAM/lib.h>

class VEC4
{
    iRRAM::REAL x[4];

public:

    VEC4() { x[0] = x[1] = x[2] = x[3] = 0; }
    VEC4(iRRAM::REAL x0, iRRAM::REAL x1, iRRAM::REAL x2, iRRAM::REAL x3) {
        x[0] = x0; x[1] = x1; x[2] = x2; x[3] = x3;
    }

    iRRAM::REAL& operator[](std::size_t idx)       { return x[idx]; }
    const iRRAM::REAL& operator[](std::size_t idx) const { return x[idx]; }

    iRRAM::REAL norm() { return x[0]*x[0] - x[1]*x[1] - x[2]*x[2] - x[3]*x[3]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const VEC4& v)
{
    return os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
}

#endif