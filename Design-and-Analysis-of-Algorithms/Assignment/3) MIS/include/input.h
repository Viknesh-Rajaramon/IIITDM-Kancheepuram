#include <bits/stdc++.h>
#define NIL -1
#include <queue>
#include <list>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define INF 1000000
#define s second
#define f first

void Greedy(vector<int> adj[], int n);
void edge_add(vector<int> adj[], int u, int v);
void get_graph(vector<int> adj[], int n);
int get_degree(vector<int> adj[], int n, int u);
void DPMis(vector<int> adj[], int x, int y, set<int> DP[]);
