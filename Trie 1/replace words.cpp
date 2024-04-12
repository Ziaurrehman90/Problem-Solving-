class TrieNode {
public:
    bool isWord;
    string data;
    TrieNode* childs[26];

    TrieNode() {
        for (auto& a: childs) a = nullptr;
        data = "";
        isWord = false;
    }
};

class Solution {
public:
    TrieNode* root;
    
    void insertWord(string word) {
        TrieNode* p = root;
        for (auto& c: word) {
            int index = c - 'a';
            if (!p -> childs[index]) 
                p -> childs[index] = new TrieNode();
            p = p -> childs[index];
        }  
        p -> data = word;
        p -> isWord = true;
    }

    TrieNode* searchWord(string word) {
        TrieNode* p = root;
        for (auto& c: word) {
            int index = c - 'a';
            if (p -> isWord) return p;
            if (!p -> childs[index]) return nullptr;
            p = p -> childs[index];
        }
        if (p -> isWord) return p;
        else return nullptr;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();

        for (string& word: dictionary) {
            insertWord(word);
        }

        vector<string> tokens;
        string word = "";
        for (char& c: sentence) {
            if (c == ' ' && word.size() > 0) {
                tokens.push_back(word);
                word = "";
            } else if (c != ' ') {
                word += c;
            }
        }
        if (word.size() > 0) tokens.push_back(word);

        string answer = "";
        for (int i = 0; i < tokens.size(); i++) {
            string word = tokens[i];
            TrieNode* found = searchWord(word);
            if (found) answer += found -> data;
            else answer += word;
            
            if (i < tokens.size() - 1) answer += ' ';
        }

        return answer;
    }
};