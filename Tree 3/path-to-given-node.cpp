/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 bool path(TreeNode *root, int key,vector<int>&ans){
     if(root==NULL){
         return false;
     }
      ans.push_back(root->val);
     if(root->val==key || path(root->left,key,ans) || path(root->right,key,ans)){
        
         return true;
     }
     ans.pop_back();
     return false;
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int>ans;
    path(A,B,ans);
    return ans;
    // return {};
}
