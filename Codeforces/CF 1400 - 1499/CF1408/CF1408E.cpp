#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

const int maxn = 2e5 + 7;
vector<pii> edges[maxn];
bitset<maxn> done;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n, x, y;
    cin >> m >> n;

    // We can revisualise this set to element relationship in the form of a bipartite graph,
    // with the "sets" on the left, and "elements" on the right.
    // Viewing it as such, we can see that in order for no cycles to occur, we must find a/some tree-like component(s),
    // while deleting all other edges.
    // This should you remind you of maximum spanning tree, as we want to maximise the values of edges that we don't delete.

    int a[m+1], b[n+1];
    ll ans = 0;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i<=m; ++i)
    {
        cin >> x;
        for (int j = 1; j <= x; ++j)
        {
            cin >> y;
            ans += a[i] + b[y];
            edges[y].push_back({a[i] + b[y], n + i});
            edges[n + i].push_back({a[i] + b[y], y});
        }
    }
    priority_queue<pii> q;
    for (int i = 1; i<=n; ++i)
        if (!done[i])
        {
            done[i] = 1;
            for (pii j : edges[i])
                q.push(j);
            while (!q.empty())
            {
                x = q.top().f;
                y = q.top().s;
                q.pop();
                if (done[y])
                    continue;
                done[y] = 1;
                ans -= x;
                for (pii j : edges[y])
                    q.push(j);
            }
        }
    cout << ans;
    return 0;
}