#include <iostream>
#include "BigNum.h"

int main() {
    std::cout << (1.5_bn - 0.8_bn) << std::endl;
    std::cout << (234.65_bn + 123.45_bn) << std::endl;
    std::cout << (2234525734562345235434.6345234525_bn * 125243523453256525234524353.423455634562365435623545_bn) << std::endl;
    return 0;
}
