#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
char str[10002];
int D[10002];
int Decision[10002][5];

int decision(int begin, int end)
{
    int& ret = Decision[begin][end-begin];
    if(ret!= -1) return ret;
    int len = end - begin + 1;
    
    bool allsame = true;
    char front = str[begin];
    for(int i = begin + 1; i <= end; i++){
        if(front != str[i]){allsame = false; break;}
    }
    if(allsame) return ret = 1;
    // bool monotonic = true;
    // char dis = str[begin+1] - str[begin];
    // for(int i = begin + 2; i <= end; i++){
    //     if(dis != str[i] - str[i-1]){monotonic = false; break;}
    // }
    bool sameDif = true;
    for(int i = begin; i <= end - 2; i++){
        if(str[begin+1]-str[begin] != str[begin+2]-str[begin+1]){sameDif = false; break;}
    }
    if(sameDif && abs(str[begin+1] - str[begin]) == 1) return ret = 2;
    bool switching = true;
    char second = str[begin+1];
    for(int i = 2; i < len; i++){
        if(i%2==0){
            if(front != str[begin+i]){
                switching = false;
                break;
            }
        }
        if(i%2!=0){
            if(second != str[begin+i]){
                switching = false;
                break;
            }
        }
    }
    if(switching) return ret = 4;
    if(sameDif) return ret = 5;
    return ret = 10;
}
int dp(int begin)
{
    if(begin == strlen(str)) return 0;
    int& ret = D[begin];
    if(ret != -1) return ret;

    ret = INF;

    for(int L = 3; L <= 5; L++){
        if(begin + L <= strlen(str)){
            ret = min(ret, dp(begin+L) + decision(begin, begin+L-1));
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; 
    cin >> t;
    while(t--){
        cin >> str;
        memset(D, -1, sizeof(D));
        memset(Decision, -1, sizeof(Decision));
        //strlen(str)
        cout << dp(0) << '\n';
    }
    return 0;
}