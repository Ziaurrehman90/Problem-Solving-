vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<vector<int>>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int>temp;
        while(n--){
            BinaryTreeNode<int> *node=q.front();
            q.pop();
            temp.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }


        }
        ans.push_back(temp);
    }
    vector<int>zia;
    for(auto it:ans){
        zia.push_back(it[0]);
    }
    return zia;
}