#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string dial;
    cin >> dial;

    int k = 0;
    int time = 0;
    while(dial[k] != '\0'){
        if(dial[k] >= 65 && dial[k] <= 67){
            time += 3;
        }
        else if(dial[k] >= 68 && dial[k] <= 70){
            time += 4;
        }
        else if(dial[k] >= 71 && dial[k] <= 73){
            time += 5;
        }
        else if(dial[k] >= 74 && dial[k] <= 76){
            time += 6;
        }
        else if(dial[k] >= 77 && dial[k] <= 79){
            time += 7;
        }
        else if(dial[k] >= 80 && dial[k] <= 83){
            time += 8;
        }
        else if(dial[k] >= 84 && dial[k] <= 86){
            time += 9;
        }
        else{
            time += 10;
        }
        k++;
    }
    cout << time;

    return 0;
}