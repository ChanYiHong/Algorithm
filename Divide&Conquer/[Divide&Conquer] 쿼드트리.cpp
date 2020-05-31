#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
char arr[65][65];
string answer="";

void quadTree(int x, int y, int size)
{
    if(size == 1){
        answer += arr[x][y];
        return;
    }
    char color = arr[x][y];
    bool uni = true;
    for(int i = x; i < size + x; i++){
        for(int j = y; j < size + y; j++){
            if(color != arr[i][j]){
                uni = false;
                break;
            }
        }
        if(!uni) break;
    }
    if(uni){
        answer += arr[x][y];
    }
    else{
        answer += "(";
        quadTree(x, y, size/2);
        quadTree(x, y + size/2, size/2);
        quadTree(x + size/2, y, size/2);
        quadTree(x + size/2, y + size/2, size/2);
        answer += ")";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    quadTree(0,0,n);
    cout << answer;

    return 0;
}

// 분할 정복
/*
계속 사등분 하는데, 만약에 다 0이거나 1이면 그대로 그 숫자 출력

처음에.. 쭉 보다가 다른거 있으면 괄호 붙이고,
음..
일단 함수를 만들어서
시작점 위치 x,y좌표랑 사이즈 어제랑 똑같이..

그리고 string 변수를 만들고
string합치는 뭔가를 찾아서 처음에 들어갈 때
( 붙이고
다 끝나면 ) 붙이고
*/