#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int idx = 0;
int white[1002], black[1002];
int dp[1002][16][16];

int napsack(int w, int b, int now)
{
    if(now == idx) return 0;

    int &ret = dp[now][w][b];

    if(ret != -1) return ret;

    if(w > 0) ret = max(ret, napsack(w - 1, b, now + 1) + white[now]);

    if(b > 0) ret = max(ret, napsack(w, b - 1, now + 1) + black[now]);

    ret = max(ret, napsack(w, b, now + 1));

    return ret;
}

// bool descending(const pair<int, int> a, const pair<int, int> b){
//     return a.first > b.first;
// }

int main()
{
    memset(dp, -1, sizeof(dp));

    int w, b;
    while(scanf("%d %d", &w, &b) != EOF)
    {
        white[idx] = w;
        black[idx++] = b;
    }
    cout << napsack(15, 15, 0);

    // int n =31;
    // vector<pair<int, int> > white, black;
    // for(int i = 0; i < n; i++){
    //     int num, num2;
    //     cin >> num >> num2;
    //     white.push_back(make_pair(num, i));
    //     black.push_back(make_pair(num2, i));
    // }
    // sort(white.begin(), white.end(), descending);
    // sort(black.begin(), black.end(), descending);

    // for(int i = 0; i < n; i++){
    //     cout << "( " << white[i].first << " " << white[i].second << " )";
    //     cout << "   ";
    //     cout << "( " << black[i].first << " " << black[i].second << " )" << '\n';
    // }

    // int k = n-1;

    // // 이미 가봤던 점인지 체크
    // bool check[n];
    // // 개수 세기. n/2 부터 시작해서 하나씩 줄여나가다가 0되면
    // // 해당색은 끝난 것
    // int w =15, b = 15;
    // // 흰색, 검정색 각각 벡터의 인덱스. 정렬해놔서 젤 큰게 먼저나옴
    // int w_index = 0, b_index = 0;
    // // 정답 저장. 다 합칠거
    // int answer = 0;
    // // 개수가 다 꽉차면 끝
    // while(k>=0){
    //     if(white[w_index].first > black[b_index].first || b == 0){
    //         if(!check[white[w_index].second]){
    //             check[white[w_index].second] = true;
    //             answer += white[w_index].first;
    //             w_index++;
    //             w--;
    //         }
    //         else{
    //             w_index++;
    //         }
    //     }
    //     else{
    //         if(!check[black[b_index].second] || w == 0){
    //             check[black[b_index].second] = true;
    //             answer += black[b_index].first;
    //             b_index++;
    //             b--;
    //         } 
    //         else{
    //             b_index++;
    //         }
    //     }
    //     k--;
    //     if(w == 0 && b == 0) break;
    // }

    // cout << answer;
    return 0;
}




