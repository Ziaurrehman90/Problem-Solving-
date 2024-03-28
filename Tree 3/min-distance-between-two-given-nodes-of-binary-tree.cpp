class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    // function to calculate the LCA 
    Node *LCA(Node *root, int a , int b){
        // base case 
        if(root==NULL){
            return NULL;
        }
        if(root->data==a || root->data==b){
            return root;
        }
        Node *left=LCA(root->left,a,b);
        Node *right=LCA(root->right,a,b);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        return right;
    }
    bool DFS(Node *root, int a,  vector<int>&ans){
        if(root==NULL){
            return false;
        }
        ans.push_back(root->data);
        if(root->data==a || DFS(root->left,a,ans) || DFS(root->right,a,ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node *lca=LCA(root,a,b);
        vector<int>v1;
         vector<int>v2;
        DFS(lca,a,v1);
        DFS(lca,b,v2);
        return v1.size()+v2.size()-2;
    
    }
};