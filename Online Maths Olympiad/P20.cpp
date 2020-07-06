#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[5];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cur=0;
    while (!(a[0]==9&&a[1]==8&&a[2]==7&&a[3]==6&&a[4]==5))
    {
        for (int i=0;i<5;++i)
        {
            if (a[i]==a[4])
            {
                ++a[i];
                for (int j=i+1;j<5;++j)
                {
                    a[j]=0;
                }
                break;
            }
        }
        ++cur;
        cout<<cur<<" "<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<"\n";
    }
    cout<<cur;
    return 0;
}