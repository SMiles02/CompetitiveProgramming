#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<char> letters = {'A','B','C','D'};
vector<char> others = {'B','A','D','C'};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,w=1,x=1,y=1,z=1;
    cin>>a>>b>>c>>d;
    char ans[48][50];
    for (int i=0;i<48;++i)
        for (int j=0;j<50;++j)
            ans[i][j]=letters[i/12];
    for (int i=0;i<12;i+=2)
        for (int j=0;j<50;j+=2)
            if (x<b)
            {
                ans[i][j]='B';
                ++x;
            }
    for (int i=13;i<24;i+=2)
        for (int j=0;j<50;j+=2)
            if (w<a)
            {
                ans[i][j]='A';
                ++w;
            }
    for (int i=24;i<36;i+=2)
        for (int j=0;j<50;j+=2)
            if (z<d)
            {
                ans[i][j]='D';
                ++z;
            }
    for (int i=37;i<48;i+=2)
        for (int j=0;j<50;j+=2)
            if (y<c)
            {
                ans[i][j]='C';
                ++y;
            }
    cout<<"48 50\n";
    for (int i=0;i<48;++i)
    {
        for (int j=0;j<50;++j)
            cout<<ans[i][j];
        cout<<"\n";
    }
    return 0;
}