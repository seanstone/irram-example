#include <iRRAM/lib.h>
#include <stdlib.h>
#include "vec4.hpp"
#include "bispinor.hpp"
#include "massless.hpp"
#include "lorentz.hpp"
#include "random.hpp"

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

void compute()
{
    MASSLESS a1(rand_massless()), a2(rand_massless()), a3(rand_massless());
    MASSLESS b1(lorentz_x(1,a1.p)), b2(lorentz_x(1,a2.p)), b3(lorentz_x(1,a3.p));

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

    cout << ab(a1,a2) * sb(a1,a2) - ab(b1,b2) * sb(b1,b2) << "\n";

    // cout << ab(a1,b1) << "\n";
    // cout << sb(a1,b1) << "\n";

    // COMPLEX ma = ab(a1,a2) * ab(a1,a2) * ab(a1,a2) / ab(a2,a3) / ab(a3,a1);
    // COMPLEX mb = ab(b1,b2) * ab(b1,b2) * ab(b1,b2) / ab(b2,b3) / ab(b3,b1);

    // cout << ma << "\n";
    // cout << mb << "\n";

    // cout << ma._real*ma._real + ma._imag*ma._imag << "\n";
    // cout << mb._real*mb._real + mb._imag*mb._imag << "\n";
}
