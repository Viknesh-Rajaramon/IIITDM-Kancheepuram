#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define N 50000
#define pb push_back
#define mp make_pair

void Greedy(vector<pair<int, int>> v, int x)
{
    int count = 0;

    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (x >= v[i].f && v[i].s > 0)
        {
            x -= v[i].f;
            v[i].s--;
            count++;
        }
    }

    cout << "Greedy solution- ";
    if (x == 0)
    {
        cout << endl
             << "Minimum number of coins required is " << count << endl;
    }
    else
    {
        cout << endl
             << "Change is not possible with given denominations" << endl;
    }
}

int main()
{
    vector<pair<int, int>> coins;
    int k, a, b;
    cout << "Enter number of denominations: ";
    cin >> k;
    cout << "Enter (denomination,limit): ";
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        coins.pb(mp(a, b));
    }
    int x;
    cout << "Enter value: ";
    cin >> x;
    Greedy(coins, x);
}