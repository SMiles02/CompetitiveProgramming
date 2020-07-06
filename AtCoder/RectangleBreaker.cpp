#include<bits/stdc++.h>
#include<chrono>
#include<random>
using namespace std;
using namespace chrono;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T1, class T2> istream &operator>>(istream &in, pair<T1, T2> &P){
    in >> P.first >> P.second;
    return in;
}
template<class T1, class T2> ostream &operator<<(ostream &out, const pair<T1, T2> &P){
    out << "(" << P.first << ", " << P.second << ")";
    return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
    for(auto &x: arr)
    {
        in >> x;
    }
    return in;
}
template<class T> ostream &operator<<(ostream &out, const vector<T> &arr){
    for(auto &x: arr)
    {
        out << x << ' ';
        cout << "\n";
    }
    return out;
}
template<class T> istream &operator>>(istream &in, deque<T> &arr){
    for(auto &x: arr)
    {
        in >> x;
    }
    return in;
}
template<class T> ostream &operator<<(ostream &out, const deque<T> &arr){
    for(auto &x: arr)
    {
        out << x << ' ';
        cout << "\n";
    }
    return out;
}
mt19937 rnd(time(0));

int is_f(int x1,int x2,int x3,int x4){
    return x3<=x1&&x4>=x2;
}

string solve1(vector<vi> &abc)
{
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    x1=abc[0][0];
    y1=abc[0][1];
    x2=abc[0][2];
    y2=abc[0][3];
    x3=abc[1][0];
    y3=abc[1][1];
    x4=abc[1][2];
    y4=abc[1][3];
    x5=abc[2][0];
    y5=abc[2][1];
    x6=abc[2][2];
    y6=abc[2][3];
    bool f = false;
    if(x3 <= x1 && y3 <= y1 && x4>=x2 && y4>=y2)
    {
        f = true;
    }
    if(x5 <= x1 && y5 <= y1 && x6>=x2 && y6>=y2)
    {
        f = true;
    }
    if(x5 <= x1 && y5 <= y1 && x6 >= x2 && x4>=x2 && y4>=y2 && x3<=x1 && y6>=y3)
    {
        f = true;
    }
    if(x3 <= x1 && y3 <= y1 && x4 >= x2 && x6>=x2 && y6>=y2 && x5<=x1 && y4>=y5)
    {
        f = true;
    }
    if(x5 <= x1 && y5 <= y1 && y6 >= y2 && x4>=x2 && y4>=y2 && y3<=y1 && x6>=x3)
    {
        f = true;
    }      
    if(x3 <= x1 && y3 <= y1 && y4 >= y2 && x6>=x2 && y6>=y2 && y5<=y1 && x4>=x5)
    {
        f = true;
    }                         
    if(!f)
    {
        return "YES";
    }
    else return "NO";
}

string solve2(vector<vi> &r)
{
    vi temp;
    for(auto x: r) for(auto y: x) temp.push_back(y);
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    int n = temp.size();
    vi convert(1000001);
    for(int i = 0; i < n; i ++) convert[temp[i]] = i;
    vector<vi> mark(n, vi(n));
    for(int i = 1; i < 3; i ++){
        for(int x = convert[r[i][0]]; x < convert[r[i][2]]; x ++){
            for(int y = convert[r[i][1]]; y < convert[r[i][3]]; y ++){
                mark[x][y] ++;
            }
        }
    }
    for(int x = convert[r[0][0]]; x < convert[r[0][2]]; x ++){
        for(int y = convert[r[0][1]]; y < convert[r[0][3]]; y ++){
            if(!mark[x][y]){
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M;
    cin >> M;
    while(1){
        vector<vi> r(3, vi(4));
        for(auto &x: r){
            for(auto &y: x) y = rnd() % M;
            if(x[0] == x[2]) x[2] ++;
            else if(x[0] > x[2]) swap(x[0], x[2]);
            if(x[1] == x[3]) x[3] ++;
            else if(x[1] > x[3]) swap(x[1], x[3]);
        }
        if(solve1(r) != solve2(r)){
            cout << "Failed at\n " << r;
            cout << "Solve1 = " << solve1(r) << "\nSolve2 = " << solve2(r);
            return 0;
        }
    }
    return 0;
}