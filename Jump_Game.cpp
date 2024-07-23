class Solution {
public:
    // we can start searching from second last index that can we jump to last index or not?
    // if yes then update last index with current index, and again start checking for curretn index as last index.
    // IF Block:
    // in this block we are checking [current index + elem at current index is >= our Destination index] means can we jump from current index to the last destination index.
    // if yes: then update lastPost with current index to check for this index as destination
    // if lastPost becomes 0 means we can jump from start to end
    bool tryJump(int ind, vector<int> &memo, vector<int>& nums) {
        if(ind >= nums.size()-1)
            return true;

        // if nums[ind] = 0 means can't jump further 
        if(nums[ind] == 0)
            return false;

        // overlaping subproblem
        if(memo[ind] != -1)
            return memo[ind];

        for(int i = ind+1; i <= ind+nums[ind]; i++) {
            if(tryJump(i, memo, nums))         // length should be nums[i] steps from i'th position
                return memo[ind] = true;;
        }

        return memo[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        // simply check all possible ways with recursion
        // at first jump length should always be nums[0], else it can't jump further
        // diving TLE, so we try using memoization, using 1D dp array
        int ind = 0;
        vector<int> memo(nums.size(), -1);
        return tryJump(ind, memo, nums);

        // method 2:
        // from notes tab: directly check from destination if we can reach there from current index
        // if yes then update the destination as current index & i--
        // int n = nums.size();
        // int dest = n-1;         // destination
        // for(int i = n-2; i >= 0; i--) {
        //     if(nums[i]+i >= dest) {
        //         dest = i; 
        //     }
        // }   

        // means we can reach destination from 0th index
        // return dest == 0;

        // from starting:
        // it shows at max what index can I reach.
        // initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
            
            //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            
            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }
        
        //this means that you reached till the end of the array, wohooo!! 
        return true;
    }
};