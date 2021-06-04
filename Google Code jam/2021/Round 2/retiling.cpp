//note: this solution got me 0 points
//so I think the idea is wrong

#include <bits/stdc++.h>
using namespace std;

const int mn = 1000;
int pt[mn],A[mn],B[mn];
 
int find_set(int v) {
    if (v == pt[v])
        return v;
    return pt[v] = find_set(pt[v]);
}
 
void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (A[a]+B[a] < A[b]+B[b])
            swap(a, b);
        pt[b] = a;
        A[a] += A[b];
        B[a] += B[b];
    }
}

int solve()
{
    int n,m,x,y,ans=0;
    cin>>n>>m>>x>>y;
    string s[n],t[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        cin>>t[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            pt[i*m+j]=i*m+j;
            if (s[i][j]=='M')
            {
                A[i*m+j]=1;
                B[i*m+j]=0;
            }
            else
            {
                A[i*m+j]=0;
                B[i*m+j]=1;
            }
            if (s[i][j]!=t[i][j])
                ++ans;
        }
    for (int i=1;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]!=s[i-1][j]&&s[i][j]!=t[i][j]&&s[i-1][j]!=t[i-1][j])
                unite((i-1)*m+j,i*m+j);
    for (int i=0;i<n;++i)
        for (int j=1;j<m;++j)
            if (s[i][j]!=s[i][j-1]&&s[i][j]!=t[i][j]&&s[i][j-1]!=t[i][j-1])
                unite(i*m+j-1,i*m+j);
    for (int i=0;i<n*m;++i)
        if (pt[i]==i)
            ans-=min(A[i],B[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": ";
        cout<<solve()<<"\n";
    }
    return 0;
}