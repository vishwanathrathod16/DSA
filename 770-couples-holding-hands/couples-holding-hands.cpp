class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        int n = row.size();

        vector<int> pos(n);

        for(int i = 0; i < n; i++)
            pos[row[i]] = i;

        int ans = 0;

        for(int i = 0; i < n; i += 2)
        {
            int first = row[i];
            int partner = first ^ 1;

            if(row[i + 1] == partner)
                continue;

            int partnerIndex = pos[partner];

            pos[row[i + 1]] = partnerIndex;
            pos[partner] = i + 1;

            swap(row[i + 1], row[partnerIndex]);

            ans++;
        }

        return ans;
    }
};