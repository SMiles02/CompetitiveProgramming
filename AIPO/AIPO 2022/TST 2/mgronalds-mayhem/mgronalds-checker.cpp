#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, m;
vector<int> likes[N], w;

bool readAns(InStream& stream) {
    string resp = upperCase(stream.readToken("[Yy][Ee][Ss]|[Nn][Oo]", "YES/NO"));
    
    if (resp == "YES") {
        int cur;
        vector<int> servingsLeft = w;
        set<int> done;
        for (int i = 0; i < n; ++i) {
            cur = stream.readInt(1, n);
            if (done.count(cur))
                stream.quitf(_wa, "Person %d is listed twice.", cur);
            done.insert(cur);
            bool eaten = false;
            for (int j : likes[cur]) {
                if (servingsLeft[j]-- > 0)
                    eaten = true;
            }
            if (!eaten)
                stream.quitf(_wa, "Person %d doesn't get any food.", cur);
        }
        return true;
    }
    else {
        if (resp != "NO")
            stream.quitf(_fail, "resp is not YES/NO");
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	
	n = inf.readInt(); m = inf.readInt();
	for (int i = 1; i <= n; ++i) {
        int k, x;
        k = inf.readInt();
        while (k--) {
            x = inf.readInt();
            likes[i].push_back(x);
        }
    }
	w.resize(m + 1);
    for (int i = 1; i <= m; ++i)
        w[i] = inf.readInt();

	bool jans = readAns(ans);
	bool pans = readAns(ouf);
	
	if (jans && !pans)
        quitf(_wa, "Jury has the answer but participant has not");
	if (!jans && pans)
        quitf(_fail, "Participant has the answer but jury has not");
	
	quitf(_ok, "Same answers", n, m);
    return 0;
}