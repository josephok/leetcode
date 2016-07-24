/*7. Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int power(int base, int e) {
    int res = 1;
    for (size_t i = 0; i < e; i++) {
        res *= base;
    }
    return res;
}

int reverse(int x) {
    if (x == INT_MIN) {
        return 0;
    }
    int int_max[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    int int_min[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
    int minus = 0;
    if (x < 0) {
        minus = 1;
    }
    x = abs(x);
    int integer[10] = {0};
    int quotation = x / 10;
    int r = x % 10;
    integer[0] = r;
    int i = 1;
    while (quotation > 0) {
        r = quotation % 10;
        integer[i++] = r;
        quotation /= 10;
    }

    int res = 0;
    for (int j = i - 1; j >= 0; j--) {
        res += integer[j] * power(10, i - 1 - j);
    }
    if (minus) {
        res = -res;
    }

    int res_int[10] = {0};
    if (i >= 10) {
        int temp = abs(res);
        int k = 0;

        while (temp) {
            r = temp % 10;
            res_int[k++] = r;
            temp /= 10;
        }

        temp = abs(x);
        k = 1;
        while (temp) {
            r = temp % 10;
            if (res_int[i - k++] != r) {
                return 0;
            }
            temp /= 10;
        }
    }

    return res;
}

int main(int argc, char const *argv[]) {
    int x = -2147483412;
    printf("%d\n", reverse(x));
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(10) == 1);
    assert(reverse(1000000003) == 0);

    return 0;
}
