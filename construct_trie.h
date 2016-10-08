//
// Created by Yariki on 10/7/2016.
//

#ifndef STRING_ALGORITHM_CONSTRUCT_TRIE_H
#define STRING_ALGORITHM_CONSTRUCT_TRIE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

using std::vector;
using std::string;

struct edge;

struct node{

public:
    node(int i){
        index = i;
    }
    int index;
    vector<edge> edges;

    bool is_leaf(){return edges.empty();}
};

struct edge {
public:
    edge(char ch, node* next){
        symbol = ch;
        nextNode = next;
    }
    char symbol;
    node* nextNode;
};

edge* is_there_edge(node* node, char symbol);

node* build_trie(vector<string> & patterns);

vector<string> read_patterns();

void construct_trie();

void print_tree(node* root);

void clean_up(node* root);




#endif //STRING_ALGORITHM_CONSTRUCT_TRIE_H
