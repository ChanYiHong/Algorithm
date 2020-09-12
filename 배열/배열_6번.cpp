#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char str[N][80];
    int score = 0;
    int bonus = 1;

    for(int i = 0; i<N; i++){
        cin >> str[i];
        for(int j = 0; str[i][j] != '\0'; j++){
            if(str[i][j] == 'O'){
                score = score + bonus;
                bonus++;
            }
            else{
                bonus = 1;
            }
        }
        cout << score << '\n';
        score = 0;
        bonus = 1;
    }

    return 0;
}