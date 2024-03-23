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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        // it can be done thorugh level order traversal for that we have to maintain
        // a queue DS where we are storing the node,veritcal and level
        queue<pair<TreeNode*,pair<int,int>>>q;
        // for storing the level for particular vertex lets create a map 
        map<int,map<int,vector<int>>>mp;
       
        // here map stores the element with its vertical and level vector/multiset

        // now lets put the base case to queue 
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            while(n--){
            auto it=q.front();
            q.pop();
            TreeNode *node=it.first;
            int vert=it.second.first;
            int level=it.second.second;
            mp[vert][level].push_back(node->val);
            if(node->left!=NULL){
                q.push({node->left,{vert-1,level+1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{vert+1,level+1}});
            }
        }
        }
        
        for(auto &it:mp){
           vector<int>ans;
           for(auto &i:it.second){
               if(i.second.size()>1){
                sort(i.second.begin(),i.second.end());
               }
               for(auto j:i.second){
                ans.push_back(j);
               }
           }
           v.push_back(ans);
        }
        return v;
        
    }
};