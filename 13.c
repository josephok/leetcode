/*13. Roman to Integer

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

#include <string.h>
#include <stdio.h>

int romanToInt(char* s) {
    int a[] = {1000, 500, 100, 50, 10, 5, 1};
    char r[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int ret = 0;
    int index = 0;
    int last = 0;

    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < strlen(r); j++) {
            if(r[j] == s[i]) {
                ret = ret + a[j];
                if (last > j) {
                    ret = ret - 2 * a[last];
                }
                last = j;
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    char *s = argv[1];
    printf("%d\n", romanToInt(s));
    return 0;
}
