#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;
    
    char temp = A[0];
    A[0] = A[2];
    A[2] = temp;

    temp = B[0];
    B[0] = B[2];
    B[2] = temp;

    int iA =0;
    int iB =0;
    int dot = 100;
    for(int i =0;i<3;i++){
        iA += (A[i] - '0') * dot;
        iB += (B[i] - '0') * dot;
        dot = dot / 10;
    }

    if(iA > iB) cout << A;
    else cout << B;
    return 0;
}