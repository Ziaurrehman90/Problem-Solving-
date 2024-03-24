class Solution{
  public:
    /*You are required to complete this function*/
    // function  to calculate the sum of nodes at even levels 
    int even_sum(Node *root){
        // base case 
        if(root==NULL){
            return 0;
        }
        int sum=0;
        sum+=root->data;
        if(root->left!=NULL && root->left->left!=NULL){
            sum+=even_sum(root->left->left);
        }
        if(root->left!=NULL && root->left->right!=NULL){
            sum+=even_sum(root->left->right);
        }
        if(root->right!=NULL && root->right->right!=NULL){
            sum+=even_sum(root->right->right);
        }
        if(root->right!=NULL && root->right->left!=NULL){
            sum+=even_sum(root->right->left);
        }
        return sum;
        
    }
    int odd_sum(Node *root){
        if(root==NULL){
            return 0;
        }
        int sum=0;
        if(root->left){
            sum+=root->left->data;
        }
        if(root->right){
            sum+=root->right->data;
        }
        if(root->left!=NULL && root->left->left!=NULL){
            sum+=odd_sum(root->left->left);
        }
        if(root->left!=NULL && root->left->right!=NULL){
            sum+=odd_sum(root->left->right);
        }
        if(root->right!=NULL && root->right->right!=NULL){
            sum+=odd_sum(root->right->right);
        }
        if(root->right!=NULL && root->right->left!=NULL){
            sum+=odd_sum(root->right->left);
        }
        return sum;
        
    }
    int getLevelDiff(Node *root)
    {
       //Your code here
       int ans=even_sum(root);
       int ans1=odd_sum(root);
       return ans-ans1;
    //   return ans;
       
    }
};