#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    while(1)
    {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        int check[50][50] = {0,};
        int arr[50][50];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        
        int number = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1 && check[i][j] == 0){
                    queue<pair<int, int> > q;
                    q.push(make_pair(i,j));
                    check[i][j] = 1;
                    while(!q.empty()){
                        int t = q.front().first;
                        int s = q.front().second;
                        q.pop();
                        for(int k = 0; k < 8; k++){
                            int xn = t + dx[k];
                            int yn = s + dy[k];
                            if(xn >= 0 && xn < m && yn >= 0 && yn < n){
                                if(arr[xn][yn] == 1 && check[xn][yn] == 0){
                                    check[xn][yn] = 1;
                                    q.push(make_pair(xn,yn));
                                }
                            }
                        }
                    }
                    number++;  
                }
            }
        }
        cout << number << '\n';
    }

    return 0;
}