/* 8. String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge,
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely
(ie, no given input specs). You are responsible to gather all the
input requirements up front.
*/

#include <string.h>
#include <assert.h>
#include <limits.h>

int myAtoi(char* str) {
    int sign = 1;
    int l = strlen(str);
    int res = 0;
    int i = 0;
    switch (str[0]) {
        case '-':
            sign = -1;
        case '+':
            i = 1;
            break;
        case ' ':
            for (i = 0; i < l - 1; i++) {
                if (str[i + 1] != ' ')
                    return myAtoi(str + i + 1);
            }
        default:
            break;
    }
    for (; i<l; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            /* In case that res *= 10 overflows */
            if (res > INT_MAX / 10 && res > 0)
                return sign == 1 ? INT_MAX : INT_MIN;
            else
                res *= 10;
            /* In case that res += str[i] - '0' overflows */
            int digit = str[i] - '0';
            if (res > INT_MAX - digit && res > 0)
                return sign == 1 ? INT_MAX : INT_MIN;
            else
                res += digit;
        }
        else
            break;
    }
    return sign * res;
}

int main(int argc, char const *argv[]) {
    char s1[] = "123";
    char s2[] = "abc";
    assert(myAtoi(s1) == 123);
    assert(myAtoi(s2) == 0);
    return 0;
}
