#include <iRRAM/lib.h>
#include <stdlib.h>
#include "vec4.hpp"
#include "bispinor.hpp"
#include "massless.hpp"

using namespace iRRAM;

void compute();

int main(int argc, char **argv)
{
    srand(time(NULL));

    iRRAM_initialize2(&argc, argv);

    int deci_places = 8;
    cout << setRwidth(deci_places + 8);

    iRRAM::exec(compute);
    iRRAM_finalize();

    return 0;
}

REAL rand1() { return 2 * (float)rand()/(float)(RAND_MAX) - 1; }
COMPLEX rand1z() { return COMPLEX(rand1(),rand1()); }

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

VEC4 rand_massless()
{
    VEC4 p(0, rand1(), rand1(), rand1());
    p[0] = sqrt(p[1]*p[1] + p[2]*p[2] + p[3]*p[3]);
    return p;
}

void compute()
{
    MASSLESS a1(rand_massless()), a2(rand_massless()), a3(rand_massless());
    MASSLESS b1(rotate_x(1,a1.p)), b2(rotate_x(1,a2.p)), b3(rotate_x(1,a3.p));

    // cout << a1.a << "\n";
    // cout << a1.s << "\n";
    cout << a1.p << "\n";
    cout << b1.p << "\n";
    cout << BISPINOR(a1.a, a1.s) << "\n";
    cout << BISPINOR(b1.a, b1.s) << "\n";

    cout << ab(a1,a2) << " " << sb(a1,a2) << "\n";
    cout << ab(b1,b2) << " " << sb(b1,b2) << "\n";

    cout << ab(a1,a2) * sb(a1,a2) << "\n";
    cout << ab(b1,b2) * sb(b1,b2) << "\n";
    // cout << ab(a1,b1) << "\n";
    // cout << sb(a1,b1) << "\n";

    // COMPLEX ma = ab(a1,a2) * ab(a1,a2) * ab(a1,a2) / ab(a2,a3) / ab(a3,a1);
    // COMPLEX mb = ab(b1,b2) * ab(b1,b2) * ab(b1,b2) / ab(b2,b3) / ab(b3,b1);

    // cout << ma << "\n";
    // cout << mb << "\n";

    // cout << ma._real*ma._real + ma._imag*ma._imag << "\n";
    // cout << mb._real*mb._real + mb._imag*mb._imag << "\n";
}
