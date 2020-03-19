#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int tri[501][501];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int num;
            cin >> num;
            tri[i][j] = num;
        }
    }
    long long D[501][501];
    D[1][1] = tri[1][1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            D[i][j] = 0;
            if(j == 1) D[i][j] += D[i-1][j] + tri[i][j];
            else if(j == i) D[i][j] += D[i-1][j-1] + tri[i][j];
            else D[i][j] += max(D[i-1][j-1], D[i-1][j]) + tri[i][j];
        }
    }
    long long max = 0;
    for(int i = 1; i <=n; i++){
        if(max < D[n][i]) max = D[n][i];
    }
    cout << max;
    return 0;
}

// 2차원 배열 DP
// tri에 삼각형에 있는 정수들 저장.
// 맨 초기값, 즉, 맨 위층 값 D[1][1] = tri[1][1]로 초기화
// 그 후에 밑에 층으로 가는데 맨 왼쪽하고 맨 오른쪽은 어짜피 한쪽 길밖에 없으니 그대로 더해주고,
// 중간 값들은 더 큰거를 더해줌
// 연산 다 끝나고 D[n][?] 에 있는 것들 중에 최대값이 답임.