#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int res;

int button[10][16] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
bool isAllClockTwelve(vector<int>& watch)
{
    for(int i = 0; i < 16; i++){
        if(watch[i] != 12) return false;
    }
    return true;
}
void adjustWatch(int buttonNum, vector<int>& watch)
{
    for(int i = 0; i < 16; i++){
        if(button[buttonNum][i] == 1){
            watch[i] += 3;
            if(watch[i] == 15) watch[i] = 3;
        }
    }
}
void pushButton(int pushNum, vector<int>& watch, int buttonNum)
{
    if(isAllClockTwelve(watch)){
        res = min(res, pushNum);
        return;
    };
    if(buttonNum > 9){
        return;
    }
    for(int i = 0; i < 4; i++){
        pushButton(pushNum+i, watch, buttonNum+1);
        adjustWatch(buttonNum, watch);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        vector<int> watch(16);
        res = INF;
        for(int i = 0; i < 16; i++){
            cin >> watch[i];
        }
        pushButton(0, watch, 0);
        cout << res << '\n';
    }
    return 0;
}