#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char sign[9];
int n;

// 답의 후보를 넣는다.
vector<string> answer;
// 중복은 항상 check 배열로 확인하자.
int check[10];

bool ok(char a, char b, char sign)
{
    if(sign == '>'){
        if(a < b) return false;
    }
    if(sign == '<'){
        if(a > b) return false;    
    }
    return true;
}

void go(int index, string num)
{
    // 멈춤 조건
    if(index == n + 1){
        answer.push_back(num);
        return;
    }
    // 다음으로 가는 경우
    // 최대 값 찾아보기
    for(int i = 0; i <= 9; i++){
        if(check[i]) continue;
        if(index == 0 || ok(num[index-1],i+'0',sign[index-1])){
            check[i] = true;
            go(index + 1, num+to_string(i));
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> sign[i];
    }
    go(0, 0);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }
    
    return 0;
}