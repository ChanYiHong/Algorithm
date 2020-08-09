#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
//int N;
vector<int> D;

// int dp(int position, int cost){
    
//     cout << "P : " << position << " C : " << cost << '\n';
    
//     int& ret = D[position];
//     cout << "D[" << position << "] = " << ret << '\n'; 
    
//     if(position == N){
//         ret = min(ret, cost);
//         return ret;
//     }
//     if(ret != INF){
//         ret = min(ret, cost);
//         return ret;
//     }

//     int ret1 = dp(position + 1, cost + 1);
//     ret = min(ret, ret1);

//     if(position * 2 <= N && position != 0){
//         int ret2 = dp(position * 2, cost);
//         ret = min(ret, ret2);
//     }
    
//     return ret;
// }

// 웅아의 DP
// D[n] = min(D[n-1] + 1, D[n/2])
// 단 n 이 2로 나누어 떨어질 경우만.. 안나눠 떨어지면 n-1만
// 그리고 메모이제이션까지 적용


int dp(int position){
    
    if(position == 1){
        return 1;
    }
    
    int& ret = D[position];
    
    if(ret != INF){
        return ret;
    }
    
    ret = min(ret, dp(position-1) + 1);
    
    if(position % 2 == 0){
        ret = min(ret, dp(position/2));
    }
    
    return ret;
    
}
    
int solution(int n)
{
    int ans = 0;
    //N = n;
    //D.resize(n+1, INF);
    //ans = dp(n);
    while(n!=0){
        if(n%2 == 0){
            n/=2;
        }
        else{
            n--;
            ans++;
        }
    }
    
    return ans;
}