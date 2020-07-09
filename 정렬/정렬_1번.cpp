#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> vec;
    for(int i = 0; i < N; i++){
        int number;
        cin >> number;
        vec.push_back(number);
    }
    for(int i = vec.size(); i > 1; i--){
        for(int j = 1; j < i; j++){
            if(vec[j-1]> vec[j]){
                int temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }
    }
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << '\n';
    }
    return 0;
}