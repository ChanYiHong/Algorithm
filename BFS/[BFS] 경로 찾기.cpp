#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n][n];
    vector<vector<int> >v;
    v.resize(n, vector<int>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for(int i = 0; i < n; i++){
        sort(v[i].begin(), v[i].end());
    }
    
    int answer[n][n];
    for(int i = 0; i < n; i++){
        memset(answer[i], 0, sizeof(int)*n);
    }
    
    for(int i = 0; i < n; i++){
        bool check[n];
        memset(check, false, sizeof(bool));
        queue<int> q;
        q.push(i);

        // queue 만들기
        while(!q.empty()){
            int x = q.front();
            for(int j = 0; j < )
        }

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}