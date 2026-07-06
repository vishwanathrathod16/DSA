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

    TreeNode* build(vector<int>& preorder, int start, int end)
    {
        if(start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[start]);

        int idx = start + 1;

        while(idx <= end && preorder[idx] < preorder[start])
            idx++;

        root->left = build(preorder, start + 1, idx - 1);
        root->right = build(preorder, idx, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return build(preorder, 0, preorder.size() - 1);
    }
};