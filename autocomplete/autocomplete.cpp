#include <iostream>
#include "Trie.h"


int main() {

    TrieNode* root = getNewNode();

    int sizeOfDic = 0;
    std::string sizeOfDicStr = "0";

    std::cout << "Input a size of your dictionary:" << std::endl;
    getline(std::cin, sizeOfDicStr);
    sizeOfDic = stoi(sizeOfDicStr);

    std::cout << "Input your dictionary:" << std::endl;
    std::string tmp = "";
    for (int i = 0; i < sizeOfDic; ++i) {
        getline(std::cin, tmp);
        insert(root, tmp);
    }
        
    std::string word = " ";
    std::vector<std::string> res;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Now we are in an autocompletion loop; to exit type 0." << std::endl;
    while (true) {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Type your word (to exit type 0): " << std::endl;
        getline(std::cin, word);
        if (word == "0") {
            break;
        }
        AutoSuggestion suggestions = getAutoSuggestions(root, word, res);
        if (suggestions == AutoSuggestion::HAVE_SUGGESIONS_IN_DIC) 
            printAutoSuggestions(res);
        else if (suggestions == AutoSuggestion::ONLY_THE_SAME_STRING_IN_DIC) {
            std::cout << "--------------------------" << std::endl;
            std::cout << "dictionary does not have other suggestion :( \n";
        }
        else {
            std::cout << "--------------------------" << std::endl;
            std::cout << "dictionary does not have any suggestion yet :( \n";
        }
    }
    

    return 0;
}

