class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // time: O(n^2)  & space: O(n^2) in worst consedering every triplet in
        // array for every i search if there exist any pair that sum up to -nums[i]

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            int s = i + 1, e = n - 1;

            // don't start with same num as previous to avoid duplicates
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            // now we find if there is a pair with sum == -(nums[i])
            while (s < e) {
                if (nums[s] + nums[e] == -nums[i]) {
                    vector<int> triplet = {nums[i], nums[s++], nums[e--]};
                    res.push_back(triplet);

                    // removing duplicate chanches
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    // since all are sorted we can check continuously
                    while (s < e && nums[s] == triplet[1])
                        s++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (s < e && nums[e] == triplet[2])
                        e--;

                } else if (nums[s] + nums[e] < -nums[i])
                    s++;
                else
                    e--;
            }
        }

        return res;
    }
};