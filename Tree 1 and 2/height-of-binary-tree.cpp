/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int left=1+height(root->left);
    int right=1+height(root->right);
    return max(left,right);
}
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    return height(root);

}
