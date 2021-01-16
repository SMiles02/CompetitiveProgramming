#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mn = (2<<9), INF = 1e9;
int done[mn][mn];
bitset<mn> selected;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,K,p,x,y;
    cin>>N;
    /**
    For any N:
    K = 2^N - 1
    n = 2^(N-1) - 1
    m = 2^(N-1)
    **/
    K = (1<<N) - 1;
    cout << K << "\n";
    for (int i=1;i<=(1<<N);++i)
        done[i][i]=INF;
    while (K--)
    {
        p = (1<<(N-1))-1;
        selected.reset();
        y=INF;
        x=1;
        vector<int> v = {x};
        selected[x]=1;
        //cout<<"x = "<<x<<"\n";
        while (p--)
        {
            vector<int> w,q;
            for (int i=1;i<=(1<<N);++i)
                if (!selected[i])
                    w.push_back(i);
            shuffle(v.begin(), v.end(), rng);
            for (int j : v)
            {
                y=INF;
                for (int i : w)
                    y=min(y,done[i][j]);
                for (int i : w)
                    if (done[i][j]==y)
                        q.push_back(i);
                w=q;
                q.clear();
            }
            x=w[0];
            v.push_back(x);
            //cout<<x<<" "<<y<<" added\n";
            selected[x]=1;
        }
        for (int i=1;i<=(1<<N);++i)
        {
            if (selected[i])
            {
                cout<<"A";
                for (int j=1;j<i;++j)
                    if (selected[j])
                    {
                        ++done[i][j];
                        ++done[j][i];
                    }
            }
            else
            {
                cout<<"B";
                for (int j=1;j<i;++j)
                    if (!selected[j])
                    {
                        ++done[i][j];
                        ++done[j][i];
                    }
            }
        }
        cout<<"\n";
    }
    for (int i=1;i<=(1<<N);++i)
    {
        for (int j=1;j<=(1<<N);++j)
            if (i!=j)
                cout<<done[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}