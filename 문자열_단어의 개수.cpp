#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);

    int k = 0;
    int count = 0;
    while(str[k]!='\0'){
        if(k==0 && str[k] == ' '){
            k++;
            continue;
        }
        if(str[k] == ' ' && str[k+1] == '\0'){
            count++;
            break;
        }
        if(str[k+1] == '\0'){
            count++;
            break;
        }
        if(str[k] == ' '){
            count++;
        }
        k++;
    }
    cout << count;
    return 0;
}