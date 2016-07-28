/* 15. 3Sum

Given an array S of n integers, are there elements a, b, c in S such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return x - y;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **results = NULL, *result = NULL, resultsSize = 0;
    if (nums != NULL && numsSize >= 3) {
        int i, j;
        qsort(nums, numsSize, sizeof(int), compare);
        for (i = 0; i < numsSize - 2 && nums[i] <= 0; ++i) {
            for (j = i + 1; j < numsSize - 1; ++j) {
                int r_val = -(nums[i] + nums[j]);
                int occured = 0, index = resultsSize;
                while (!occured && index-- > 0 && results[index][0] == nums[i])
                    occured = results[index][1] == nums[j];
                if (occured)
                    continue;
                if (bsearch(&r_val, nums + j + 1, numsSize - (j + 1), sizeof(int), compare) == NULL)
                    continue;
                result = (int*)malloc(3 * sizeof(int));
                result[0] = nums[i], result[1] = nums[j], result[2] = r_val;
                results = (int**)realloc(results, (resultsSize + 1) * sizeof(int*));
                results[resultsSize++] = result;
            }
        }
    }
    *returnSize = resultsSize;
    return results;
}

static void print_results(int **results, int arrsize, int size)
{
    printf("There're %d arrays\n", arrsize);
    printf("-----------------------\n");
    for (int i = 0; i < arrsize; i++) {
        printf("%d. ", i + 1);
        for (int j = 0; j < size; j++) {
            printf("%3d ", results[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}

int main(int argc, char const *argv[]) {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize = 0;
    int **results = threeSum(nums, 6, &returnSize);
    print_results(results, returnSize, 3);
    return 0;
}
