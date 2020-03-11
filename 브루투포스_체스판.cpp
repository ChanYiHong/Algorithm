#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    char board[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    // 검사 횟수
    int num;
    if(M == 8 && N == 8) num = 1;
    else num = (M-7) * (N-7);

    int x;
    int y;
    int min = 987654321;
    for(int i = 0; i < num; i++){
        // 검사하는 영역 지정 8 x 8
        // y축으로 한 칸씩 이동. y축 다 보면 밑으로 한칸
        if(i==0){ 
            x = 0;
            y = 0;
        }
        else if(y + 9 > M){
            y = 0;
            x++;
        }
        else y++;

        for(int two = 0; two < 2; two++){
            int count = 0;
            char first;
            for(int j = x; j < x + 8; j++){
                for(int k = y; k < y + 8; k++){
                    // 8x8판에서 젤 왼쪽맨위 
                    if(j == x && k == y && two == 0){
                        first = 'W';
                        if(first != board[j][k]) count++;
                        continue;
                    }
                    if(j == x && k == y && two == 1){
                        first = 'B';
                        if(first != board[j][k]) count++;
                        continue;
                    }
                    // 8x8판의 맨 왼쪽 열 다음 행과 맨 오른쪽 위의 행이랑 비교
                    if(j != x && k == y){
                        if(first == board[j][k]){
                            continue;
                        }
                        else{
                            count++;
                            continue;
                        }
                    }
                    if((k-y)%2 == 1 && board[j][k] == first) count++;
                    if((k-y)%2 == 0 && board[j][k] != first) count++;
                    if(k == y + 7){
                        if(first == 'B') first = 'W';
                        else first = 'B';
                    }
                }
            }
            if(min > count) min = count;
        }
    }
    cout << min << '\n';

    return 0;
}