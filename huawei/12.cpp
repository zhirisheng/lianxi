#include <bits/stdc++.h>

using namespace std;

int r = 0;
int n = 0;
int task[10000] = {0};

void func()
{
    int time = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (task[i] + sum <= r)
        {
            time++;
            sum = 0;
        }
        else
        {
            time += (task[i] + sum) / r;
            sum = (task[i] + sum) % r;
        }
    }
    cout << "result:" << time;
}

int main()
{
    cin >> r;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }
    func();
    cin >> r >> n;
}