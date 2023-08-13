// bad impl, copied my cses submission for a template
// to-do: re-impl sometime?

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int trie[6400000][2], d;
 
void add(int x, int id)
{
    int c=0;
    for (int i=29;i>=0;--i)
    {
        if (!trie[c][min((1<<i)&x,1)])
            trie[c][min((1<<i)&x,1)]=++d;
        c=trie[c][min((1<<i)&x,1)];
    }
    trie[c][0]=id;
}
 
int query(int x)
{
    int c=0;
    for (int i=29;i>=0;--i)
    {
        if ((1<<i)&x)
        {
            if (trie[c][1])
                c=trie[c][1];
            else
                c=trie[c][0];
        }
        else
        {
            if (trie[c][0])
                c=trie[c][0];
            else
                c=trie[c][1];
        }
    }
    return trie[c][0];
}

void solve() {
    for (int i = 0; i <= d; ++i) {
        trie[i][0] = trie[i][1] = 0;
    }
    d = 0;
    int n, k;
    cin >> n >> k;
    int a[n];
    array<int, 3> ans = {1 << k, -1, -1};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) {
            int q = query(a[i]);
            ans = min(ans, {a[q] ^ a[i], q, i});
        }
        add(a[i], i);
    }
    int x = 0;
    for (int i = 0; i < k; ++i) {
        if ((a[ans[1]] & (1 << i)) == 0 && (a[ans[2]] & (1 << i)) == 0) {
            x += 1 << i;
        }
    }
    cout << ans[1] + 1 << " " << ans[2] + 1 << " " << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}