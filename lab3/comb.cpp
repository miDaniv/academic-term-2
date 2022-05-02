#include "comb.h"

#include <cmath>
int comb::factorial(int arg)
{
    if (arg == 0) return 1;

    return arg * factorial(arg - 1);
}

int comb::A(int n, int k)
{
    return factorial(n) / factorial(n - k);
}

int comb::_A(int n, int k)
{
    return std::pow(n, k);
}

int comb::C(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int comb::_C(int n, int k)
{
    return factorial(n + k - 1) / (factorial(k) * factorial(n - 1));
}
