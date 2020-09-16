#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int alpha[26] = {0,};
    int k = 0;
    while(str[k] != '\0'){
        if(str[k] >= 65 && str[k] <= 90){
            alpha[int(str[k]-'A')]++;
        }
        if(str[k] >= 97 && str[k] <= 122){
            alpha[int(str[k]-'a')]++;
        }
        k++;
    }
    int max = 0;
    int index = 0;
    for(int i=0;i<26;i++){
        if(alpha[i]>max){
            max = alpha[i];
            index = i;
        }
    }

    int state = 0;
    for(int i=0;i<26;i++){
        if(state == 0 && max == alpha[i]){
            state = 1;
            continue;
        }
        if(state == 1 && max == alpha[i]){
            state = 2;
            cout << '?';
            break;
        }
    }
    if(state == 1){
        cout << char('A'+index);
    }

    return 0;
}