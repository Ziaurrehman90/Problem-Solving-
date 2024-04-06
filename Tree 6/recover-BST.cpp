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
// brute force 
 vector<int>v;
 int i=0;
void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
}
void helper(TreeNode *root){
  
    if(root){
        helper(root->left);
        
        if(root->val!=v[i]){
            swap(root->val,v[i]);
            // root->val=data;
        }
        i++;
        helper(root->right);
    }

}

    void recoverTree(TreeNode* root) {
       
        inorder(root);
        sort(v.begin(),v.end());
        helper(root);
    }
};