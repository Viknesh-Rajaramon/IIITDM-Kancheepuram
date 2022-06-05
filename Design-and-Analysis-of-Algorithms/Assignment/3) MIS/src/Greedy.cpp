#include "../include/input.h"

int get_degree(vector<int> adj[], int n, int u)
{
    return adj[u].size();
}

void Greedy(vector<int> adj[], int n)
{
    set<pair<int, int>> deg;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        deg.insert(make_pair(get_degree(adj, n, i), i));
    }

    // cout<<"Degree sequence"<<endl;
    // for (auto const &x : deg)
    // cout<<x.first<<" "<<x.second<<endl;

    set<int> mis;
    int v;
    while (!deg.empty())
    {
        p = *(deg.begin());
        v = p.second;

        mis.insert(v); //insert min degree node in mis
        deg.erase(deg.begin());

        for (auto it = adj[v].begin(); it != adj[v].end(); it++) //erase neighbours of v
        {
            for (auto i = deg.begin(); i != deg.end(); i++)
            {
                if (i->second == *it)
                    deg.erase(*i);
            }
        }
    }

    cout << endl
         << "Maximum Independent Set" << endl;
    for (auto it = mis.begin(); it != mis.end(); it++)
        cout << *it << " ";
}