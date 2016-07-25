/* 9. Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int power(int base, int e) {
    int res = 1;
    for (size_t i = 0; i < e; i++) {
        res *= base;
    }
    return res;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int temp = x;
    int i = 0;
    int j = 0;
    while (temp) {
        temp /= 10;
        i++;
    }

    temp = x;
    int k = 0;
    while (temp) {
        if (temp % 10 == x / (power(10, i - 1 - k))) {
            x %= power(10, i - 1 - k);
            j++;
            k++;
        }
        else
            return false;
        temp /= 10;
    }

    if (i == j)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[]) {
    int x = 121;
    assert(isPalindrome(x));
    return 0;
}
