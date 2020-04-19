#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n;
vector<vector<int> > v;
int answer[100001];
bool check[100001];
int parent[100001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    v.resize(n+1, vector<int>());
    for(int i = 0; i < n-1; i++){
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }

    for(int i = 1 ; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }

    for(int i = 0; i < n; i++){
        cin >> answer[i];
    }

    bool state = true;
    queue<int> q;
    q.push(1);
    check[1] = true;
    int m = 1; // 큐의 크기
    
    for(int k = 0; k < n; k++){
        if(q.empty()){
            state = false;
            break;
        }
        int cnt = 0;
        int x = q.front();
        q.pop();
        if(x != answer[k]){
            state = false;
            break;
        }
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(!check[y]){
                parent[y] = x;
                cnt++;
            }
        }
        for(int i = 0; i < cnt; i++){
            if(m+i >= n || parent[answer[m+i]] != x){
                state = false;
                break;
            }
            else{
                q.push(answer[m+i]);
                check[answer[m+i]] = true;
            }
        }
        m += cnt;
        if(!state) break;
    }

    if(state) cout << 1;
    else cout << 0;
    return 0;
}