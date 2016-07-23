// 1. Two Sum
//
// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
// You may assume that each input would have exactly one solution.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <assert.h>

int* two_sum(int* nums, int nums_size, int target) {
    int *indices = calloc(2, sizeof(int));
    for (size_t i = 0; i < nums_size; i++) {
        for (size_t j = i + 1; j < nums_size; j++) {
            if (nums[i] + nums[j] == target) {
                indices[0]  = i;
                indices[1] = j;
            }
        }
    }
    return indices;
}

int main(int argc, char const *argv[]) {
    int nums[] = {2, 7, 11, 15};
    int nums_size = 4;
    int target = 9;
    int *indices = two_sum(nums, nums_size, target);
    assert(indices[0] == 0);
    assert(indices[1] == 1);
    free(indices);
    return 0;
}
