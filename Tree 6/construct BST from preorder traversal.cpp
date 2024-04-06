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
TreeNode* buildTreeHelper(vector<int> & preorder,int preS,int preE, vector<int> & inorder,int inS,int inE){
    if(inS>inE){
        return NULL;
    }
    int rootdata=preorder[preS];
    int rootindex=-1;
    for(int i=inS;i<=inE;i++){
        if(inorder[i]==rootdata){
            rootindex=i;
            break;
        }
    }
    
    int lsin=inS;
    int lein=rootindex-1;
    int lspre=preS+1;
    int lepre=lein-lsin+lspre;
    int rsin=rootindex+1;
    int rein=inE;
    int rspre=lepre+1;
    int repre=preE;
TreeNode*root=new TreeNode(rootdata);
    root->left=buildTreeHelper(preorder,lspre,lepre,inorder,lsin,lein);
    root->right=buildTreeHelper(preorder,rspre,repre,inorder,rsin,rein);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       vector<int>inorder,v;
       v=preorder;
       sort(v.begin(),v.end());
       inorder=v;
       int n=preorder.size();
       int m=inorder.size();
       return buildTreeHelper(preorder,0,n-1,inorder,0,m-1);
       

        

        
    }
};