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
bool right_sub(TreeNode *root, int key){
    if(root==NULL){
        return true;
    }
    if(root->val>key && right_sub(root->left,key) && right_sub(root->right,key)){
      return true;
    }
    return false;
}
bool left_sub(TreeNode *root, int key){
    if(root==NULL){
        return true;
    }
    if(root->val<key && left_sub(root->left,key) && left_sub(root->right,key)){
      return true;
    }
    return false;
}
    bool helper(TreeNode *root){
        // case 1 . 
        if(root==NULL){
            return true;
        }
        // if it has only root 
        if(!root->left && !root->right){
            return true;
        }
        // if root has only right schild 
        if(root->left==NULL){
            if(root->val<root->right->val && helper(root->right) && right_sub(root->right,root->val) ){
                return true;
            }
            else{
                return false;
            }
        }
        // if it has only left child 
        if(root->right==NULL){
            if(root->left->val<root->val && helper(root->left) && left_sub(root->left,root->val)){
                return true;
            }
            else{
                return false;
            }
        }
        if(root->left && root->right ){
            if(root->left->val < root->val && root->right->val>root->val && helper(root->left) && helper(root->right) && left_sub(root->left,root->val) && right_sub(root->right,root->val)){
                return true;
            }
        }
        return false;
        
        
        
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};