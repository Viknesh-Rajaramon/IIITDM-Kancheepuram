#include "../include/input.h"

void edge_add(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void get_graph(vector<int> adj[], int n)
{
    int u, v, m;
    m = n - 1;
    cout << "Enter edges(src,dest separated by spaces): ";
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edge_add(adj, u, v);
    }
}

int main()
{
    int n;
    cout << "Enter vertices starting from 0 \n\n";
    cout << "Enter no of vertices: " << endl;
    cin >> n;
    vector<int> adj[100];
    get_graph(adj, n);
    cout << endl
         << endl
         << "Greedy solution - "
         << endl;
    Greedy(adj, n);

    cout << endl
         << endl
         << "DP solution - "
         << endl;
    set<int> M;
    set<int> DP[100];
    DPMis(adj, 0, 0, DP);

    cout << endl
         << "Maximum Independent Set" << endl;
    for (auto it = DP[0].begin(); it != DP[0].end(); it++)
        cout << *it << " ";
}