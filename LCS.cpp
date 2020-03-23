#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str1, str2;
    cin >> str1 >> str2;

    int chart[1001][1001];
    int i, j;
    for(i = 0; i <= str1.length(); i++){
        for(j = 0; j <= str2.length(); j++){
            if(i == 0 || j == 0){
                chart[i][j] = 0;
                continue;
            }
            if(str1[i-1] != str2[j-1]) chart[i][j] = max(chart[i][j-1], chart[i-1][j]);
            if(str1[i-1] == str2[j-1]) chart[i][j] = chart[i-1][j-1] + 1;
        }
    }

    int max = 0;
    for(i = 0; i <= str1.length(); i++){
        for(j = 0; j <= str2.length(); j++){
            if(max < chart[i][j]) max = chart[i][j];
        }
    }
    cout << max;
    return 0;
}