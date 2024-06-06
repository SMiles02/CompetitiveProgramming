#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e6 + 2;
int b[N], c[N];

ll find_inversions(int l, int r)
{
    if (l==r)
        return 0;
    int m=l+((r-l)>>1),x=l,y=m+1;
    ll ans=find_inversions(l,m)+find_inversions(m+1,r);
    for (int i=l;i<=r;++i)
    {
        if (x>m)
            c[i]=b[y++];
        else if (y>r)
            c[i]=b[x++];
        else if (b[x]>b[y])
        {
            c[i]=b[y++];
            ans+=m-x+1;
        }
        else
            c[i]=b[x++];
    }
    for (int i=l;i<=r;++i)
        b[i]=c[i];
    return ans;
}

void dnc(int l, int r, int pl, int pr, vector<int>& a, vector<int>& c, vector<vector<int>>& after_this) {
    if (l > r) {
        return;
    }
    int m = l + (r - l) / 2, mn, ans = pl, cur = 0;
    // cout << l << " " << m << " " << r << " " << pl << " " << pr << endl;
    // return;
    for (int i = pr; i > pl; --i) {
        cur += c[m] > a[i];
    }
    mn = cur;
    for (int i = pl + 1; i <= pr; ++i) {
        cur -= c[m] > a[i];
        cur += a[i] > c[m];
        if (cur < mn) {
            mn = cur;
            ans = i;
        }
    }
    after_this[ans].push_back(c[m]);
    dnc(l, m - 1, pl, ans, a, c, after_this);
    dnc(m + 1, r, ans, pr, a, c, after_this);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), c(m);
    vector<vector<int>> after_this(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    dnc(0, m - 1, 0, n, a, c, after_this);
    int cur = 0;
    for (int i = 0; i <= n; ++i) {
        if (i != 0) {
            b[cur++] = a[i];
        }
        sort(after_this[i].begin(), after_this[i].end());
        for (int j : after_this[i]) {
            b[cur++] = j;
        }
    }
    cout << find_inversions(0, cur - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}