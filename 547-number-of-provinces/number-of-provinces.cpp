class Solution {
private :
    void dfs(int node,vector<int>adjLs[],vector<int>&Vis) {
        Vis[node]=1;
        for(auto it : adjLs[node]){
            if(!Vis[it]){
                dfs(it,adjLs,Vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adjLs[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int>Vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(Vis[i]==0){
                cnt++;
                dfs(i,adjLs,Vis);
            }
        }
        return cnt;

        
    }
};