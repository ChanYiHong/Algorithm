#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int k = 0;
    int state = 0;
    int count = 0;

    for(int t = 0;t < N;t++){
        string str;
        cin >> str;
        vector<char> vec;
        while(str[k] != '\0'){   
            if(k==0){
                vec.push_back(str[k]);
                k++;
                continue;
            }
            if(str[k-1] == str[k]){ 
                k++;
            }
            else{
                for(vector<char>::size_type i = 0;i<vec.size();i++){
                    if(str[k] == vec[i]){
                        state = 1;
                        break;
                    }
                }
                if(state == 1)break;
                vec.push_back(str[k]);
                k++;
            }
        }
        if(state == 0)count++;
        state = 0;
        k = 0;
    }
    cout << count;

    return 0;
}