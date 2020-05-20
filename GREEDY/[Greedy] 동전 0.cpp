#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, goal;
    cin >> n >> goal;
    int coin[n];
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    // Greedy
    int count = 0;
    int index = n-1;
    int total = 0;
    while(1){
        if(coin[index] > goal){
            index--;
            continue;
        }
        else if(coin[index] < goal){
            if(total + coin[index] < goal){
                count++;
                total += coin[index];
                continue;
            }
            else if(total + coin[index] > goal){
                index--;
                continue;
            }
            else{
                count++;
                break;
            }
        }
        else{
            count++;
            break;
        }
    }

    cout << count;
    return 0;
}