#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 알파벳인지 아닌지 확인
bool isAlphabet(char k){
    if((k>='A' && k<='Z') || (k>='a' && k<='z')){
        return true;
    }
    return false;
}

// 소문자로 통일
char makeLowerCase(char k){
    if(k>='A' && k<='Z') k = k + ('a' - 'A');
    
    return k;
}

void makeSet(vector<string>& set, string str){
    
    char lastChar;
    for(int i = 0; i < str.length(); i++){
        if(i == 0) {lastChar = str[i]; continue;}
        
        // 둘 다 알파벳이라면
        if(isAlphabet(str[i]) && isAlphabet(lastChar)){
            // 소문자 만들기
            str[i] = makeLowerCase(str[i]);
            lastChar = makeLowerCase(lastChar);
            
            // 다중집합 원소 저장
            string savedString = "";
            savedString += lastChar;
            savedString += str[i];
            set.push_back(savedString);
        }
        
        lastChar = str[i];
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> set1;
    vector<string> set2;
    
    makeSet(set1, str1);
    makeSet(set2, str2);
    
    double uni = 0.0;
    double intersection = 0.0;
    
    for(int i = 0; i < set1.size(); i++){
        cout << set1[i] << ' ';
    }
    cout << '\n';
    
    for(int i = 0; i < set2.size(); i++){
        cout << set2[i] << ' ';
    }
    
    int size1 = set1.size();
    int size2 = set2.size();
    
    vector<bool> check1(size1, false);
    vector<bool> check2(size2, false);
    
    for(int i = 0; i < set1.size(); i++){
        for(int j = 0; j < set2.size(); j++){
            if(check1[i] == true || check2[j] == true) continue;
            if(set1[i].compare(set2[j]) == 0){
                intersection++;
                check1[i] = true;
                check2[j] = true;
                break;
            }
        }
    }
    uni = set1.size() + set2.size() - intersection;
    
    cout << intersection << ' ' << uni;
    
    if(uni != 0) answer = (intersection / uni) * 65536; 
    else if(set1.size() == 0 && set2.size() == 0) answer = 65536;
    else answer = 0;

    return answer;
}