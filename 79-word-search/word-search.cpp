class Solution {
public:

    bool dfs(int row, int col, int m, int n,
             vector<vector<char>>& board,
             string& word,
             int index,
             vector<vector<int>>& Vis,
             int delrow[],
             int delcol[]) {

        if (index == word.size() - 1)
            return true;

        Vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < m &&
                ncol >= 0 && ncol < n &&
                Vis[nrow][ncol] == 0 &&
                board[nrow][ncol] == word[index + 1]) {

                if (dfs(nrow, ncol, m, n, board, word,
                        index + 1, Vis, delrow, delcol))
                    return true;
            }
        }

        Vis[row][col] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> Vis(m, vector<int>(n, 0));

        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(i, j, m, n, board, word,
                            0, Vis, delrow, delcol))
                        return true;
                }
            }
        }

        return false;
    }
};