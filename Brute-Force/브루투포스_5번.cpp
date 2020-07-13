#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int answer;
    int count = 0;
    int number = 666;
    int sequence = 0;
    while(1){
        for(int i = number ; i > 1; i /= 10){
            if(i % 10 == 6) sequence++;
            else sequence = 0;
            if(sequence == 3){
                count ++;
                break;
            }
        }
        if(count == N){
            answer = number;
            break;
        }
        number++;
        sequence = 0;
    }
    cout << answer;
    return 0;
}



