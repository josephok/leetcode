// 4. Median of Two Sorted Arrays
//
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).
//
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define MIN(a, b) (((a) < (b)) ? (a): (b))

double median(int a[], int n, int b[], int m, int k)
{
    if (n <= 0) return b[k-1];
    if (m <= 0) return a[k-1];
    if (k <= 1) return MIN(a[0], b[0]);
    if (b[m/2] >= a[n/2]) {
        if ((n/2 + 1 + m/2) >= k)
             return median(a, n, b, m/2, k);
        else
             return median(a + n/2 + 1, n - (n/2 + 1), b, m, k - (n/2 + 1));
   }
   else {
        if ((m/2 + 1 + n/2) >= k)
             return median( a, n/2, b, m, k);
        else
             return median( a, n, b + m/2 + 1, m - (m/2 + 1), k - (m/2 + 1));
   }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size)
{
    if ((nums1Size + nums2Size ) % 2 == 0 ) {
        return (median(nums1, nums1Size, nums2, nums2Size,
                       (nums1Size + nums2Size) / 2) +
                median(nums1, nums1Size, nums2, nums2Size,
                       (nums1Size + nums2Size) / 2 + 1)) / 2.0;
    }
    else {
        return median(nums1, nums1Size, nums2, nums2Size,
                      (nums1Size + nums2Size) / 2 + 1);
    }
}

int main(int argc, char const *argv[]) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    double median1 = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("%lf\n", median1);
    assert(median1 == 2.0);

    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    double median2 = findMedianSortedArrays(nums3, 2, nums4, 2);
    printf("%lf\n", median2);
    assert(median2 == 2.5);
    return 0;
}
