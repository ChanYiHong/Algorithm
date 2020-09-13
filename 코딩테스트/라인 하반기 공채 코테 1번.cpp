#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> B;
int answer = 0;

void switchThings(int index){
    
    if(index == B.size()) return;
    
    if(B[index][0] == B[index][1]){
        switchThings(index+1);
        return;
    }
    
    for(int i = index + 1; i < B.size(); i++){
        if(B[i][0] == B[index][0]){
            swap(B[i][0], B[index][1]);
            switchThings(index+1);
            return;
        }
        if(B[i][1] == B[index][0]){
            swap(B[i][1], B[index][1]);
            switchThings(index+1);
            return;
        }
        if(B[i][0] == B[index][1]){
            swap(B[i][0], B[index][0]);
            switchThings(index+1);
            return;
        }
        if(B[i][1] == B[index][1]){
            swap(B[i][1], B[index][0]);
            switchThings(index+1);
            return;
        }
    }
}

void addThings(){
    for(int i = 0; i < B.size(); i++){
        if(B[i][0] != B[i][1]){
            answer++;
        }
    }
}

int solution(vector<vector<int>> boxes) {
    
    B = boxes;
    
    sort(B.begin(), B.end());
    for(int i = 0; i < B.size(); i++){
        sort(B[i].begin(), B[i].end());
    }
    
    switchThings(0);
    
    addThings();
    
    return answer;
}