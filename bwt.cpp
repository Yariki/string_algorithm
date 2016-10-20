//
// Created by Yariki on 10/14/2016.
//

#include "bwt.h"


string read_input_bwt_data(string filename){
    string result = "";
    ifstream file(filename);
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

string INVERSE_BWT(const string& text){

    vector<string> last_column;
    int count = text.size() - 1;

    for (int i = 0; i < text.size(); ++i) {
        last_column.push_back(string(1,text.at(i)));
    }
    vector<string> first_col = last_column;
    sort(first_col.begin(),first_col.end());
    for (int j = 0; j < count; ++j) {
        vector<string> merged;
        for (int i = 0; i < first_col.size(); ++i) {
            merged.push_back(last_column.at(i) + first_col.at(i));
        }
        sort(merged.begin(),merged.end());
        first_col = merged;
    }
    string first = first_col.at(0);
    char front = first.front();
    first = first.substr(1,first.size()-1);
    first.push_back(front);

    return first;
}

void test_btw(){
    string text = read_input_bwt_data("sample3_btw");
    cout << BWT(text) << '\n';
}

void test_InverseBtw(){
    string bwt = read_input_bwt_data("sample2_RBTW");
    string result = INVERSE_BWT(bwt);

    for(auto ch : result){
        cout << ch << "\n";
    }
}