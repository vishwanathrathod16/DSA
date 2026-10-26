class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> Vis(n, vector<int>(m, 0));
        int cnt = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!Vis[i][j] && grid[i][j] != 0) {
                    long long sum = 0;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    Vis[i][j] = 1;

                    while(!st.empty()) {
                        auto [x, y] = st.top();
                        st.pop();

                        sum += grid[x][y];

                        for(int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
                               !Vis[nx][ny] && grid[nx][ny] != 0) {
                                Vis[nx][ny] = 1;
                                st.push({nx, ny});
                            }
                        }
                    }

                    if(sum % k == 0) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};