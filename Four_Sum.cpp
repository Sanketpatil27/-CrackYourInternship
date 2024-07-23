class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // time: O(n^3) space: O(1)
        // similar as 3Sum approach with little modification for target & 4th value
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            // don't start with same num as previous to avoid duplicates
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i+1; j < n; j++) {
                // don't start with same num as starting val to avoid duplicates
                if (j != i+1 && nums[j] == nums[j - 1])
                    continue;

                long long newTarget = target-(long(nums[i]+nums[j]));

                int s = j + 1, e = n - 1;
                // now we find if there is a pair with sum == -(nums[i])
                while (s < e) {
                    if (nums[s] + nums[e] == newTarget) {
                        vector<int> triplet = {nums[i], nums[j], nums[s++], nums[e--]};
                        res.push_back(triplet);

                        // removing duplicate chanches
                        // Processing duplicates of Number 2
                        // Rolling the front pointer to the next different number forwards
                        // since all are sorted we can check continuously
                        while (s < e && nums[s] == triplet[2])
                            s++;

                        // Processing duplicates of Number 3
                        // Rolling the back pointer to the next different number backwards
                        while (s < e && nums[e] == triplet[3])
                            e--;

                    } else if (nums[s] + nums[e] < newTarget)
                        s++;
                    else
                        e--;
                }
            }
        }

        return res;
   }
};