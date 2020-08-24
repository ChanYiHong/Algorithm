#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > num;
vector<int> check;
int ans = 0;
int cnt = 0;

void dfs(int x){

    if(check[x] != -1){
        ans++;
        return;
    }

    check[x] = cnt;
    cnt++;

    for(int i = 0; i < num[x].size(); i++){

        int next = num[x][i];
        dfs(next);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        num.resize(n+1, vector<int>());
        check.resize(n+1, -1);

        for(int i = 1; i <= n; i++){
            int temp; cin >> temp;
            num[i].push_back(temp);
        }


        for(int i = 1; i <= n; i++){
            if(check[i] == -1){
                dfs(i);
            }
        }

        cout << ans << '\n';
        ans = 0;
        cnt = 0;
        num.clear();
        check.clear();
    }

    return 0;
}