#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int trie[10000000][2],d;

void add(int x)
{
    int c=0;
    for (int i=19;i>=0;--i)
    {
        if (!trie[c][min((1<<i)&x,1)])
            trie[c][min((1<<i)&x,1)]=++d;
        c=trie[c][min((1<<i)&x,1)];
    }
    trie[c][0]=x;
}

int query(int x)
{
    int c=0;
    for (int i=19;i>=0;--i)
    {
        if ((1<<i)&x)
        {
            if (trie[c][0]) {
                c=trie[c][0];
            }
            else {
                c=trie[c][1];
            }
        }
        else
        {
            if (trie[c][1]) {
                c=trie[c][1];
            }
            else {
                c=trie[c][0];
            }
        }
    }
    return trie[c][0] ^ x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    add(0);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        add(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (query(a[i]) == n - 1) {
            for (int j = 0; j < n; ++j) {
                cout << (a[j] ^ a[i]) << " ";
            }
            return 0;
        }
    }
    return 0;
}