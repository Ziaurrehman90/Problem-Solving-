class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(!root->left && !root->right){
            return root;
        }
        TreeNode *left=(root->left);
        TreeNode *right=(root->right);
        root->left=right;
        root->right=left;
      invertTree(root->left);
        invertTree(root->right);
        return root;
        
    }
};