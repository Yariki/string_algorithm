//
// Created by Yariki on 10/14/2016.
//

#include "bwt.h"


string read_input_bwt_data(){
    string result = "";
    ifstream file("sample3_bwt");
    if(file.is_open()){
        getline(file,result);
        file.close();
    }
    return result;
}


string BWT(const string& text){
    string result = "";
    string temp = text;
    vector<string> btw_matrix;
    btw_matrix.push_back(text);
    int size = temp.size() - 1;
    for (int i = 0; i < size; ++i) {
        char ch = temp.back();
        temp.pop_back();
        temp.insert(temp.begin(),ch);
        btw_matrix.push_back(temp);
    }

    sort(btw_matrix.begin(),btw_matrix.end());

    for(auto s : btw_matrix){
        result.push_back(s.back());
    }

    return result;
}

void test_btw(){
    string text = read_input_bwt_data();
    cout << BWT(text) << '\n';
}