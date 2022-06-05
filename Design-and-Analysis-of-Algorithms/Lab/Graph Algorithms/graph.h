#ifndef GRAPH_H 
#define GRAPH_H 

//Basic Graph Algorithms
int check_connected(int **,int,int);
int check_connected_DAG(int **,int);
void add_edge(int **,int,int);
void add_edge(int **,int,int,int);
void add_edge_directed(int **,int,int,int);
void remove_edge(int **,int,int);
int* initialize_1d_array(int,int);
int **initialize_adjmatrix(int);
int check_cycle(int **,int,int,int);

//Module 1
void dfs(int **,int *,int,int);
void dfs(int **,int);
int dfs(int **,int,int,int);

//Module 2
void bfs(int **,int *,int,int);
void bfs(int **,int *,int);
int bfs(int **,int *,int,int,int);

//Module 3
int min_distance(int *,int *,int);
void BFS_SPATH(int **,int,int,int);
std::pair<int,int> bfs(int **,int,int);
void topological_sort(int **,int,int,int *,int *,int &);
void LPATH(int **,int,int,int);
void MAX_Weight_MST(int **,int);
bool reverse_sort(struct edge,struct edge);
void MST_youralgo(int **,int);

//Module 4
int Test_bipartite(int **,int);
void APutil(int,int *,int *,int *,int *,int *,int **,int);
void Test_articulationpoints(int **,int);
void Bridgeutil(int,int *,int *,int *,int *,int **,int);
void Test_bridges(int **,int);

//Module 5
void mst_prim(int **,int);
bool edge_sort(struct node,struct node);
void mst_kruskal(int **,int);
void mst_youralgo(int **,int);

#endif
