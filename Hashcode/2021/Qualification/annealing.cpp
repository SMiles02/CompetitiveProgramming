#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NUM = 120000, INF = 1e9, X = 2*INF;
int score, newScore;
int d,n,s,v,f,w,x,y,z,ed,trie[3000000][27],strNum[30000000],endP[100000],strLen[100000],journeyLen[1000],strUse[100000],curAt[1000],curPointAt[100000],timeAtCur[100000];
vector<int> carPath[1000], strAtInt[100000], times[100000];
string str[100000],tp;
queue<int> q[100000];
queue<array<int,2>> passing[100000];
double t=50; //starting temperature

double rnd()
{
    return double(rng()%X)/X;
}

void addStreet(int i)
{
    cin>>x>>endP[i];
    strAtInt[endP[i]].push_back(i);
    cin>>str[i];
    cin>>strLen[i];
    z=0;
    w=str[i].size();
    for (int j=0;j<w;++j)
    {
        if (str[i][j]=='-')
        {
            if (!trie[z][26])
                trie[z][26]=++ed;
            z=trie[z][26];
        }
        else
        {
            if (!trie[z][str[i][j]-'a'])
                trie[z][str[i][j]-'a']=++ed;
            z=trie[z][str[i][j]-'a'];
        }
    }
    strNum[z]=i;
}

void addCar(int i)
{
    cin>>journeyLen[i];
    carPath[i].resize(journeyLen[i]);
    for (int j=0;j<journeyLen[i];++j)
    {
        cin>>tp;
        z=0;
        for (auto idx : tp)
        {
            if (idx=='-')
                z=trie[z][26];
            else
                z=trie[z][idx-'a'];
        }
        carPath[i][j]=strNum[z];
        ++strUse[strNum[z]];
        //cout<<strNum[z]<<" ";
    }
    //cout<<"\n";
}

int randRange(int l, int r)
{
    return uniform_int_distribution<int>(l,r)(rng);
}

int calc()
{
    for (int i=0;i<n;++i)
    {
        while (!passing[i].empty())
            passing[i].pop();
        while (!q[i].empty())
            q[i].pop();
        curPointAt[i]=0;
        timeAtCur[i]=0;
    }
    for (int i=0;i<v;++i)
    {
        curAt[i]=1;
        q[carPath[i][0]].push(i);
    }
    int rtn = 0;
    for (int i=0;i<=d;++i)
        for (int j=0;j<n;++j)
        {
            for (int k : strAtInt[j])
            {
                if (!passing[k].empty()&&i>=passing[k].front()[1])
                {
                    if (++curAt[passing[k].front()[0]]==journeyLen[passing[k].front()[0]])
                    {
                        //cerr << passing[k].front()[0] << " reached at time " << i << "\n";
                        rtn+=f+d-i;
                    }
                    else
                    {
                        //cerr << passing[k].front()[0] << " moves to " << str[k] << " at time " << i << "\n";
                        q[k].push(passing[k].front()[0]);
                    }
                    passing[k].pop();
                }
                //if (!q[k].empty())
                //    cerr << "front of " << str[k] << " at time " << i << " is " << q[k].front() << "\n";
            }
            if (!q[strAtInt[j][curPointAt[j]]].empty())
            {
                z = carPath[q[strAtInt[j][curPointAt[j]]].front()][curAt[q[strAtInt[j][curPointAt[j]]].front()]];
                passing[z].push({q[strAtInt[j][curPointAt[j]]].front(),i+strLen[z]});
                q[strAtInt[j][curPointAt[j]]].pop();
            }
            if (++timeAtCur[j]==times[j][curPointAt[j]])
            {
                timeAtCur[j]=0;
                if (++curPointAt[j]==sz(strAtInt[j]))
                    curPointAt[j]=0;
            }
        }
    return rtn;
}

bool cmp(int& X, int Y)
{
    if (strUse[X]>strUse[Y])
        return 1;
    return 0;
}

void buildFirst()
{
    for (int i=0;i<n;++i)
    {
        sort(strAtInt[i].begin(), strAtInt[i].end(), cmp);
        while (!strAtInt[i].empty()&&strUse[strAtInt[i].back()]==0)
            strAtInt[i].pop_back();
        for (int j=sz(strAtInt[i]);j>0;--j)
            times[i].push_back(1);
        sort(times[i].rbegin(), times[i].rend());
    }
}

void tryIncrease()
{
    int x=randRange(0,n-1),a;
    a=randRange(0,sz(strAtInt[x])-1);
    if (times[x][a]==d)
        return;
    ++times[x][a];
    newScore=calc();
    if (newScore>=score||rnd()<exp((newScore-score)/t))
    {
        score=newScore;
        return;
    }
    --times[x][a];
}

void trySwap()
{
    int x=randRange(0,n-1),a;
    a=randRange(0,sz(strAtInt[x])-1);
    if (a>0)
        swap(strAtInt[x][a],strAtInt[x][a-1]);
    else if (a+1<sz(strAtInt[x]))
        swap(strAtInt[x][a],strAtInt[x][a+1]);
    else
        return;
    newScore=calc();
    if (newScore>=score||rnd()<exp((newScore-score)/t))
    {
        score=newScore;
        return;
    }
    if (a>0)
        swap(strAtInt[x][a],strAtInt[x][a-1]);
    else if (a+1<sz(strAtInt[x]))
        swap(strAtInt[x][a],strAtInt[x][a+1]);
}

void printAns(string filename)
{
    cerr << "Score in " << filename << ": " << score << "\n";
    string file = "out/file_" + filename + ".out";
    freopen(file.c_str(), "w", stdout);
    int ans=0;
    for (int i=0;i<n;++i)
        if (!strAtInt[i].empty())
            ++ans;
    cout << ans << "\n";
    for (int i=0;i<n;++i)
        if (!strAtInt[i].empty())
        {
            z = strAtInt[i].size();
            cout << i << "\n" << z << "\n";
            for (int j=0;j<z;++j)
                cout << str[strAtInt[i][j]] << " " << times[i][j] << "\n";
        }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("b3.in", "r", stdin);
    cin>>d>>n>>s>>v>>f;
    for (int i=0;i<s;++i)
        addStreet(i);
    for (int i=0;i<v;++i)
        addCar(i);
    buildFirst();
    score=calc();
    printAns("ans");
    return 0;
    const int iterations = 0;
    //const int printFreq = 2;
    //this will create (printFreq) number
    //of intermediate output files
    int duk_orz;   
    //double mpl = pow((1e-5)/t,(double)1/iterations);
    for (int i=0;i<iterations;++i)
    {
        //t*=mpl;
        duk_orz=randRange(1,1);
        if (duk_orz==0)
            trySwap();
        else
            tryIncrease();
        //if (i%(iterations/printFreq)==0)
        //    printAns(to_string(i/(iterations/printFreq)));
    }
    printAns("ans");
    return 0;
}