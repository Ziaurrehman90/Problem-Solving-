class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void preorder(Node *root,vector<int>&ans){
        if(root!=NULL){
            ans.push_back(root->data);
            preorder(root->left,ans);
            preorder(root->right,ans);
        }
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>v1,v2;
     preorder(root1,v1);
     preorder(root2,v2);
     unordered_map<int,int>map;
     for(auto &it:v1){
         map[it]++;
     }
     vector<int>ans;
     for(int i=0;i<v2.size();i++){
         if(map.find(v2[i])!=map.end()){
             ans.push_back(v2[i]);
         }
     }
     sort(ans.begin(),ans.end());
     return ans;
     
     
    }
};