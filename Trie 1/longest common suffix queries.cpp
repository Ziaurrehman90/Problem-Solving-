class TrieNode {
public:
    int bestIdx = 0;
    TrieNode *children[26];
};
class Solution {
    void insert(TrieNode *root, int i, vector<string>& wordsContainer) {
        TrieNode* curr = root;
        if(wordsContainer[i].length() < wordsContainer[curr -> bestIdx].length()) curr -> bestIdx = i;
        for(int j = wordsContainer[i].length() - 1; j >= 0; j--) {
            int ch = wordsContainer[i][j] - 'a';
            if(curr -> children[ch] == nullptr) {
                curr -> children[ch] = new TrieNode(i);
            } 
            curr = curr -> children[ch];
            if(wordsContainer[i].length() < wordsContainer[curr -> bestIdx].length()) curr -> bestIdx = i;
        }
    }
    int search(TrieNode *root, string &word) {
        TrieNode* curr = root;
        for(int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if(curr -> children[ch] == nullptr) {
                return curr -> bestIdx;
            } 
            curr = curr -> children[ch];
        }
        return curr -> bestIdx;
    }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode *root = new TrieNode(0);
        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(root, i, wordsContainer);
        }
        vector<int> ans;
        for(int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(search(root, wordsQuery[i]));
        }
        return ans;
    }
};