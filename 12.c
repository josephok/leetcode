/*12. Integer to Roman

Given an integer,  convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[10] = {'\0'};

char* intToRoman(int num) {
    char symbols[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
                         "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for(int i=0; num != 0; ++i) {
        while(num >= value[i]) {
            num -= value[i];
            strcat(str, symbols[i]);
        }
    }
    return str;
}

int main(int argc, char const *argv[]) {
    int num = atoi(argv[1]);
    printf("%s\n", intToRoman(num));
    return 0;
}
