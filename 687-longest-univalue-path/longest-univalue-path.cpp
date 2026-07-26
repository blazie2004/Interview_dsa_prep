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

    int helper(TreeNode* root, int &maxi) {
    if (!root) return 0;

    int l = helper(root->left, maxi);
    int r = helper(root->right, maxi);

    int lp = 0, rp = 0;

    if (root->left && root->left->val == root->val)
        lp = l + 1;

    if (root->right && root->right->val == root->val)
        rp = r + 1;

    maxi = max(maxi, lp + rp);

    return max(lp, rp);
}
    int longestUnivaluePath(TreeNode* root) {

        if(!root)return 0;
        
       int maxi=0;
       int ans=helper(root,maxi);
       return maxi;

        
    }
};