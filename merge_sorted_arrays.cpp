class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we use 2 pointers one pointer will be on num1 & another on num2, start filling from last side
        // if nums1[i] < nums2[j] then we do i++ and move on
        // if nums[i] > num2[j] then we swap both and do i++ & j++

        // k is the nums1's last index where we store max values from ith & jth index 
        int i = m-1, k = m+n-1, j = n-1;

        while (i >= 0 && j >= 0 && k >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }


        // now fill the remaining space of nums1 with remaining values in nums2
        while (j >= 0)
            nums1[k--] = nums2[j--];

        // if nums 2 is over then check if i is still >= 0
        while (i >= 0) 
            nums1[k--] = nums1[i--];
    }
};