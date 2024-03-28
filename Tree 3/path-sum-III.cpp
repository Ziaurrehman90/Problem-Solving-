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

    long long  zia=0;
    void DFS(TreeNode *root, long long  targetSum ){
        // base case 
        if(root==NULL){
            return;
        }
        if(root->val==targetSum){
            zia++;
        }
        DFS(root->left,targetSum-root->val);
        DFS(root->right,targetSum-root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
              if(root==NULL){
                return 0;
              }
              if(root){
                DFS(root,targetSum);
                pathSum(root->left,targetSum);
                pathSum(root->right,targetSum);
              }
              return zia;

    }
};