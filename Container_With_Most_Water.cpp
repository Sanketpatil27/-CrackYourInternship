// Algorithm:  See in notes tab:   https://leetcode.com/problems/container-with-most-water/description/

// Designate two pointers ptr_lo = 0 and ptr_hi = length(height) - 1 i.e. set the two pointers at the two ends.
// If height[ptr_lo] <= height[ptr_hi] then increment ptr_lo.
// If height[ptr_lo] > height[ptr_hi] then decrement ptr_hi (i.e. iteratively move the smaller of the two edges closer to the other).
// Calculate the area after each change and keep track of the maximum area.
// End when the two pointers are equal to each other.
// Why the algorithm works
// Let i, j be the left and right edges of the container with most water (0 <= i < j < length(height)). If there are multiple such containers, then i, j can be the edges of any one of them. We will prove that between the start and end condition, there must be one moment when ptr_lo == i and ptr_hi == j i.e. the maximum area is always considered.

// Note that between the start and end condition, there must be a pointer that reaches one of the edge of the maximum container (the dashed border in our figure). We can now devise three scenarios:

// Scenario 1: ptr_lo == i and ptr_hi == j at the same time
// This means we proved our hypothesis.

// Scenario 2: ptr_lo reaches the left edge first
// Here, we have ptr_lo == i and j < ptr_hi < length(height). We can now have two sub-scenarios:

// Sub-scenario 1 If height[ptr_hi] >= height[ptr_lo] i.e. the right edge >= left edge


// In this situation, we see that by letting height[ptr_hi] >= height[ptr_lo], we create a new area strictly greater than the maximum area. This contradicts our original stipulation. Therefore, sub-scenario 1 is impossible.

// Sub-scenario 2 If height[ptr_lo] > height[ptr_hi] i.e. the left edge > right edge


// Using the algorithm, we will just keep decrementing ptr_hi. In fact, because sub-scenario 1 is impossible, once ptr_lo == i, then for all j < ptr_hi < length(height) we have height[ptr_lo] > height[ptr_hi].

// Therefore, once ptr_lo reaches i, it will stays there until ptr_hi reaches j. We proved our hypothesis

// Scenario 3: ptr_hi reaches the right edge first
// This is the same as scenario 2, only reversed.


class Solution {
public:
    int maxArea(vector<int>& height) {
        // Time: O(N^2)  Space: O(1)     GIVING TLE!!!
        // we start from 1st line and for each line from starting we calculate max water it 
        // can store from last line, and multiply the space between both by the minimum of both lines (starting line, last line)

        int n = height.size();
        int maxWater = 0;

        // for(int i = 0; i < n; i++) {
        //     for(int j = n-1; j >= 0; j--) {
        //         int space = j - i;
        //         int weightOfStoredWater = min(height[i], height[j]);
        //         maxWater = max(maxWater, weightOfStoredWater*space);
        //     }
        // }

        // method 2: time: O(n)  space: O(1)
        // using 2 pointers appraoch
        // 1st pointer on first line & 2nd on last line
        // calculate maxWater same as previous and then move the smaller pointer further
        // wheather do increment of first pointer OR decrement of last pointer
        // using this we always be moving toward getting maximum water between 2 points
        int s = 0, e = n-1;         // defining starting & ending pointer

        while(s < e) {
            int space = e - s;
            int weightOfStoredWater = min(height[s], height[e]);        // the storage area
            maxWater = max(maxWater, weightOfStoredWater*space);

            if(height[s] < height[e])
                s++;
            else 
                e--;
        }

        return maxWater;
    }
};