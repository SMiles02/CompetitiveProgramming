#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

class ThreeNeighbors
{
public:
    vector<string> construct(int n)
    {
        int n;
        string s;
        vector<string> v;
        for (int i=0;i<48;++i)
        {
            s="";
            for (int j=0;j<48;++j)
            {
                s+='.';
            }
            v.push_back(s);
        }
        for (int i=0;i<48;i+=4)
        {
            for (int j=0;j<48;j+=4)
            {
                if (n)
                {
                    v[i+1][j]='X';
                    v[i][j+1]='X';
                    v[i][j+2]='X';
                    --n;
                }
                if (n)
                {
                    v[i+1][j+3]='X';
                    --n;
                }
                if (n)
                {
                    v[i+1][j+3]='X';
                    --n;
                }
                if (n)
                {
                    v[i+1][j+3]='X';
                    --n;
                }
            }
        }
        return;
    }
};