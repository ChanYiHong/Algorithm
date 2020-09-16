#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int k = 0;
    int count = 0;
    while(k < str.length()){
        if(str[k] == 'c'){
            if(str[k+1] == '=' || str[k+1] == '-'){
                count++;
                k += 2;
            }
            else{
                count++;
                k++;
            }
        }
        else if(str[k] == 'd'){
            if(str[k+1] == 'z'){
                if(str[k+2] == '='){
                    count++;
                    k += 3;
                }
                else{
                    count++;
                    k++;
                }
            }
            else if(str[k+1] == '-'){
                count++;
                k += 2;
            }
            else{
                count++;
                k++;
            }
        }
        else if(str[k] == 'l'){
            if(str[k+1] == 'j'){
                count++;
                k += 2;
            }
            else{
                count++;
                k++;
            }
        }
        else if(str[k] == 'n'){
            if(str[k+1] == 'j'){
                count++;
                k += 2;
            }
            else{
                count++;
                k++;
            }
        }
        else if(str[k] == 's'){
            if(str[k+1] == '='){
                count++;
                k += 2;
            }
            else{
                count++;
                k++;
            }
        }
        else if(str[k] == 'z'){
            if(str[k+1] == '='){
                count++;
                k += 2;
            }
            else{
                count++;
                k++;
            }
        }
        else{
            count++;
            k++;
        }
    }
    cout << count;

    return 0;
}