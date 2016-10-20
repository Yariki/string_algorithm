//
// Created by Yariki on 10/21/2016.
//

#include "kmp.h"


vector<string> read_kmp_data(string filename){
    string temp;
    vector<string> result;
    ifstream file(filename);
    if(file.is_open()){
        getline(file,temp);
        result.push_back(temp);
        getline(file,temp);
        result.push_back(temp);
        file.close();
    }
    return result;
}

vector<int> compute_prefix_function(const string& text){
    vector<int> s(text.size());
    s[0] = 0;
    int border = 0;
    int len = text.size();
    for (int i = 1; i < len; ++i) {
        while(border > 0 && text[i] != text[border]){
            border = s[border - 1];
        }
        if(text[i] == text[border]){
            border = border + 1;
        }else{
            border = 0;
        }
        s[i] = border;
    }
    return s;
}

vector<int> compute_kmp(int prefixLen,const vector<int>& prefixResult){
    vector<int> result;
    for (int i = prefixLen + 1; i < prefixResult.size(); ++i) {
        if(prefixResult[i] == prefixLen){
            result.push_back(i - (2 * prefixLen));
        }
    }
    return result;
}

void test_kmp(){
    auto data = read_kmp_data("sample3_kmp");
    if(data.size() > 1){
        string text = data.at(0) + "$" + data.at(1);
        auto prefixResult = compute_prefix_function(text);
        auto kmpResult = compute_kmp(data.at(0).size(),prefixResult);

        for (auto pos : kmpResult) {
            cout << pos << " ";
        }
        cout << "\n";
    }
}


