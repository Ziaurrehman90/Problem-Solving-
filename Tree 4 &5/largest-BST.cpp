// lets implement a class for min, max value 
class TreeNode{
    public:
    int min_node,max_node;
    int max_size;
    TreeNode(int mini, int maxi, int max_s){
        this->min_node=mini;
        this->max_node=maxi;
        this->max_size=max_s;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    // can I do it? by firstly checking each subtree as a BST !! like valid BST 
    // if it found , we can now count the number of nodes in the treee
    // void  preorder(Node *root,){
    //     vector<int>ans;
    //     if(root){
            
    //         ans.push_back(root->data);
    //         preorder(root->left);
    //         preorder(root->right);
            
    //     }
    // }
    // bool left_sub(Node *root,int num){
    //     if(root==nullptr){
    //         return true;
    //     }
    //     if(root->data>num && left_sub(root->left,num) && left_sub(root->right,num) ){
    //         return true;
    //     }
    //     return false;
    // }
    // bool right_sub(Node *root,int num){
    //     if(root==nullptr){
    //         return true;
    //     }
    //     if(root->data<num && right_sub(root->left,num) && right_sub(root->right,num) ){
    //         return true;
    //     }
    //     return false;
    // }
    
    
    // bool helper(Node *root){
    //     if(root==nullptr){
    //         return true;
    //     }
    //     if(root->left==nullptr && root->right==nullptr){
    //         return true;
    //     }
    //     if(root->left==NULL){
    //         if(root->data<root->right->data && helper(root->right) && right_sub(root->right,root->data)){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     if(root->right==NULL){
    //         if(root->data>root->left->data && helper(root->left) && left_sub(root->left,root->data)){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     if(root->left && root->right){
    //         if(root->data>root->left->data && root->data<root->right->data && helper(root->left) && helper(root->right) && left_sub(root->left,root->data) && right_sub(root->right,root->data)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    // ps: I was doing it bruteforcelly but suddenly realised the approach taught by ankan bhaiya
    // thanks bhaiya, I good approach to learn ^^
    
    TreeNode helper(Node *root){
        // base case 
        if(root==NULL){
            return TreeNode(1e9,-1e9,0);
        }
        auto left=helper(root->left);
        auto right=helper(root->right);
        // now check the condition for the BST 
        if(left.max_node<root->data && root->data<right.min_node){
            return TreeNode((min(root->data,left.min_node)),(max(root->data,right.max_node)),(1+left.max_size+right.max_size));
        }
        return TreeNode(-1e9,1e9,max(left.max_size,right.max_size));
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	return helper(root).max_size;
    	
    	
    	
    }
};