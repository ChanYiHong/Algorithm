#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
vector<vector<int> > v;
int ans;
int n, m;

void picnic(vector<bool>& list)
{
    int first = -1;
    for(int i = 0; i < n; i++){
        if(!list[i]) {first = i; break;}        
    }
    if(first == -1) {ans++; return;}
    for(int i = 0 ; i < v[first].size() ; i++){
        if(list[v[first][i]] == true ) continue;
        list[first] = true;
        list[v[first][i]] = true;
        picnic(list);
        list[first] = false;
        list[v[first][i]] = false;
    } 
    // for(int i = first+1; i < n; i++){
        
    //     if(list[i] == true) continue;
    //     for(int j = 0; j < v[i].size(); j++){
    //         if(list[j] == true) continue;
    //         list[i] = true;
    //         list[v[i][j]] = true;
    //         cout << i << ' ' << v[i][j] << '\n';
    //         picnic(list);
    //         list[i] = false;
    //         list[v[i][j]] = false;
    //     }
    // }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        v.resize(n, vector<int>());
        ans = 0;
        for(int i = 0; i < m; i++){
            int stu1, stu2;
            cin >> stu1 >> stu2;
            v[stu1].push_back(stu2);
            v[stu2].push_back(stu1);
        }
        for(int i = 0; i < n; i++){
            sort(v[i].begin(), v[i].end());
        }
        vector<bool> list(n, false);
        picnic(list);
        cout << ans << '\n';
        v.clear();
    }
    return 0;
}
/*
작은 조각 + 나머지 재귀

짝들을 다 vector에 저장
2차원 벡터
약간 그래프 느낌으로

한명씩 받으면서
짝이 될 수 있으면 짝으로 만들고
체크하고..
다 되면 체크 초기화 하고
경우의 수 ++해주고

최악의 경우도
10 x (90/2)= 450 x 50 정도?
*/
/*
1. 문제를 읽는다
2. 문제를 내가 쓸 수 있는 말로 다시 재정의 한다
3. 문제를 어떻게 해결할지 생각. 자료구조, 알고리즘..
4. 계획 검증하기.. 메모리, 시간복잡도, 
5. 구현
6. 복습
*/