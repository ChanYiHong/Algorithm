#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    char color[101][101];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> color[i][j];
        }
    }
    // RGB
    int yes = 0;
    bool check[101][101];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!check[i][j]){
                yes++;
                char current = color[i][j];
                queue<pair<int, int> > q;
                q.push(make_pair(i,j));
                check[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int c = 0; c < 4; c++){
                        int nx = x + dx[c];
                        int ny = y + dy[c];
                        if(nx >= 0 && nx < n && ny >=0 && ny < n){
                            if(!check[nx][ny] && current == color[nx][ny]){
                                check[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }

    // Color Blindness
    int no = 0;
    bool check2[101][101];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!check2[i][j]){
                no++;
                int current;
                if(color[i][j] == 'B') current = 1;
                else current = 2;
                queue<pair<int, int> > q;
                q.push(make_pair(i,j));
                check2[i][j] = true;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int c = 0; c < 4; c++){
                        int nx = x + dx[c];
                        int ny = y + dy[c];
                        if(nx >= 0 && nx < n && ny >=0 && ny < n){
                            if(!check2[nx][ny] && current == 1){
                                if(color[nx][ny] == 'B'){
                                    check2[nx][ny] = true;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                            else if(!check2[nx][ny] && current == 2){
                                if(color[nx][ny] == 'R' || color[nx][ny] == 'G'){
                                    check2[nx][ny] = true;
                                    q.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << yes << ' ';
    cout << no;
    return 0;
}