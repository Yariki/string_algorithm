//
// Created by Yariki on 10/14/2016.
//

#ifndef STRING_ALGORITHM_BWT_H
#define STRING_ALGORITHM_BWT_H

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

string read_input_bwt_data(string filename);

string BWT(const string& text) ;

// relatively naive method
string INVERSE_BWT(const string& text);

// inverting with first-last property
string FL_BWT(const string& text);

void test_btw();

void test_InverseBtw();

#endif //STRING_ALGORITHM_BWT_H
