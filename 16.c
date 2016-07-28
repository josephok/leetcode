/* 16. 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is
closest to a given number, target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    int smallest = INT_MAX;
    int temp, result, ri, rj, rk;
    for (size_t i = 0; i < numsSize; i++) {
        for (size_t j = i + 1; j < numsSize; j++) {
            for (size_t k = j + 1; k < numsSize; k++) {
                temp = abs(target - (nums[i] + nums[j] + nums[k]));
                if (temp < smallest) {
                    smallest = temp;
                    result = nums[i] + nums[j] + nums[k];
                    ri = i;
                    rj = j;
                    rk = k;
                }
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int s[] = {1, 1, 1, 0};
    int target = -100;
    printf("%d\n", threeSumClosest(s, 4, target));
    return 0;
}
