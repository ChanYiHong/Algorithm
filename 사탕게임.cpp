#include <iostream>
using namespace std;

char arr[51][51];
int find(int n)
{
    int i, j, count = 1;
    int max = 0;
    // 행 부터 찾기
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(arr[i][j] == arr[i][j+1]) {
                count++;
                if(count > max) max = count;
            }
            else count = 1;
        }
        count = 1;
    }
    // 열 찾기
    for(j=0;j<n;j++){
        for(i=0;i<n-1;i++){
            if(arr[i][j] == arr[i+1][j]){
                count++;
                if(count > max) max = count;
            }
            else count = 1;
        }
        count = 1;
    }
    return max;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int i,j, n;
    int answer = 0;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    //행을 기준으로..
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(arr[i][j] != arr[i][j+1]){
                char temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
                int result = find(n);
                if(result > answer) answer = result;
                //바꾼걸 다시 원상복구
                temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
            }  
        }
    }

    //열을 기준으로..
    for(j=0;j<n;j++){
        for(i=0;i<n-1;i++){
            if(arr[i][j] != arr[i+1][j]){
                char temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
                int result = find(n);
                if(result > answer) answer = result;
                //바꾼걸 다시 원상복구
                temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
            }
        }
    }

    cout << answer;

    return 0;
}