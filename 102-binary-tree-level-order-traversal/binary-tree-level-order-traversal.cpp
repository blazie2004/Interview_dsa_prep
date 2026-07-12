class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;

        while (q.size() > 0) {

            vector<int> temp;
            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};