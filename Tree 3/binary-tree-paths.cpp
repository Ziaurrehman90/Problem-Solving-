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
// can we apply dfs ??
void DFS(TreeNode *root, vector<int>&path,vector<vector<int>>&ans){
    // base case 
    if(root==NULL){
        return;
    }
    path.push_back(root->val);
    // if root is the leaf node 
    if(root->left==NULL && root->right==nullptr){
       ans.push_back(path);
    //    return;
    }
    else{
    DFS(root->left,path,ans);
    DFS(root->right,path,ans);
    }
    path.pop_back();

}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>path;
        vector<vector<int>>ans;
        DFS(root,path,ans);
        vector<string>zia;
        for(auto &it:ans){
            string temp="";
            for(int i=0;i<it.size()-1;i++){
                temp+=to_string(it[i]);
                temp+="->";
            }
            temp+=to_string(it[it.size()-1]);
            zia.push_back(temp);
        }
        return zia;
        
    }
};