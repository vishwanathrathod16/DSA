class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] =
               findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        u = findUPar(u);
        v = findUPar(v);

        if(u == v) return;

        if(size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                    continue;

                for(int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1)
                    {
                        int node = i * n + j;
                        int adj = nr * n + nc;

                        ds.unionBySize(node, adj);
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    continue;

                set<int> st;

                for(int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1)
                    {
                        st.insert(
                        ds.findUPar(nr * n + nc));
                    }
                }

                int total = 1;

                for(auto it : st)
                    total += ds.size[it];

                ans = max(ans, total);
            }
        }

        for(int i = 0; i < n * n; i++)
        {
            if(ds.findUPar(i) == i)
                ans = max(ans, ds.size[i]);
        }

        return ans;
    }
};