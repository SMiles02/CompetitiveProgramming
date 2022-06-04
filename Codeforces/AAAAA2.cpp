#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x) {
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int wnext(int i, int t) {
    if (t == 0)
        return rand(i);
    if (t > 0)
        return max(rand(i), wnext(i, t - 1));
    if (t < 0)
        return min(rand(i), wnext(i, t + 1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = rand(99990, 100000);
    int t = 1000;
    int z = 1000000;
    
    vector<int> p(n);
    
    /* setup parents for vertices 1..n-1 */
    for(int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = wnext(i, t);
    
    cout << n << " " << n - 1 << endl;
    
    /* shuffle vertices 1..n-1 */
    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end(), rng);
    
    /* put edges considering shuffled vertices */
    vector<pair<int,int> > edges;
    for (int i = 1; i < n; i++)
        if (rand(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));
    
    /* shuffle edges */
    shuffle(edges.begin(), edges.end(), rng);
    
    for (int i = 1; i < n; i++) {
        cout << edges[i - 1].first + 1 << " " << edges[i - 1].second + 1 << " " << rand(1, z);
        cout << endl;
    }
}