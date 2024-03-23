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
void dfs(TreeNode *root,int count,vector<int>&ans){
    if(root==NULL){
        return;
    }
    count++;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(count);
    }
    dfs(root->left,count,ans);
    dfs(root->right,count,ans);

}
    int maxDepth(TreeNode* root) {
        // base case
        if(root==NULL){
            return 0;
        }
        vector<int>ans;
        dfs(root,0,ans);
        return *max_element(ans.begin(),ans.end());


    }
};