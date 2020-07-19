#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool descending (char a, char b){
    return a > b;
}

string solution(string s) {
    string answer = s;
    sort(answer.begin(), answer.end(), descending);
    return answer;
}