int helper(Node *root,int input){
    if(root==NULL){
        return -1;
    }
    int ans=1e9;
    while(root!=NULL){
        if(root->data==input){
            return root->data;
        }
        else if(root->data<input){
            root=root->right;
        }
        else{
            ans=min(ans,root->data);
            root=root->left;
        }
    }
    if(ans==1e9){
        return -1;
    }
    return ans;
   
    
   
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
        
    // Your code here
    return helper(root,input);
}