// 208. Implement Trie (Prefix Tree).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
// C++
class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;

        for (TrieNode*& curr : children) {
            curr = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        TrieNode* currNode = root;

        for (char currChar : word) {
            int idx = currChar - 'a';

            if (currNode->children[idx] == nullptr) {
                currNode->children[idx] = new TrieNode();
            }

            currNode = currNode->children[idx];
        }

        currNode->endOfWord = true;
    }

    bool search(std::string word) {
        TrieNode* currNode = root;

        for (char currChar : word) {
            int idx = currChar - 'a';

            if (currNode->children[idx] == nullptr) {
                return false;
            }

            currNode = currNode->children[idx];
        }

        return currNode->endOfWord;
    }

    bool startsWith(std::string prefix) {
        TrieNode* currNode = root;

        for (char currChar : prefix) {
            int idx = currChar - 'a';

            if (currNode->children[idx] == nullptr) {
                return false;
            }

            currNode = currNode->children[idx];
        }

        return true;
    }
};
int main()
{
    Trie t;
    t.insert("apl");
    t.insert("app");
    t.insert("apps");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
