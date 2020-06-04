#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
string str;
bool D[2501][2501];
/*
int mid(int x, int y)
{
    int size = y - x + 1;
    int goal = x + size/2;
    return goal;
}
*/
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> str;
    int len = str.size();
    // 1번째 자리부터 계산하기 위함
    str = " " + str;

    // i ~ j 번째 까지가 팰린드롬인지 확인
    for(int i = len; i > 0; i--){
        for(int j = i; j <=len; j++){
            if(i == j) D[i][j] = 1;
            else if(i == j-1 && str[i] == str[j]) D[i][j] = 1;
            else if(D[i+1][j-1] && str[i] == str[j]) D[i][j] = 1;
        }
    } 

    // 
    int cnt[2501];
    cnt[0] = 0;
	for (int i = 1; i <= len; i++) {
		cnt[i] = 987654321;
		for (int j = 1; j <= i; j++) {
			if (D[j][i]) {
				if (cnt[i] > cnt[j - 1] + 1) {
					cnt[i] = cnt[j - 1] + 1;
				}
			}
		}
	}
}
    
    /*
    for(int i = 0; i < str.length(); i++){
        for(int j = i; j < str.length(); j++){
            // 개수가 짝수면 절대 대칭이 안됨. 그래서 홀수만 봐줌
            if((j - i + 1) % 2 == 1){
                // 만약 D[x][x] 처럼 값이 같으면 무조건 대칭임
                if(i == j) D[i][j] = true;
                else{
                    int check = true;
                    int middle = mid(i,j);
                    for(int k = 1; k <= middle; k++){
                        int left = middle - k;
                        int right = middle + k;
                        if(str[left] != str[right]){
                            check = false;
                            break;
                        }
                    }
                    if(check == true) D[i][j] = true;
                }
            }
        }
    }*/
    cout << cnt[len];
    return 0;
}
/*
ABACABA
는 
ABACABA 분할이 가능하다

어쨋든
가장 길이가 길게 최대한 분할해야해
DP를 사용한다 치고 우선 DP 문제니까

ABA가 펠린드롬
펠린드롬이려면 무조건 개수가 홀수여야 함
ABA x x 가 펠린드롬 이려면

가운데를 기준으로 역으로 다 같아야 됨

for문을 i = 0부터 돌되
j = i 부터 돌고
j - i + 1 이 짝수면 무조건 0

근데 길이는 어떻게 할까
------------------------
A, B, A, C, A, B, A
ABACABA
i = 0 
A 
D[0][0] = 1
D[0][1] = 0;
D[0][2] => 2 - 0 / 2 = 1
        str[0] == str[2]
        D[0][2] = 1;

D[1][1] = 1
D[1][2] = 0
D[1][3] = 0;
D[1][4] = 0;
D[1][5] = 1;

D[0][0] = 1;
끝점하고 길이 저장?
answer[5] = 2;
answer[0] = 1;
answer[1] = answer[0] + 1;
answer[2] = answer[1]
D[0][4] = 0;
D[4][4] = 1;
D[4][5]......

흠

결국 answer 는 그냥
다시한번
일단 해볼까
아니 일단 하지마

*/
