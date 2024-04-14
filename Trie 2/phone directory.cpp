#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> links;
    bool isEnd;
    std::set<std::string> stringSet;

    TrieNode() {
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links.find(ch) != links.end();
    }

    TrieNode* getNode(char ch) {
        return links[ch];
    }

    void addNode(char ch) {
        links[ch] = new TrieNode();
    }

    bool getEnd() {
        return isEnd;
    }

    void setEnd(bool value) {
        isEnd = value;
    }

    void addString(const std::string& str) {
        stringSet.insert(str);
    }

    std::vector<std::string> getStringList() {
        return std::vector<std::string>(stringSet.begin(), stringSet.end());
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insertString(const std::string& str) {
        TrieNode* temp = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (!temp->containsKey(ch)) {
                temp->addNode(ch);
            }
            temp = temp->getNode(ch);
            temp->addString(str);
        }
        temp->setEnd(true);
    }

    std::vector<std::string> searchString(const std::string& str) {
        TrieNode* temp = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (!temp->containsKey(ch)) {
                return {"0"};
            }
            temp = temp->getNode(ch);
        }
        return temp->getStringList();
    }
};

class Solution {
public:
    static std::vector<std::vector<std::string>> displayContacts(int n, std::vector<std::string>& contacts, std::string query) {
        Trie trie;
        for (const auto& contact : contacts) {
            trie.insertString(contact);
        }
        std::vector<std::vector<std::string>> result;
        for (int i = 0; i < query.length(); i++) {
            result.push_back(trie.searchString(query.substr(0, i + 1)));
        }
        return result;
    }
};
