class Solution {
public:
    // in loop :
    // first search for : next row searching of same colum
    // second search for : next col searching of same row
    // third search for : previous row searching of same colum
    // forth search for : previous col searching of same row

    // if we found any of these search is true then we go to search next
    // character(increment index) of that word
    // after every search again we put current character on that borad[row][col] for next calls, coz earlier we make this as checked
    // time : O(m*n) for checking all characters in grid,
    // space: O(auxilary space for recursion)

    bool DFS(int row, int col, int n, int m, int ind, vector<vector<char>>& board, string word) {
        if(ind == word.size())
            return true;

        if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] == '#' || board[row][col] != word[ind])
            return false;

        // mark current letter as visited & save for reseting
        char store = board[row][col];
        board[row][col] = '#';

        // now we have four choices we only move on if next letter matches
        bool up = DFS(row-1, col, n, m, ind+1, board, word);
        bool left = DFS(row, col-1, n, m, ind+1, board, word);
        bool right = DFS(row, col+1, n, m, ind+1, board, word);
        bool down = DFS(row+1, col, n, m, ind+1, board, word);

        // backtrack to reseat at unvisited
        board[row][col] = store;
        return (up || left || right || down);
    }


    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int ind = 0;          // track index of word

        // instead of visited array mark visited work = #, & unmark when backtracking
        // only go ahead  if first  letter matches

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                if(board[i][j] == word[0])
                    if(DFS(i, j, n, m, ind, board, word))
                        return true;


        return false;
    }
};