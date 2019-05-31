#include <iRRAM/lib.h>
#include "vec4.hpp"

using namespace iRRAM;

VEC4 lorentz_x(REAL eta, VEC4 p)
{
    VEC4 q = p;
    q[0] = cosh(eta) * p[0] + sinh(eta) * p[1];
    q[1] = sinh(eta) * p[0] + cosh(eta) * p[1];
    return q;
}

VEC4 rotate_x(REAL eta, VEC4 p)
{
    VEC4 q = p;
    q[2] = cos(eta) * p[2] + sin(eta) * p[3];
    q[3] = -sin(eta) * p[2] + cos(eta) * p[3];
    return q;
}
