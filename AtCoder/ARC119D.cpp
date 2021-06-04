//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2501, INF = 1e9, X = 2*INF;
int n,m,k,r,c,R,C,score,x[N],y[N];
double t=50; //starting temperature
char ch;
bitset<N*N> b;
vector<array<int,2>> v;

double rnd()
{
    return double(rng()%X)/X;
}

int range(int ABC, int DEF)
{
    return uniform_int_distribution<int>(ABC,DEF)(rng);
}

void buildFirst()
{
    for (int i=0;i<k;++i)
    {
        b[i]=range(0,1);
        if (b[i]==0)
        {
            if (++x[v[i][0]]==1)
                ++r;
        }
        else if (++y[v[i][1]]==1)
            ++c;
    }
    score=r*m+c*n-r*c;
}

void tryFlip()
{
    int tg = range(0,k-1);
    R=r;C=c;
    if (b[tg]==0)
    {
        if (--x[v[tg][0]]==0)
            --R;
        if (++y[v[tg][1]]==1)
            ++C;
    }
    else
    {
        if (--y[v[tg][1]]==0)
            --C;
        if (++x[v[tg][0]]==1)
            ++R;
    }
    if (R*m+C*n-R*C>=score||rnd()<exp((R*m+C*n-R*C-score)/t))
    {
        score=R*m+C*n-R*C;
        r=R;
        c=C;
        b[tg]=1-b[tg];
        return;
    }
    if (b[tg])
    {
        --x[v[tg][0]];
        ++y[v[tg][1]];
    }
    else
    {
        ++x[v[tg][0]];
        --y[v[tg][1]];
    }
}

void printAns()
{
    // cerr << "Score in " << s<< ": " << score << "\n";
    // string file = "out/file_" + s + ".out";
    // freopen(file.c_str(), "w", stdout);
    // cout<<sz(usedT)<<"\n";
    // for (int i : usedT)
    // {
    //     cout<<teams[i]<<" ";
    //     for (int j : given[i])
    //         cout<<j<<" ";
    //     cout<<"\n";
    // }

    // cout << "Score: " << score << "\n";
    // cout << r << " " << c << "\n";
    cout<<k<<"\n";
    for (int i=0;i<k;++i)
    {
        if (b[i]==0)
            cout<<"X";
        else
            cout<<"Y";
        cout<<" "<<v[i][0]<<" "<<v[i][1]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("b3.in", "r", stdin);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            cin>>ch;
            if (ch=='R')
                v.push_back({i,j});
        }
    if (v.empty())
    {
        cout<<"0\n";
        return 0;
    }
    k=sz(v);
    buildFirst();
    const int iterations = 20000000;
    // const int printFreq = 1000;
    //this will create (printFreq) number
    //of intermediate output files   
    double mpl = pow((1e-5)/t,(double)1/iterations);
    for (int i=0;i<iterations;++i)
    {
        t*=mpl;
        tryFlip();
        // if (i%(iterations/printFreq)==0)
            // printAns(to_string(i/(iterations/printFreq)));
    }
    // cout<<"Score: "<<score<<"\n";
    // cout<<fixed<<setprecision(10)<<"Final Temp: "<<t<<"\n";
    // cout<<"-------\n";
    printAns();
    return 0;
}