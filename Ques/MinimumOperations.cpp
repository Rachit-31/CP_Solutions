#include <bits/stdc++.h>
using namespace std;

void s()
{
    long long n, k;
    cin >> n >> k;
    long long a = 0;
    if (k == 1)
    {
        cout << n << '\n';
        return;
    }
    while (n)
    {
        a += n % k;
        n /= k;
    }
    cout << a << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        s();
    }
}