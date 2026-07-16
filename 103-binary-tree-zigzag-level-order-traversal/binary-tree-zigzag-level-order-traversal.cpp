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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


        queue<TreeNode*>q;
        bool flag=true;
        q.push(root);
        vector<vector<int>>final;


        if(!root)return {};


        while(q.size()>0){

            int sz=q.size();
            vector<int>arr;
            for(int i=0;i<sz;i++)
            {
                auto top=q.front();
                q.pop();
                if(top->left!=nullptr)q.push(top->left);
                if(top->right!=nullptr)q.push(top->right);

                arr.push_back(top->val);



            }
            if(flag){
                final.push_back(arr);
            }
            else{
                reverse(arr.begin(),arr.end());
                final.push_back(arr);
            }
            flag=!flag;

        }
        return final;

        
    }
};