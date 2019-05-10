#ifndef __VEC4_HPP__
#define __VEC4_HPP__

#include <iRRAM/lib.h>

class vec4
{
    iRRAM::REAL x[4];

public:
    iRRAM::REAL& operator[](std::size_t idx)       { return x[idx]; }
    const iRRAM::REAL& operator[](std::size_t idx) const { return x[idx]; }

    iRRAM::REAL norm() { return x[0]*x[0] - x[1]*x[1] - x[2]*x[2] - x[3]*x[3]; }
};

iRRAM::orstream& operator<<(iRRAM::orstream& os, const vec4& v)
{
    return os << "[" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << "]";
}

#endif