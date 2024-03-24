/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // base case 
        if(root==NULL){
            return "NULL,";
        }
        // now can apply normal preorder traveesal 
        string ans="";
        ans+=to_string(root->val);
        ans+=",";
        ans+=serialize(root->left);
        ans+=serialize(root->right);
        return ans;

        

        
    }

    // Decodes your encoded data to tree.
    TreeNode *fun(queue<string>&q){
        string temp=q.front();
        q.pop();
        if(temp=="NULL"){
            return NULL;
        }
        TreeNode *root=new TreeNode(stoi(temp));
        root->left=fun(q);
        root->right=fun(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        
        queue<string>q;
        string temp="";
        for(char c:data){
            if(c==','){
            q.push(temp);
            temp="";
            continue;
            }
            temp+=c;
        }
        if(temp.size()!=0){
            q.push(temp);
        }
        return fun(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));