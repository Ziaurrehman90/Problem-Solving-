class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
 
    void inorder(Node *root,vector<int>&v){
        if(root){
            inorder(root->left,v);
            v.push_back(root->data);
            inorder(root->right,v);
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int>v1,v2;
       inorder(root1,v1);
       inorder(root2,v2);
       vector<int>ans;
       for(auto i:v1){
           ans.push_back(i);
       }
       for(auto i:v2){
           ans.push_back(i);
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};