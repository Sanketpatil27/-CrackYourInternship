// You must write an algorithm that runs in O(n) time and uses only constant extra space.
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Think in terms of on and off. Turning on and turning off a switch. If a switch is already turned on, you can not turn it on again.
// Given this: [2,5,2,1,1,4]
// Go to index 0 and flip whatever value index 0 pointing to[if it was not flipped(turned on) before]...
// What does that mean?
// Index 0 has value 2. Flip whatever 2 is pointing-to. Since the array is 0 based, so we will flip 2-1 = 1 and that is 5.
// So, our result will look like:[2,-5,2,1,1,4]
// Next, we will go to index 1. After modifying the array, value at index 1 might or might not become negative. So, for this, we get the absolute value of that position. So, flip(if it was not flipped before) whatever Math.abs(arr[1])-1 = 4 pointing to.

// Since 4 is pointing to 1 and it is not negative(not flipped before), so we flip it to -1.

// [2,-5,2,1,-1,4]

// Next index 2, value 2, and it is pointing -5, which must be flipped by some other 2 in the array. So, we get our first duplicate value. Add 2 in our result and continue.

// In this way, we will be able to find all the elements in the array that are duplicate.

// ``
// Assume I/O Array   A -[ 4,   3,   2,   7,   8,    2,   3,    1   ]
//           index -       0     1    2   3    4     5    6      7
		  
				   
// 				   index                 element                       Todo                               
// 				    0                      A[0] = 4                   A[4-1] Not negative
// 					                                                  do it negetive mean we visited 4
// 																	  array - [4,3,2,-7,8,2,3,1]
																	 
// 					1                     A[1] = 3                      A[3-1] Not negative
// 					                                                    do it negetive mean we visited 3
// 					                                                    array - [4,3,-2,-7,8,2,3,1]
																	  
//                    2                      A[2] = 2                      A[2-1] Not negative
// 				                                                        do it negetive mean we visited 2
// 																	    array - [4,-3,-2,-7,8,2,3,1]
																	 
// 				   3                        A[3]=7                      A[7-1] Not negative
// 				                                                        do it negetive mean we visited 7
// 																        Array- [4,-3,-2,-7,8,2,-3,1]
																 
// 				   4                       A[4]=8                      A[8-1] Not negative
// 				                                                       do it negetive mean we visited 8
// 																        Array- [4,-3,-2,-7,8,2,-3,-1]
																 
// 				   5                     A[5]=2                       A[2-1] is Negative Mean It is A 
// 				                                                      duplicate ele so Put it into ans array  
// 																     Array- [4,-3,-2,-7,8,2,-3,-1]
																
//                     6                   A[6]=3                        A[3-1] is Negative Mean It is A 
//                                                                      duplicate ele so Put it into ans array  
//                                                                       Array- [4,-3,-2,-7,8,2,-3,-1]
																
// 					7                  A[7] = 1                     A[1-1] Not negative
// 					                                                do it negetive mean we visited 1
//                                                                      Array- [-4,-3,-2,-7,8,2,-3,-1]
															   
// 	So we Have {2 , 3 }  <= Here For ans
	

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // method 2: see in notes tab
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            int val = nums[abs(nums[i])-1];         // nums[i] can have negative value & index can't be negative so take absolute value
            if(val < 0) {
                res.push_back(abs(nums[i]));
                nums[abs(nums[i])-1] = abs(val);     // restore it in positive as originally
            }
            else        // flip the value 
                nums[abs(nums[i])-1] = -val;
        }

        return res;
    }
};