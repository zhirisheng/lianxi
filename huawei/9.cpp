#include <bits/stdc++.h>

using namespace std;

long long x = 0;
int y = 1;
int n = 1;
int main()
{
    cin >> x;
    cin >> y;
    long long m = pow(26, y);
    cout << m << "x:" << x << endl;
    long long p = 1;
    long long result = p * m;
    while (result < x)
    {
        cout << "p:" << result << endl;
        result *= 10;
        n++;
    }
    if (n > 1)
    {
        n--;
    }
    cout << n;
    cin >> n;
    return 0;
}