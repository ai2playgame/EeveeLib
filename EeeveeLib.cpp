#include <iostream>
#include <eevee/math/math.hpp>

int main()
{
    eevee::Modint<100> m1{ 10 };
    eevee::Modint<100> m2{ 90 };

    std::cout << m1 + m2 << std::endl;
    return 0;
}
