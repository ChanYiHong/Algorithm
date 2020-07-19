#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> index;
    for(string str : strings){
        index.push_back({str[n], str});
    }
    sort(index.begin(), index.end());
    for(int i = 0; i < index.size(); i++){
        answer.push_back(index[i].second);
    }
    return answer;
}