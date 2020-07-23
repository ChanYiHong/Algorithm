#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// 10진수 -> 2진수 맵핑
// 매개변수 n : 배열 크기, arr : 10진수 저장배열, map : 2진수 맵핑 결과물
void makeBinary(int n, vector<int>& arr, vector<vector<int>>& map){
    for(int i = 0; i < n; i++){
        int decimal = arr[i];
        // 큰 2진수 부터 나눠봄
        for(int j = n-1; j >= 0; j--){
            // 0으로 못나누니 예외처리
            if(j == 0){
                if(decimal == 1) map[i].push_back(1);
                else map[i].push_back(0);
                break;
            }
            int divisor = pow(2, j);
            // 나눠지면 해당 이진수 위치가 1
            if(decimal / divisor >= 1){
                // 1을 map에 저장
                map[i].push_back(1);
                decimal -= divisor;
            }
            // 안 나눠지면 해당 이진수 위치가 0
            else{
                map[i].push_back(0);
            }
        }
    }
}

void encryptMap(int n, vector<vector<int>>& map1, vector<vector<int>>& map2, vector<string>& answer){
    for(int i = 0; i < n; i++){
        string temp = "";
        for(int j = 0; j < n; j++){
            // 하나라도 1이면 #
            if(map1[i][j] == 1 || map2[i][j] == 1){
                temp += '#';
            }
            // 이외의 경우는 다 공백
            else temp += ' ';
        }
        answer.push_back(temp);
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<vector<int>> map1(n);
    vector<vector<int>> map2(n);

    makeBinary(n, arr1, map1);
    makeBinary(n, arr2, map2);
    
    encryptMap(n, map1, map2, answer);
    

    // test
    for(int i= 0; i < map1.size(); i++){
        for(int j = 0; j < map1[i].size(); j++){
            cout << map1[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return answer;
}