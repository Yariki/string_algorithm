//
// Created by Yariki on 10/8/2016.
//

#ifndef STRING_ALGORITHM_TRIE_MATHING_H
#define STRING_ALGORITHM_TRIE_MATHING_H

#include "construct_trie.h"

string  read_data(vector<string>& patterns);

vector<int> trie_matching(string& text, node* root);

int prefix_trie_matching(string& text, int startSymbolIndex, node* root);


void matching();


#endif //STRING_ALGORITHM_TRIE_MATHING_H
