class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> freqs;
};

class AutocompleteSystem {
private:
    TrieNode* root;
    TrieNode* curr;
    string currQuery;

    static bool compareFreq(pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        curr = root;
        currQuery = "";

        for (int i = 0; i < sentences.size(); ++i) {
            insertSentence(sentences[i], times[i]);
        }
    }

    void insertSentence(string sentence, int time) {
        TrieNode* node = root;
        for (char ch : sentence) {
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->freqs[sentence] += time;
        }
    }

    vector<string> inputChar(char c) {
        if (c == '#') {
            insertSentence(currQuery, 1);
            currQuery = "";
            curr = root;
            return {};
        }

        currQuery += c;
        if (!curr->children[c]) {
            curr->children[c] = new TrieNode();
            curr = curr->children[c];
            return {};
        }

        curr = curr->children[c];
        vector<pair<string, int>> suggestions(curr->freqs.begin(), curr->freqs.end());
        sort(suggestions.begin(), suggestions.end(), compareFreq);

        vector<string> res;
        for (int i = 0; i < min(3, (int)suggestions.size()); ++i) {
            res.push_back(suggestions[i].first);
        }

        return res;
    }
};
