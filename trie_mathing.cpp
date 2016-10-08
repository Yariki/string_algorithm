//
// Created by Yariki on 10/8/2016.
//

#include "trie_mathing.h"

string read_data(vector<string>& patterns){
    string text;
    string count;
    ifstream file("sample3");
    if(file.is_open()){
        getline(file,text);
        getline(file,count);
        string line;
        while(getline(file,line)){
            patterns.push_back(line);
        }
    }
    return text;
}

int prefix_trie_matching(string& text, int startSymbolIndex, node* root){
    node* currentNode= root;
    int initIndex = startSymbolIndex;
    char currentSymbol = text.at(initIndex);

    edge* foundEdge = nullptr;
    while(true){
        if(currentNode->is_leaf()){
            return initIndex;
        } else if((foundEdge = is_there_edge(currentNode,currentSymbol)) != nullptr){
            currentNode = foundEdge->nextNode;
            currentSymbol = (++startSymbolIndex < text.size()) ?  text.at(startSymbolIndex) : '\0';
            foundEdge = nullptr;
        } else{
            return -1;
        }
    }
}

vector<int> trie_matching(string& text, node* root){
    vector<int> results;
    for (int i = 0; i < text.size(); ++i) {
        auto result = prefix_trie_matching(text,i,root);
        if(result > -1){
            results.push_back(result);
        }
    }
    return results;
}

void matching(){
    vector<string> patterns;
    string text = read_data(patterns);
    node* root_trie = build_trie(patterns);
    auto results = trie_matching(text,root_trie);

    for (int i = 0; i < results.size(); ++i) {
        cout << results.at(i) << "\n";
    }

    clean_up(root_trie);
}