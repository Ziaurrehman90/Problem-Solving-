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
TreeNode *conversion(vector<int>&nums,int low,int high){
    if(nums.size()==0){
        return NULL;
    }
    if(low>high){
        return NULL;
    }
    int mid=low+(high-low)/2;
    TreeNode *node= new TreeNode(nums[mid]);
    node->left=conversion(nums,low,mid-1);
    node->right=conversion(nums,mid+1,high);
    return node;


}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return conversion(nums,low,high);
    }
};