#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define INF 987654321
int N, _min=INF;
vector<int> A,D;
int GO(int now){
    //마지막에 정확히 도착
    if(now==N){
        return 0;
    }
    if(now>N){
        return INF;
    }
    //Cache
    if(D[now]!=-1) return D[now];

    D[now] = INF;
    for(int i=1; i<=A[now]; i++){
        D[now] = min(D[now], GO(now+i) + 1);
    }
    return D[now];
}

int main(){
    cin>>N;
    A.resize(N+1);
    D.resize(N+1,-1);
    for(int i=1; i<=N; i++){
        cin>>A[i];
    }

    int res = GO(1);
    if(res==INF){cout<<"-1";}
    else { cout<<res;};
    return 0;
}