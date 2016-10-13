//
// Created by Yariki on 10/7/2016.
//

#include "construct_trie.h"


void create_new_edge(char currentSymbol, int &index, node *&currentNode);

edge * is_there_edge(node *node, char symbol){
    edge* result = nullptr;
    for (int i = 0; i < node->edges.size(); ++i) {
        if(node->edges.at(i).symbol == symbol){
            result = &(node->edges.at(i));
            break;
        }
    }
    return result;
}

node* build_trie(vector<string> & patterns){
    int index = 0;
    node* root = new node(index);
    edge* foundEdge = nullptr;
    for (int i = 0; i < patterns.size(); ++i) {
        node *currentNode = root;
        auto pattern = patterns.at(i);
        for (int j = 0; j < pattern.size(); ++j) {
            char currentSymbol = pattern.at(j);
            if(currentNode->edges.empty()){
                create_new_edge(currentSymbol, index, currentNode);
            } else if( (foundEdge = is_there_edge(currentNode,currentSymbol)) != nullptr ){
                currentNode = foundEdge->nextNode;
                foundEdge = nullptr;
            } else{
                create_new_edge(currentSymbol, index, currentNode);
            }
        }
    }
    return root;
}

void create_new_edge(char currentSymbol, int &index, node *& currentNode) {
    auto newOne = new node(++index);
    edge e(currentSymbol,newOne);
    currentNode->edges.push_back(e);
    currentNode = newOne;
}


vector<string> read_patterns(){
    string line;
    vector<string> patterns;
    ifstream file("sample3");
    if(file.is_open()){
        getline(file,line);
        while(getline(file,line)){
            patterns.push_back(line);
        }
        file.close();
    }
    return patterns;
}

void construct_trie(){

    vector<string> patterns = read_patterns();

    node* t = build_trie(patterns);

    print_tree(t);

    clean_up(t);
}

void print_tree(node* root){
    if(root == nullptr || root->is_leaf()){
        return;
    }
    for (int i = 0; i < root->edges.size(); ++i) {
        auto edge = root->edges.at(i);
        std::cout << root->index << "->" << edge.nextNode->index << ":" << edge.symbol << "\n";
        print_tree(edge.nextNode);
    }
}

void clean_up(node* root){
    if(root == nullptr){
        return;
    }
    if(root->is_leaf()){
        delete  root;
        return;
    }
    for (int i = 0; i < root->edges.size(); ++i) {
        clean_up(root->edges.at(i).nextNode);
    }
    delete root;
}