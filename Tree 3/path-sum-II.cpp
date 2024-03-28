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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>rootPath;
        DFS(root,path,rootPath);
        vector<vector<int>>zia;
        for(auto &it:rootPath){
            // vector<int>v;
            int sum=0;
            for(int j:it){
               sum+=j;
            }
            if(sum==targetSum){
                vector<int>v;
                for(int j:it){
                 v.push_back(j);
                }
                zia.push_back(v);
            }
        }
        return zia;
        
    }
};