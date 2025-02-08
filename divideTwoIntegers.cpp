#include <cstdint>
#include <limits>

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) return INT_MAX; 


        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long a = std::abs((long long)dividend);
        long long b = std::abs((long long)divisor);

        long long quotient = 0;
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            quotient += multiple;
        }

        return static_cast<int>(sign * quotient);
    }
};
