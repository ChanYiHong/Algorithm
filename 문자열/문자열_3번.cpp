#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char input[100] = {0,};
    int alpha[26];
    cin >> input;
    int k = 0;

    for(int i = 0;i < 26;i++){
        alpha[i] = -1;
    }

    while(input[k] != 0){
        if(alpha[int(input[k]-'a')] == -1){
            alpha[int(input[k]-'a')] = k;
        }
        k++;
    }
    for(int i = 0;i < 26;i++){
        cout << alpha[i] << " ";
    }
    return 0;
}