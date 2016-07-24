/*6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given
number of rows like this: (you may want to display this pattern in a
fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given
a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if(numRows == 1) return s;
    int len = strlen(s), k = 0, interval = numRows * 2 - 2;
    char *res = calloc(len + 1, sizeof(char));
    for(int j = 0; j < len ; j += interval)
        res[k++] = s[j];

    for(int i = 1; i < numRows - 1; i++) {
        int inter = i * 2;
        for(int j = i; j < len; j += inter) {
            res[k++] = s[j];
            inter = interval - inter;
        }
    }

    for(int j = numRows - 1; j < len ; j += interval)
        res[k++] = s[j];
    return res;
}

int main(int argc, char const *argv[]) {
    char *res = convert("PAYPALISHIRING", 3);
    assert(strcmp("PAHNAPLSIIGYIR", res) == 0);
    return 0;
}
