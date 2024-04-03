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
int max_sum=0;
class Pair{
    public:
    int minimum;
    int maximum;
    int sum;
    bool isbst;
};
Pair helper(TreeNode *root){
    if(root==NULL){
        Pair output;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        output.sum=0;
        output.isbst=true;
        return output;
    }
    Pair output;
    Pair leftans=helper(root->left);
    Pair rightans=helper(root->right);
    int mini=min(root->val,min(leftans.minimum,rightans.minimum));
    int maxi=max(root->val,max(leftans.maximum,rightans.maximum));
    bool isBST=(root->val>leftans.maximum&&root->val<rightans.minimum)&&(leftans.isbst)&&(rightans.isbst);
    output.minimum=mini;
    output.maximum=maxi;
    output.isbst=isBST;
    if(isBST){
         output.sum=leftans.sum+rightans.sum+root->val;
         if(output.sum>max_sum){
             max_sum=output.sum;
         }
    }
    else{
        output.sum=0;
    }
    return output;
}
    int maxSumBST(TreeNode* root) {
         helper(root);
         return max_sum;

    }
};