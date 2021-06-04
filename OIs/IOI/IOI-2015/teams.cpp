#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+7;
int n;
array<int,2> a[N];

bool cmp(array<int,2>& x, array<int,2> &y)
{
    return x[1] < y[1];
}

void init(int tmp, int A[], int B[])
{
    n=tmp;
    for (int i=0;i<n;++i)
        a[i]={A[i],B[i]};
    sort(a,a+n,cmp);
}

bool can(int m, int k[])
{
    sort(k,k+m);
    int c=0, x=0;
    for (int i=0;i<n&&c<m;++i)
        if (a[i][0]<=k[c]&&k[c]<=a[i][1])
            if (++x==k[c])
                x=0,++c;
    return c==m;
}

// int main()
// {
//     int t,q,k;
//     cin>>t;
//     int A[t],B[t];
//     for (int i=0;i<t;++i)
//         cin>>A[i]>>B[i];
//     init(t,A,B);
//     cin>>q;
//     while (q--)
//     {
//         cin>>k;
//         int c[k];
//         for (int i=0;i<k;++i)
//             cin>>c[i];
//         cout<<can(k,c)<<"\n";
//     }
// }