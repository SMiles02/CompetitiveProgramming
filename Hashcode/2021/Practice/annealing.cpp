#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//let NUM = total number of teams
//i.e. t2+t3+t4
const int NUM = 120000, INF = 1e9, X = 2*INF;
ll score, newScore;
int n,m,t2,t3,t4,k;
vector<vector<string>> pizzas;
set<string> diff;
vector<int> teams, given[NUM];
deque<int> usedT,unusedT,unusedP;
double t=50; //starting temperature

double rnd()
{
    return double(rng()%X)/X;
}

ll square(int x)
{
    return x*x;
}

ll calc(int x)
{
    diff.clear();
    for (int i : given[x])
        for (auto j : pizzas[i])
            diff.insert(j);
    return square(diff.size());
}

void buildFirst()
{
    vector<int> pIndex(m);
    for (int i=0;i<t2;++i)
        teams.push_back(2);
    for (int i=0;i<t3;++i)
        teams.push_back(3);
    for (int i=0;i<t4;++i)
        teams.push_back(4);
    iota(pIndex.begin(), pIndex.end(), 0);
    shuffle(pIndex.begin(), pIndex.end(), rng);
    shuffle(teams.begin(), teams.end(), rng);
    int k=0;
    for (int i=0;i<n;++i)
    {
        if (k+teams[i]<=m)
        {
            usedT.push_back(i);
            diff.clear();
            for (int j=k;j<k+teams[i];++j)
                given[i].push_back(pIndex[j]);
            score+=calc(i);
            k+=teams[i];
        }
        else
            unusedT.push_back(i);
    }
    for (int j=k;j<m;++j)
        unusedP.push_back(pIndex[j]);
}

void trySwap()
{
    int x,y=uniform_int_distribution<int>(0,sz(usedT)-1)(rng),a,b;
    x=y;
    while (x==y)
        y=uniform_int_distribution<int>(0,sz(usedT)-1)(rng);
    a=uniform_int_distribution<int>(0,teams[usedT[x]]-1)(rng);
    b=uniform_int_distribution<int>(0,teams[usedT[y]]-1)(rng);
    newScore=score;
    newScore-=calc(x);
    newScore-=calc(y);
    swap(given[x][a],given[y][b]);
    newScore+=calc(x);
    newScore+=calc(y);
    if (newScore>=score||rnd()<exp((newScore-score)/t))
    {
        score=newScore;
        return;
    }
    swap(given[x][a],given[y][b]);
}

void tryAnother()
{
    int x=uniform_int_distribution<int>(0,sz(usedT)-1)(rng),a,b;
    a=uniform_int_distribution<int>(0,teams[usedT[x]]-1)(rng);
    b=uniform_int_distribution<int>(0,sz(unusedP)-1)(rng);
    newScore=score;
    newScore-=calc(x);
    swap(given[x][a],unusedP[b]);
    newScore+=calc(x);
    if (newScore>=score||rnd()<exp((newScore-score)/t))
    {
        score=newScore;
        return;
    }
    swap(given[x][a],unusedP[b]);
}

void printAns(string s)
{
    cerr << "Score in " << s<< ": " << score << "\n";
    string file = "out/file_" + s + ".out";
    freopen(file.c_str(), "w", stdout);
    cout<<sz(usedT)<<"\n";
    for (int i : usedT)
    {
        cout<<teams[i]<<" ";
        for (int j : given[i])
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("b3.in", "r", stdin);
    cin>>m>>t2>>t3>>t4;
    n=t2+t3+t4;
    int k;
    for (int i=0;i<m;++i)
    {
        cin>>k;
        vector<string> v(k);
        for (int j=0;j<k;++j)
            cin>>v[j];
        pizzas.push_back(v);
    }
    buildFirst();
    const int iterations = 10000000;
    const int printFreq = 1000;
    //this will create (printFreq) number
    //of intermediate output files   
    double mpl = pow((1e-5)/t,(double)1/iterations);
    for (int i=0;i<iterations;++i)
    {
        t*=mpl;
        k=uniform_int_distribution<int>(0,1)(rng);
        if (k==0)
            trySwap();
        else
            tryAnother();
        if (i%(iterations/printFreq)==0)
            printAns(to_string(i/(iterations/printFreq)));
    }
    // cout<<"Score: "<<score<<"\n";
    // cout<<fixed<<setprecision(10)<<"Final Temp: "<<t<<"\n";
    // cout<<"-------\n";
    printAns("ans");
    return 0;
}