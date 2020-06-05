#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<vector<long double> > arr;
long double makePath(vector<bool>& path, long double length, int before)
{
    int finish = -1;
    for(int i = 0; i < n; i++){
        if(!path[i]) {finish = i; break;}
    }
    if(finish == -1){
        return length;
    }
    long double ret = 987654321.0;
    for(int j = 0; j < n; j++){
        if(path[j]) continue;
        path[j] = true;
        long double dis = arr[before][j];
        ret = min(ret, makePath(path, length + dis, j));
        path[j] = false;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        arr.resize(n, vector<long double>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        vector<bool> path;
        long double res = 987654321.0;
        for(int i = 0; i < n; i++){
            path.resize(n, false);
            path[i] = true;
            res = min(res, makePath(path, 0.0, i));
            path.clear();
        }
        cout.precision(14);
        cout << res << '\n';
        arr.clear();
    }
    return 0;
}