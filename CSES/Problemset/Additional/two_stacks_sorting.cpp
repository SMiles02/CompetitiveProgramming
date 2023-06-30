#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cur = 1;
    cin >> n;
    stack<int> a, b;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (!a.empty() && k + 1 == a.top()) {
            ans.push_back(1);
            a.push(k);
        }
        else if (!b.empty() && k + 1 == b.top()) {
            ans.push_back(2);
            b.push(k);
        }
        else if (a.empty()) {
            ans.push_back(1);
            a.push(k);
        }
        else if (b.empty()) {
            ans.push_back(2);
            b.push(k);
        }
        else if (a.empty()) {
            ans.push_back(1);
            a.push(k);
        }
        else if (b.empty()) {
            ans.push_back(2);
            b.push(k);
        }
        else if (a.top() < b.top()) {
            ans.push_back(1);
            a.push(k);
        }
        else {
            ans.push_back(2);
            b.push(k);
        }
        while (true) {
            if (!a.empty() && a.top() == cur)
                a.pop();
            else if (!b.empty() && b.top() == cur)
                b.pop();
            else
                break;
            ++cur;
        }
    }
    if (a.size() + b.size() == 0)
        for (int i : ans)
            cout << i << " ";
    else
        cout << "IMPOSSIBLE";
    return 0;
}