#include <bits/stdc++.h>
#include "grader.h"
#include "memory.h"
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void play()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<char,vector<int>> m;
    char c;
    for (int i=1;i<51;++i)
    {
        c=faceup(i);
        m[c].push_back(i);
    }
    for (char j='A';j<'Z';++j)
    {
        c=faceup(m[j][0]);
        c=faceup(m[j][1]);
    }
    return;
}