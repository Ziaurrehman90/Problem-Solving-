class Solution {
public:
    struct Trie{
        Trie*next[26];
        int freq;
        Trie(){
            freq=0;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    Trie *root;
    void insert(string s){
        int n = s.size();
        Trie*temp = root;
        for(int i=0;i<n;i++){
            if(temp->next[s[i]-'a']==NULL){
                temp->next[s[i]-'a'] = new Trie();
            }
            temp = temp->next[s[i]-'a'];
            temp->freq++;
        }
    }
    int getAns(string s){
        int ans = 0;
        int n = s.size();
        Trie*temp = root;
        for(int i=0;i<n;i++){
            temp = temp->next[s[i]-'a'];
            ans+=temp->freq;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new Trie();
        for(auto it:words){
            insert(it);
        }
        vector<int>ans;
        for(auto it:words){
            ans.push_back(getAns(it));
        }
        return ans;
    }
};