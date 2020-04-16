#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[8] = {2,1,2,1,-2,-1,-2,-1};
int dy[8] = {1,2,-1,-2,1,2,-1,-2};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int l, cur_x, cur_y, des_x, des_y;
        cin >> l >> cur_x >> cur_y >> des_x >> des_y;
        int check[301][301];
        bool v[301][301];
        for(int i = 0; i < 301; i++){
            for(int j = 0; j < 301; j++){
                check[i][j] = 0;
                v[i][j] = false;
            }
        }
        queue<pair<int, int> > q;
        q.push(make_pair(cur_x, cur_y));
        v[cur_x][cur_y] = true;
        while(!q.empty()){
            int t = q.front().first;
            int s = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i++){
                int xn = t + dx[i];
                int yn = s + dy[i];
                if(xn >= 0 && xn < l && yn >= 0 && yn < l){
                    if(!v[xn][yn]){
                        q.push(make_pair(xn, yn));
                        v[xn][yn] = true;
                        check[xn][yn] = check[t][s] + 1;
                    }
                }
            }
        }
        cout << check[des_x][des_y] << '\n';
    }
    return 0;
}