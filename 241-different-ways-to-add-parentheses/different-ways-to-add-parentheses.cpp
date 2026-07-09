class Solution {
public:

    vector<int> solve(string exp)
    {
        vector<int> ans;

        for(int i = 0; i < exp.size(); i++)
        {
            char ch = exp[i];

            if(ch == '+' || ch == '-' || ch == '*')
            {
                vector<int> left = solve(exp.substr(0, i));
                vector<int> right = solve(exp.substr(i + 1));

                for(int a : left)
                {
                    for(int b : right)
                    {
                        if(ch == '+')
                            ans.push_back(a + b);

                        else if(ch == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        if(ans.empty())
        {
            ans.push_back(stoi(exp));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {

        return solve(expression);
    }
};