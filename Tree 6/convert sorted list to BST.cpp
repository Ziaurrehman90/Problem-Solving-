

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode *func(int start,int end,vector<int>&ans){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode *node=new TreeNode(ans[mid],func(start,mid-1,ans),func(mid+1,end,ans));
    return node;
  
}
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
        ListNode *temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        return func(0,ans.size()-1,ans);
       
       
        
    }
};