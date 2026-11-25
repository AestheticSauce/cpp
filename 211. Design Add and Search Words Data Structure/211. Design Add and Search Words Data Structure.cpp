// 211. Design Add and Search Words Data Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
class node {
    
public:
    node* letters[26];
    bool EOW;

    node() {
        for (node*& letter : letters) {
            letter = nullptr;
        }
        EOW = false;
    }
    
};

class WordDictionary {
private:
    node* root;
public:
    WordDictionary() {
        root = new node();
    }

    void addWord(std::string word) {
        node* currNode = root;
        for (char a : word) {
            int idx = a - 'a';

            if (currNode->letters[idx] == nullptr) {
                currNode->letters[idx] = new node();
            }

            currNode = currNode->letters[idx];
        }

        currNode->EOW = true;
    }

    bool search(std::string word) {
        bool found = false;
        return searchHelper(word, root);
    }
    bool searchHelper(std::string word, node* itr) {
        if (word.size() == 0) {
            return itr->EOW;
        }
        if (word[0] == '.') {
            for (int i = 0; i < 26; i++) {
                if (itr->letters[i] != nullptr) {
                    bool res = searchHelper(word.substr(1, word.size()), itr->letters[i]);
                    if (res) {
                        return true;
                    }
                }
            }
            return false;
        }
        else {
           return searchHelper(word.substr(1, word.size()), itr->letters[word[0] - 'a']);
        }
    } 
};

int main()
{
    WordDictionary* dict = new WordDictionary();
    dict->addWord("ba");
    dict->addWord("bb");
    dict->addWord("bc");
    dict->addWord("bit");
    std::cout << dict->
    
}
