#ifndef __LORENTZ_HPP__
#define __LORENTZ_HPP__

#include <iRRAM/lib.h>
#include "vec4.hpp"

VEC4 lorentz_x(iRRAM::REAL eta, VEC4 p);
VEC4 rotate_x(iRRAM::REAL eta, VEC4 p);

#endif