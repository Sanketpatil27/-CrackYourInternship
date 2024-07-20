int subarraysDivByK(vector<int>& nums, int k) {
    // watched Coder army video: https://www.youtube.com/watch?v=rLOFyQ3FW20
    // we calculate prefix sum, and after some observations we can get that if we take prefix
    // sum's reminder then we can find the subarray's which divisible by k that's if same reminder comes again
    // but it fails when there is negative prefixSum or its reminder so we have to make reminder positive by adding k into it 
    // coz max reminder range is [-k-1, .. -1, 0, 1, .. k-1] if we add k to any negative reminder then it converted to positive
    // see notes for explanation

    unordered_map<int, int> mp;     // store reminder of prefix Sum with count
    mp[0] = 1;                      // 0 always  divisible by any number
    int preSum = 0;
    int rem, res = 0;

    for(int i = 0; i < nums.size(); i++) {
        preSum += nums[i];
        rem = preSum % k;

        // if reminder becomes negative then add k's value to make it positive
        if(rem < 0) 
            rem += k;           // using this we avoid previous solution's double modulos

        if(mp.count(rem))
            res += mp[rem];

        mp[rem]++;
    }

    return res;
}
