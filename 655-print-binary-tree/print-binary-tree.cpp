/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return 1 + max(height(root->left),
                       height(root->right));
    }

    void fill(TreeNode* root,
              int row,
              int left,
              int right,
              vector<vector<string>>& ans)
    {
        if(root == NULL)
            return;

        int mid = (left + right) / 2;

        ans[row][mid] = to_string(root->val);

        fill(root->left,
             row + 1,
             left,
             mid - 1,
             ans);

        fill(root->right,
             row + 1,
             mid + 1,
             right,
             ans);
    }

    vector<vector<string>> printTree(TreeNode* root) {

        int h = height(root);

        int rows = h;
        int cols = (1 << h) - 1;

        vector<vector<string>> ans(
            rows,
            vector<string>(cols, "")
        );

        fill(root,
             0,
             0,
             cols - 1,
             ans);

        return ans;
    }
};