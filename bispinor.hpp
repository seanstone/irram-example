#ifndef __BISPINOR_HPP__
#define __BISPINOR_HPP__

#include <iRRAM/lib.h>
#include "spinor.hpp"

class bispinor
{
    spinor x[2];

public:

    bispinor() { x[0][0] = x[0][1] = x[1][0] = x[1][1] = iRRAM::COMPLEX(0); }
    bispinor(iRRAM::COMPLEX x00, iRRAM::COMPLEX x01, iRRAM::COMPLEX x10, iRRAM::COMPLEX x11) {
        x[0][0] = x00; x[0][1] = x01;
        x[1][0] = x10; x[1][1] = x11;
    }

    spinor& operator[](std::size_t idx)       { return x[idx]; }
    const spinor& operator[](std::size_t idx) const { return x[idx]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const bispinor& v)
{
    return os
    << "|" << v[0][0] << ", " << v[0][1] << "|" << "\n"
    << "|" << v[1][0] << ", " << v[1][1] << "|";
}

#endif