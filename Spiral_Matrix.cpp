                    // https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // require 4 variable as for left right top bottom & spiral array
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> spiral;

        //           top
        //        ----------
        //        |        |       
        //  left  |        |    right
        //        |        |
        //        ----------
        //          bottom
        // we just have to move in saquential direction: 
        // top -> bottom -> left -> right
        int top = 0;
        int right = m-1;
        int left = 0;
        int bottom = n-1;

        // when the top row completed we should jump to next row (top++)
        // and go down from right side, after reaching end do (right--)
        // then go left side from bottom, after reaching column 0 do (bottom--)
        // then go to top from left side (col 0) after reaching top do (left++)

        while(top <= bottom && left <= right) {
            // ------- travel 'left-to-right' from 'top' side --------
            for(int i = left; i <= right; i++)
                spiral.push_back(matrix[top][i]);

            top++;          // after that top will be increased


            // ------- travel 'top-to-bottom' from 'right' side --------
            for(int i = top; i <= bottom; i++)           // start from top coz 1 layer is completed
                spiral.push_back(matrix[i][right]);

            right--;        // after that right will be decreased


            // ------- travel 'right-to-left' from 'bottom' side -------
            if(bottom >= top) {                         // to don't go to visited path
                for(int i = right; i >= left; i--)
                    spiral.push_back(matrix[bottom][i]);

                bottom--;           // after that bottom will be decreased
            }


            // ------- travel 'bottom-to-top' from 'left' side --------
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    spiral.push_back(matrix[i][left]);

                // after that left will be increased
                left++;
            }
        }

        return spiral;
    } 
};