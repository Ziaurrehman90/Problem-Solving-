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
void DFS(TreeNode *root, vector<int>&path, vector<vector<int>>&rootPath){
    // base case 
    if(root==NULL){
        return;
    }
    path.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        rootPath.push_back(path);
    }
    else{
        DFS(root->left,path,rootPath);
        DFS(root->right,path,rootPath);
    }
    path.pop_back();
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>rootPath;
        DFS(root,path,rootPath);
        for(auto &it:rootPath){
            int sum=0;
            for(int i:it){
                sum+=i;
            }
            if(sum==targetSum){
                return true;
            }
        }
        return false;
        
    }
};