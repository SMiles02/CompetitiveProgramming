#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3e5+7;
int n,a[N],b[N],c[N];

// b is the array that will be checked (will also be sorted after checking)
 
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    int n, k, ans, q_inv = 0;
    cin >> n >> k;
    vector<int> p(n), q(k);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> q[i];
    }
    for (int i = 0; i < n * k; ++i) {
        b[i] = p[i / k] * (1 << q[i % k]);
    }
    cout << find_inversions(0, n * k - 1);
    return 0;
}