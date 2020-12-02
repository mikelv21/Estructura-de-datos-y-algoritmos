// =========================================================
// File:   main.cpp
// Author: José Miguel Luna Vega
// Date:   02/12/2020
// =========================================================

#include<iostream>
#include<map>
#include<sstream>
using namespace std;

int main() {

  map<string,string> dictionary;
  string english_word, foreign_word, line, search;

  while(getline(cin, line))  {
    if(line=="")  break;
    istringstream words(line);
    words >> english_word >> foreign_word;
    dictionary[foreign_word] = english_word;
  }

  while(cin >> search){
    if(dictionary[search].empty()){
      cout<<"eh"<<endl;
    }
    else{
      cout<<dictionary[search]<<endl;
    }
  }

  return 0;
}
