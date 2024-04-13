#include <iostream>
#include <vector>

class TrieNode {
public:
    std::vector<TrieNode*> children;
    int zeroCount, oneCount;
    TrieNode() : children(2, nullptr), zeroCount(0), oneCount(0) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {}

    void insert(int value) {
        TrieNode* currentNode = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (value & (1 << i)) > 0 ? 1 : 0;
            if (currentNode->children[bit] == nullptr) {
                currentNode->children[bit] = new TrieNode();
            }
            currentNode = currentNode->children[bit];
            if (bit == 1) {
                currentNode->oneCount++;
            } else {
                currentNode->zeroCount++;
            }
        }
    }

    long long countSubarraysWithMaxXor(int xorValue, int limit) {
        TrieNode* currentNode = root;
        long long totalCount = 0;
        if (currentNode == nullptr) {
            return totalCount;
        }
        for (int i = 31; i >= 0; i--) {
            int limitBit = (limit & (1 << i)) > 0 ? 1 : 0;
            int xorBit = (xorValue & (1 << i)) > 0 ? 1 : 0;
            if (limitBit == 1) {
                if (xorBit == 1) {
                    if (currentNode->children[1] != nullptr)
                        totalCount += currentNode->children[1]->oneCount;
                    if (currentNode->children[0] == nullptr)
                        return totalCount;
                    currentNode = currentNode->children[0];
                } else {
                    if (currentNode->children[0] != nullptr)
                        totalCount += currentNode->children[0]->zeroCount;
                    if (currentNode->children[1] == nullptr)
                        return totalCount;
                    currentNode = currentNode->children[1];
                }
            } else {
                if (xorBit == 1) {
                    if (currentNode->children[1] == nullptr)
                        return totalCount;
                    currentNode = currentNode->children[1];
                } else {
                    if (currentNode->children[0] == nullptr)
                        return totalCount;
                    currentNode = currentNode->children[0];
                }
            }
        }

        return totalCount;
    }
};

int main() {
    int testCaseCount;
    std::cin >> testCaseCount;

    while (testCaseCount--) {
        int arraySize, maxAllowedXor;
        std::cin >> arraySize >> maxAllowedXor;
        std::vector<int> array(arraySize);
        for (int i = 0; i < arraySize; i++) {
            std::cin >> array[i];
        }

        Trie trie;
        int cumulativeXor = 0;
        long long result = 0;
        trie.insert(cumulativeXor);
        for (int element : array) {
            cumulativeXor ^= element;
            result += trie.countSubarraysWithMaxXor(cumulativeXor, maxAllowedXor);
            trie.insert(cumulativeXor);
        }
        std::cout << result << std::endl;
    }

    return 0;
}
