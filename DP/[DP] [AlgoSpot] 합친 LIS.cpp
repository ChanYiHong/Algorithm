#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int arr1[101];
int arr2[101];
int D[101][101];
const long long NEGINF = numeric_limits<long long>::min();
int jlis(int index1, int index2)
{
    int& ret = D[index1+1][index2+1];
    if(ret != -1) return ret;
    ret = 2;

    long long a = (index1 == -1 ? NEGINF : arr1[index1]);
    long long b = (index2 == -1 ? NEGINF : arr2[index2]);
    long long maxElement = max(a, b);
    for(int next1 = index1 + 1; next1 < n; next1++){
        if(arr1[next1] > maxElement){
            ret = max(ret, jlis(next1, index2) + 1);
        }
    }
    for(int next2 = index2 + 1; next2 < m; next2++){
        if(arr2[next2] > maxElement){
            ret = max(ret, jlis(index1, next2) + 1);
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
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> arr1[i];
        }
        for(int i = 0; i < m; i++){
            cin >> arr2[i];
        }
        memset(D, -1, sizeof(D));
        int res = jlis(0, 0);
        cout << res << '\n';
    }
    return 0;
}