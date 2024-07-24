// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0
// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution {
  public:
    void solve(int i, vector<vector<int>> &ans, vector<int> &arr, int n) {
        if(i >= n) {
            ans.push_back(arr);
            return;
        }
         
        for(int j = i; j < n; j++) {
            swap(arr[i], arr[j]);
            solve(i+1, ans, arr, n);
            swap(arr[i], arr[j]);
        }
        
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        solve(0, ans, arr, n);
        
        // for sorted and without duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};