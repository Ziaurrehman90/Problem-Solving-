class TrieNode {
    public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i=0; i<26; i++){
            this->children[i] = NULL;
        }
        this->isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        TrieNode* p = new TrieNode();
        this->root = p;    
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            int idx = word[i]-'a';
            if(!temp->children[idx]){
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;

        for(int i=0; i<word.length(); i++){
            int idx = word[i]-'a';
            if(!temp->children[idx]) return false;
            temp = temp->children[idx];
        }

        return (temp->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for(int i=0; i<prefix.length(); i++){
            int idx = prefix[i]-'a';
            if(!temp->children[idx]) return false;
            temp = temp->children[idx];
        }

        return true;
    }
};
