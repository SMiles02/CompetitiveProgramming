#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double f (double t)
{
    return sqrt (fabs (t)) + 5 * pow (t, 3);
}

int main (void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int a[11];
    double y;
    int i;
    for (i = 0; i < 11; i++) cin>>a[i];

    for (i = 10; i >= 0; i--)
    {
        cout<<"f("<<a[i]<<") = ";
        y = f (a[i]);
        if (y > 400)
            cout<<"MAGNA NIMIS!\n";
        else
        {
            cout<<fixed<<setprecision(2)<<y<<"\n";
        }
    }

    return 0;
}