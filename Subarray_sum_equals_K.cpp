// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // we can use prefix sum with hasing, to find wheather k-prefix Elem is already present in 
        // prefix or not

    
        unordered_map<int, int> mp;

        mp[0] = 1;                  // to match firstPrefix sum = k when it was never in map
        int preSum = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if(mp.count(preSum-k)) {
                res += mp[preSum-k];
            }

            mp[preSum]++;
        }

        return res;
    }
};