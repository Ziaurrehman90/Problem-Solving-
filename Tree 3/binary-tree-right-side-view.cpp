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

    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>ans;
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
           
            while(n--){
                 TreeNode *node=q.front();
                 q.pop();
                 temp.push_back(node->val);
                 if(node->left){
                     q.push(node->left);
                 }
                 if(node->right){
                     q.push(node->right);
                 }


            }
            v.push_back(temp);
            

        }
        for(auto &it:v){
            ans.push_back(it[it.size()-1]);
        }
        return ans;

        
    }
};