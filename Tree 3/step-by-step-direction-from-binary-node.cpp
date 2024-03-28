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
// function to fina a path from root to node 
// bool findPath(TreeNode *root, int key, vector<TreeNode*>&v){
//     // base case 
//     if(root==NULL){
//         return false;
//     }
//     v.push_back(root);
//     if(root->val==key || findPath(root->left,key,v) || findPath(root->right,key,v)){
//         return true;
//     }
//     v.pop_back();
//     return false;
// }
// // function to find LCA 
// TreeNode* LCA(TreeNode *root, int startValue, int destValue){
//     // lets find a path from root to start value 
//     if(root==NULL){
//         return NULL;
//     }
//     vector<TreeNode*>v1;
//     findPath(root,startValue,v1);
//     // lets find a path from root to destination 
//     vector<TreeNode*>v2;
//     findPath(root,destValue,v2);
//     // lets do teh comparison to find the first different value 
//     int i=0;
//     while(i<v1.size() && i<v2.size()){
//         int n1=v1[i]->val;
//         int n2=v2[i]->val;
//         if(n1!=n2){
//             break;
//         }
//         i++;
//     }
//     return v1[i-1];

// }
// this function gives TLE after passing  332/332 test cases 😢

// optimised LCA function 
 TreeNode* LCA(TreeNode* root, int start, int dest) {
        if(root==NULL) return NULL;
        
        if(root->val == start || root->val == dest) {
               return root;
        }
        
        TreeNode* left = LCA(root->left, start, dest);
        TreeNode* right = LCA(root->right, start, dest);
        
        if(left!=NULL  && right!=NULL) {
           return root;
        }
        
        if(left!=NULL){
            return left;
        }
        return right;
    }

// now lets creeate a function of traversal 
bool DFS(TreeNode *root, string &path, int key){
    if(root==NULL){
        return false;
    }
    if(root->val==key){
        return true;
    }
    path.push_back('L');
    if(DFS(root->left,path,key)){
        return true;
    }
    path.pop_back();
    path.push_back('R');
    if(DFS(root->right,path,key)){
        return true;
    }
    path.pop_back();
    return false;
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca=LCA(root,startValue,destValue);
        string start="";
        string dest="";
        DFS(lca,start,startValue);
        DFS(lca,dest,destValue);
        for(int i=0;i<start.size();i++){
            start[i]='U';
        }
        return start+dest;
    }
};