#include <iostream>

using namespace std;

int deque[20002];
int head = 10000;
int tail = 10001;
void push_front(int X)
{
    deque[head] = X;
    head--;
}
void push_back(int X)
{
    deque[tail] = X;
    tail++;
}
void pop_front()
{
    if(head + 1 == tail) cout << -1 << '\n';
    else{
        cout << deque[head+1] << '\n';
        head++;
    }
}
void pop_back()
{
    if(head + 1== tail) cout << -1 << '\n';
    else{
        cout << deque[tail-1] << '\n';
        tail--;
    }
}
void size()
{
    cout << tail - head - 1 << '\n';
}
void empty()
{
    if(head + 1 == tail) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void front()
{
    if(head + 1 == tail) cout << -1 << '\n';
    else cout << deque[head+1] << '\n';
}
void back()
{
    if(head + 1 == tail) cout << -1 << '\n';
    else cout << deque[tail-1] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    string str;
    int num;
    for(int i = 0; i < N; i++){
        cin >> str;
        if (str == "push_front"){
            cin >> num;
            push_front(num);
        }
        else if (str == "push_back"){
            cin >> num;
            push_back(num);
        }
        else if (str == "pop_front") pop_front();
        else if (str == "pop_back") pop_back();
        else if (str == "size") size();
        else if (str == "empty") empty();
        else if (str == "front") front();
        else if (str == "back") back();
    }
    return 0;
}