/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> res;
void left_nodes(TreeNode<int>*root){
           if(root==NULL){
               return;
           }
           if(root->left==nullptr && root->right==nullptr){
               return;
           }
           res.push_back(root->data);
           if(root->left){
                 left_nodes(root->left);
           }
           else{
                  left_nodes(root->right);    
           }
            
            
}
void right_nodes(TreeNode<int>*root){
           if(root==NULL){
               return;
           }
           if(root->left==nullptr && root->right==nullptr){
               return;
           }
          
           if(root->right){
                 right_nodes(root->right);
           }
           else{
                  right_nodes(root->left);    
           }
            res.push_back(root->data);
            
            
}
void leave_nodes(TreeNode<int>*root){

        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL)
        {
            res.push_back(root->data);
            return ;
        }
        leave_nodes(root->left);
        leave_nodes(root->right);
    }


vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    if(root==NULL) return {};
       if(root->left || root->right){
           res.push_back(root->data);
       } 
        if(root->left)   {
             left_nodes(root->left);
        } 
        leave_nodes(root);

	  if(root){
       right_nodes(root->right);
      }  

	  return res;
       
    

}
