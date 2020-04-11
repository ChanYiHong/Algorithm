#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int s[20][20];
int go(vector<int> &first, vector<int> &second, int index)
{
    // 중단 조건
    if(index == n){
        if(first.size() > n/2) return -1;
        if(second.size() > n/2) return -1;
        int start = 0;
        int link = 0;
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                if(i == j) continue;
                start += s[first[i]][first[j]];
                link += s[second[i]][second[j]];
            }
        }
        int dif = start - link;
        if(dif < 0) dif = -dif;
        return dif;
    }
    // 안되는 조건
    // 다음으로 가는 조건
    int answer = -1;
    first.push_back(index);
    int start = go(first, second, index+1);
    if(answer == -1){
        answer = start;
    }
    first.pop_back();
    second.push_back(index);
    int link = go(first, second, index+1);
    if(answer == -1 || (link != -1 && answer > link)){
        answer = link;
    }
    second.pop_back();

    return answer;
    // So cute >, <
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    vector<int> first, second;
    cout << go(first, second, 0);

    return 0;
}