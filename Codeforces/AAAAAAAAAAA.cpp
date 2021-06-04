const int N = 1e5; // tree size
vector<int> e[N]; // edges in the tree
int tin[N], tout[N], timer = 0;

void dfs(int v, int p)
{
    tin[v] = timer++; // increment timer upon entry
    for (int i : e[v])
        if (i != p)
            dfs(i, v);
    tout[v] = timer++; // increment timer upon exit
}
