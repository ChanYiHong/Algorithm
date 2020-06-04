#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n+1);
    arr.push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    //bool D[2001][2001];
    vector<vector<bool> > D(2001, vector<bool>(2001));
    for(int i = n; i > 0; i--){
        for(int j = i; j <= n; j++){
            if(i == j) D[i][j] = 1;
            else if(i == j-1 && arr[i] == arr[j]) D[i][j] = 1;
            else if(D[i+1][j-1] == 1 && arr[i] == arr[j]) D[i][j] = 1;
        }
    }
    int k;
    cin >> k;
    while(k--){
        int x, y;
        cin >> x >> y;
        cout << D[x][y] << '\n';  
    }

    return 0;
}
