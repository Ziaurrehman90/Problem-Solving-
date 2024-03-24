class Solution {
  public:
   vector<vector<int>>vertical_orderTraversal(Node *root){
        vector<vector<int>>ans;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,vector<int>>>mp;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto it=q.front();
                q.pop();
                Node *node=it.first;
                int vert=it.second.first;
                int level=it.second.second;
                mp[vert][level].push_back(node->data);
                if(node->left){
                    q.push({node->left,{vert-1,level+1}});
                }
                if(node->right){
                    q.push({node->right,{vert+1,level+1}});
                }
            }
        }
        for(auto &it:mp){
            vector<int>temp;
            for(auto &i:it.second){
                for(auto &j:i.second){
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
         vector<vector<int>>ans=vertical_orderTraversal(root);
        vector<int>zia;
        for(int i=0;i<ans.size();i++){
            vector<int>temp=ans[i];
            zia.push_back(temp[temp.size()-1]);
        }
        return zia;
    }
    
};