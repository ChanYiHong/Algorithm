#include <string>
#include <vector>
#include <algorithm>

bool descending(int a, int b){
    return a > b;
}

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> arr2 = arr;
    sort(arr.begin(), arr.end(), descending);
    int del = arr[arr.size()-1];
    for(int i = 0; i < arr2.size(); i++){
        if(del == arr2[i]) continue;
        answer.push_back(arr2[i]);
    }
    if(answer.size()==0){
        answer.push_back(-1);
        return answer;
    }
    return answer;
}

// int num = *minelement(arr.begin(), arr.end());
// int pos = find(arr.begin(), arr.end(), num) - arr.begin();
// arr.erase(arr.begin() + pos);

// return arr.empty() ? vector<int>(1, -1) : arr;