class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
      Node *head=NULL;Node *prev=NULL;
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        if(head==NULL){
            head=prev=root;
        }
        else{
            prev->right =root;
            root->left = prev;
        }
        prev= root;
        inorder(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
    inorder(root);
       head->left = prev;
       prev->right = head;
       return head;
    
    }
}