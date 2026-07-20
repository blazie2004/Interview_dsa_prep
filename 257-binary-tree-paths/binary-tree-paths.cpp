class Solution {
public:
    void travel(TreeNode* root, vector<string>& ans, string s) {
        if (root == nullptr) {
            return;
        }

        // Add the current node first
        s += to_string(root->val);

        // Current node is a leaf
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(s);
            return;
        }

        s += "->";

        travel(root->left, ans, s);
        travel(root->right, ans, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        travel(root, ans, "");
        return ans;
    }
};