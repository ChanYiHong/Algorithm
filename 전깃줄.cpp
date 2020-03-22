#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, i, j, start, end;
    vector<pair<int, int> > ladder;
    cin >> n;
    // 쑤레기 값
    ladder.push_back(make_pair(-1, -1));
    for(i = 1; i <= n; i++){
        cin >> start;
        cin >> end;
        ladder.push_back(make_pair(start, end));
    }
    // First 소팅
    sort(ladder.begin(),ladder.end());

    // End의 가장 긴 LIS 구하기
    long long D[101];
    for(i = 1; i <= n; i++){
        D[i] = 1;
        for(j = 1; j < i; j++){
            if(ladder[i].second > ladder[j].second && D[i] < D[j] + 1){
                D[i] = D[j] + 1;
            }
        }
    }

    // n - 가장 긴 부분수열 길이가 없애야 하는 전깃줄의 최소 개수!
    long long max = 0;
    for(i = 1; i <= n; i++){
        if(max < D[i]) max = D[i];
    }
    cout << n - max;

    return 0;
}