#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int D[1001];
int arr[1001];

int dp(int index)
{
    int& ret = D[index+1];
    if(ret!=-1) return ret;

    ret = 1;
    for(int next = index + 1; next < n; next++){
        if(index == -1 || arr[index] < arr[next]){
            ret = max(ret, dp(next) + 1);
        }
    }
    return ret;
}

int main()
{
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(D, -1, sizeof(D));
    cout << dp(-1)-1;
    return 0;
}