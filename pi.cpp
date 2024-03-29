//
// Created by m3tr0 on 22.02.2024.
//

#include "BigNum.h"
#include <iostream>
#include <chrono>

const static char correct_pi_str[] = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989";

BigNum pi(size_t precision) {
    BigNum n0{16, precision + 10}, n1{4, precision + 1},
            n2{2, precision + 10}, n3{1, precision + 1};

    BigNum result{0, precision + 10};

    int k = 0;
    while (true) {
        n0 /= BigNum{16};
        BigNum t = n0 * (n1 / (8 * k + 1) - n2 / BigNum{8 * k + 4} - n3 / BigNum{8 * k + 5} - n3 / BigNum{8 * k + 6});

        t.decimal_precision(precision + 10);
        if (t.is_zero()) break;
        result += t;
        k++;
    }

    result.decimal_precision(precision);
    return result;
}

int main(int argc, char**argv) {
    std::cout << "Enter precision:" << std::endl;
    size_t precision;
    std::cin >> precision;

    auto start = std::chrono::high_resolution_clock::now();
    BigNum calculated_pi = pi(precision);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    BigNum correct_pi = BigNum{correct_pi_str};
    correct_pi.decimal_precision(precision);

    std::cout << ((calculated_pi == correct_pi) ? "Pi is correct!" : "Pi is incorrect...") << std::endl;
    std::cout << "Value: " << calculated_pi << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}
