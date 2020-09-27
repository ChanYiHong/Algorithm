#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    map<string, int> m;
    
    for(int i = 0; i < phone_book.size(); i++){
        m[phone_book[i]]++;
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        for(int j = 0; j < phone_book[i].length()-1; j++){
            string cur = phone_book[i].substr(0, j+1);
            if(m[cur] > 0){
                return false;
            }
        }
    }
    
    return answer;
}