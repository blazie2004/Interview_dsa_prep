/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void parent_mapping(
        TreeNode* root,
        unordered_map<TreeNode*, TreeNode*>& parent
    ) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            parent[root->left] = root;
            parent_mapping(root->left, parent);
        }

        if (root->right != nullptr) {
            parent[root->right] = root;
            parent_mapping(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent_mapping(root, parent);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int distance = 0;

        while (!q.empty() && distance < k) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Move left
                if (current->left != nullptr &&
                    !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                // Move right
                if (current->right != nullptr &&
                    !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                // Move to parent
                if (parent.find(current) != parent.end()) {
                    TreeNode* par = parent[current];

                    if (!visited[par]) {
                        q.push(par);
                        visited[par] = true;
                    }
                }
            }

           
            distance++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};