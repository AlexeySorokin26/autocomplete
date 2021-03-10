#pragma once
#include <string>
#include <vector>
#include <iostream>

const int ALPHABET_SIZE = 26;

enum class AutoSuggestion {
    ONLY_THE_SAME_STRING_IN_DIC = -1,
    NO_SUGGESTIONS_IN_DIC = 0,
    HAVE_SUGGESIONS_IN_DIC = 1
};


struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNewNode();
void insert(TrieNode* root, const std::string key);
bool search(TrieNode* root, std::string key);
bool isLastNode(TrieNode* root);
AutoSuggestion getAutoSuggestions(TrieNode* root, const std::string query, std::vector<std::string>& res);
void suggestionsRec(struct TrieNode* root, std::string currPrefix, std::vector<std::string>& res);
void printAutoSuggestions(std::vector<std::string> res);



