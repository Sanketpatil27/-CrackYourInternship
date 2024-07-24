// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    int cntLiveCells(int r, int c, vector<vector<int>>& original) {
        int cnt = 0;
        int n = original.size();
        int m = original[0].size();

        // for calculating directions of row: left diagonal, above, right diagonal, right side, botton-right diagonal
        // down, bottom-left diagonal, left side
        vector<int> dirRow ={-1, -1, -1, 0, +1, +1, +1, 0};
        vector<int> dirCol ={-1, 0, +1, +1, +1, 0, -1, -1};

        // calculate all direction's live cells
        for(int i = 0; i < dirRow.size(); i++) {
            int newRow = r + dirRow[i];
            int newCol = c + dirCol[i];

            if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m)   
                cnt += original[newRow][newCol];        // add 1 if live cell else add 0
        }

        return cnt;
    }

    void solve(int r, int c, vector<vector<int>>& board, vector<vector<int>>& original) {
        if(r == original.size() || c == original[0].size() || r < 0 || c < 0) 
            return;

        // before checking conditions we count the live cells around board[r][c]
        int cntLives = cntLiveCells(r, c, original);
        
        // before applying live cell condition first check current cell is live or not
        // 1st condition
        if(original[r][c] == 1 && cntLives < 2)
            board[r][c] = 0;

        // no need for checking 2nd case

        // 3nd condition
        if(original[r][c] == 1 && cntLives > 3)
            board[r][c] = 0;

        // 4th condition
        if(original[r][c] == 0 && cntLives == 3)
            board[r][c] = 1;
    }

    void gameOfLife(vector<vector<int>>& board) {
        // apply all the conditions on 'Original' matrix recursively & change made in board
        vector<vector<int>> original = board;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                solve(i, j, board, original);
            }
        }
    }
};