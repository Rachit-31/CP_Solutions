#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {

        ll n;

        cin >> n;

        ll mini = LLONG_MAX;

        ll sum_mini = LLONG_MAX;

        ll sum = 0;

        while (n--)
        {

            ll m;

            cin >> m;

            vector<ll> v(m);

            for (ll &x : v)
            {

                cin >> x;
            }

            sort(v.begin(), v.end());

            sum += v[1];

            mini = min(v[0], mini);

            sum_mini = min(v[1], sum_mini);
        }

        cout << sum + mini - sum_mini << endl;
    }

    return 0;
}