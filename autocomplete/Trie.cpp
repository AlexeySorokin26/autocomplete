#include "Trie.h"

TrieNode* getNewNode() {

    TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, const std::string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool search(TrieNode* root, std::string key) {

    TrieNode* node = root;
    for (int i = 0; i < key.length(); ++i) {

        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

bool isLastNode(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

void suggestionsRec(struct TrieNode* root, std::string currPrefix, std::vector<std::string>& res) {
    if (root->isEndOfWord) 
        res.push_back(currPrefix);

    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            currPrefix.push_back(97 + i);
            suggestionsRec(root->children[i], currPrefix, res);
            currPrefix.pop_back();
        }
    }
}

AutoSuggestion getAutoSuggestions(TrieNode* root, const std::string query, std::vector<std::string>& res) {
    
    TrieNode* current = root;

    for (int i = 0; i < query.length(); ++i) {
        int index = query[i] - 'a';

        if (!current->children[index])
            return AutoSuggestion::NO_SUGGESTIONS_IN_DIC;

        current = current->children[index];
    }

    bool isWord = (current->isEndOfWord == true);

    bool isLast = isLastNode(current);

    if (isWord && isLast) 
        return AutoSuggestion::ONLY_THE_SAME_STRING_IN_DIC;
    
    if (!isLast) {
        std::string prefix = query;
        suggestionsRec(current, prefix, res);
        return AutoSuggestion::HAVE_SUGGESIONS_IN_DIC;
    }
}

void printAutoSuggestions(std::vector<std::string> res) {
    std::cout << "--------------------------" << std::endl;
    std::cout << "suggestions: " << std::endl;
    for (int i = 0; i < res.size(); ++i)
        std::cout << res[i] << std::endl;
}