//
// Created by Yariki on 10/21/2016.
//

#ifndef STRING_ALGORITHM_KMP_H
#define STRING_ALGORITHM_KMP_H



#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


vector<string> read_kmp_data(string filename) ;

vector<int> compute_prefix_function(const string& text);

vector<int> compute_kmp(int prefixLen,const vector<int>& prefixResult);

void test_kmp();


#endif //STRING_ALGORITHM_KMP_H
