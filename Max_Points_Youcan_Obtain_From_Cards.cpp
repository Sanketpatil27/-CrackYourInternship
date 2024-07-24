// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    // using recursion giving TLE!!!
    // int solve(int fe, int be, int takenCnt, int score, vector<int>& cardPoints, int k) {
    //     if(takenCnt == k)
    //         return score;

    //     if(fe >= be)
    //         return 0;

    //     if(fe >= cardPoints.size() || be < 0)
    //         return 0;
        
    //     // in one call we choose front card & in other we choose last card
    //     return max(solve(fe+1, be, takenCnt+1, score+cardPoints[fe], cardPoints, k), 
    //                solve(fe, be-1, takenCnt+1, score+cardPoints[be], cardPoints, k));
    // }


    // int getWindowSum(int s, int e, vector<int>& cardPoints) {
    //     int sum = 0; 

    //     for(int i = s; i <= e; i++)
    //         sum +=  cardPoints[i];

    //     return sum;
    // }

    int maxScore(vector<int>& cardPoints, int k) {
        // greedy won't work here, ex:  [1,2,3,4,5,6,0] k = 3 choosing 5+6+0 = 11 & greedy choose= 1+2+3 = 6
        // we can try executing all possible ways using recursion
        // define frontEnd and BackEnd ponts from which we will choose
        // int fe = 0, be = cardPoints.size()-1, score = 0;       
        // int mxScore = INT_MIN;
        // int takenCnt = 0;           // count of picked cards
        // mxScore = solve(fe, be, takenCnt, score, cardPoints, k);
        // return mxScore;

        // by hints:
        // Hint 1: Let the sum of all points be total_pts. You need to **remove** a sub-array from cardPoints with length n - k.
        // Hint 2: Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow)

        int total_pts = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int windowSize = cardPoints.size()-k;
        int mxScore = 0;

        // first calculate first window
        int windowSum = 0;
        for(int i = 0; i < windowSize; i++)
            windowSum += cardPoints[i];

        mxScore = max(mxScore, total_pts - windowSum);

        // we just removing the sum of windowSize elements so we can check like in circular array. 
        // ex: [4, 2, 3, 3, 5]  k = 2  here n-k = 3, total=17 we remove first  window 17-4+2+3=8 then move on and 
        // remove 2+3+3 = 17-8 = 9  it means we pick 4 & 5 which is maximum
        for(int i = windowSize; i < cardPoints.size(); i++) {
            // add new element of window and remove the first elem of last window which now outside the current Window
            windowSum = (windowSum+cardPoints[i]) - cardPoints[i-windowSize];   
            mxScore = max(mxScore, total_pts - windowSum);
        }

        return mxScore;
    }
};