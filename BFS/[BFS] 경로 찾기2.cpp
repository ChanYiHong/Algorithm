#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int> > board;
vector<vector<int> > answer;

void make_answer(int start, int next)
{
    if(start == next){
        answer[start][start] = 1;
        return;
    }
    answer[start][next] = 1;
    for(int i = 0 ; i < board[next].size(); i++){
        int over_the_next = board[next][i];
        if(answer[start][over_the_next] == 0){
            make_answer(start, over_the_next);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    answer.resize(N, vector<int>(N));
    board.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num;
            cin >> num;
            if(num == 1) board[i].push_back(j);
            answer[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < board[i].size(); j++){
            make_answer(i, board[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}