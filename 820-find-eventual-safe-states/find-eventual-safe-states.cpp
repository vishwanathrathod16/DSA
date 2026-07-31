class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdeg(n);

        for (int i = 0; i < n; i++) {
            outdeg[i] = graph[i].size();
            for (int v : graph[i]) {
                rev[v].push_back(i);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdeg[i] == 0)
                q.push(i);
        }

        vector<int> safe;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            safe.push_back(u);

            for (int v : rev[u]) {
                if (--outdeg[v] == 0)
                    q.push(v);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
