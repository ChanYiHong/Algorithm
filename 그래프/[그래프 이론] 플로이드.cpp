#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n, m;
vector<vector<pair<int, int> > > v;

int dfs(int start, int end, int cur)
{
    if(start == end) return 0;
    vector<int> answer;
    for(int i = 0; i < v[cur].size(); i++){
        int des = v[cur][i].first;
        if(des == end) return v[cur][i].second;
        int result = dfs(start, end, des);
        if(result == -1) return -1; 
        if(start == cur && result != -1) answer.push_back(result); continue;
        return result + v[cur][i].second;
    }
    int min = 1000000;
    if(start == cur){
        for(int i = 0; i < answer.size(); i++){
            if(min > answer[i]) min = answer[i];
        }
    }
    return min;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    scanf("%d %d",&n,&m);
    v.resize(n+1);
    for(int i = 0; i < m; i++){
        int start, end, cost;
        scanf("%d %d %d",&start,&end,&cost);
        v[start].push_back(make_pair(end, cost));
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) printf("0 ");
            printf("%d",dfs(i, j, i));
        }
        printf("\n");
    }
    
    return 0;
}