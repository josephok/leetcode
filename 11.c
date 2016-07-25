/* 11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int maxArea(int* height, int heightSize) {
    int max = 0;
    for( int i = 0 ; i < heightSize; ++i)
    {
        int hi = height[i];
        if(hi == 0)
            continue;
        int minPosibleIndex = max / hi + i;
        for(int j = heightSize - 1; j > i && j >= minPosibleIndex; --j)
        {
            int hj = height[j];
            int area = MIN(hi, hj) * (j - i);
            if (area > max)
                max = area;
        }
    }
    return max;
}
