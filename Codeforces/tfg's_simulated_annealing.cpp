#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <queue>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200100;

int n;
std::vector<int> edges[ms];
std::vector<std::pair<int, int>> ed;

struct Solution {
	int bad, actual;
	std::vector<bool> present;
	int cur;

	Solution() {
		present.assign(n, false);
		bad = cur = 0;
		actual = (int) ed.size();
	}

	void flip(int x) {
		int got = present[x] ? 1 : -1;
		for(auto y : edges[x]) {
			if(present[y]) {
				bad -= got;
			} else {
				actual += got;
			}
		}
		cur -= got;
		present[x] = !present[x];
	}
};

Solution best;

void fix(Solution &cur, int rep = 10) {
	std::cerr << "starting as (" << cur.cur << ", " << cur.bad << ")" << std::endl;
	while(rep--) {
		for(int i = 0; i < n; i++) {
			if(cur.present[i]) continue;
			int prv[2] = {cur.cur, cur.bad};
			cur.flip(i);
			if(prv[1] < cur.bad) {
				cur.flip(i);
			}
		}
		//std::cerr << "first as (" << cur.cur << ", " << cur.bad << ")" << std::endl;
		for(int i = 0; i < n; i++) {
			if(!cur.present[i]) continue;
			int prv[2] = {cur.cur, cur.bad};
			cur.flip(i);
			if(prv[1] <= cur.bad) {
				cur.flip(i);
			}
		}
		//std::cerr << "second as (" << cur.cur << ", " << cur.bad << ")" << std::endl;
		assert(cur.bad == 0);
		for(int i = 0; i < n; i++) {
			if(cur.present[i]) continue;
			cur.flip(i);
			if(cur.bad != 0) {
				cur.flip(i);
			}
		}
		//std::cerr << "third as (" << cur.cur << ", " << cur.bad << ")" << std::endl;
		assert(cur.bad == 0);
		std::vector<std::vector<int>> only(n);
		for(int i = 0; i < n; i++) {
			if(!cur.present[i]) {
				std::vector<int> wtf;
				for(auto to : edges[i]) {
					if(cur.present[to]) {
						wtf.push_back(to);
					}
				}
				assert(!wtf.empty());
				if((int) wtf.size() == 1) {
					only[wtf[0]].push_back(i);
				}
			}
		}
		bool run = false;
		for(int i = 0; i < n && !run; i++) {
			for(int j = 0; j < (int) only[i].size() && j < 1000 && !run; j++) {
				for(int k = j+1; k < (int) only[i].size() && !run; k++) {
					int u = only[i][j], v = only[i][k];
					auto it = std::lower_bound(edges[u].begin(), edges[u].end(), v);
					if(it == edges[u].end() || *it != v) {
						assert(cur.present[i] && !cur.present[u] && !cur.present[v] && !run);
						run = true;
						cur.flip(i);
						cur.flip(u);
						cur.flip(v);
						assert(cur.bad == 0);
					}
				}
			}
		}
		//std::cerr << "fourth as (" << cur.cur << ", " << cur.bad << ")" << std::endl;
		if(!run) break;
	}
	std::cerr << "ending as (" << cur.cur << ", " << cur.bad << ")" << std::endl;
	if(cur.bad == 0 && cur.cur > best.cur) {
		best = cur;
	}
}

Solution greedy() {
	Solution cur;
	std::vector<int> deg(n, 0);
	for(auto e : ed) {
		deg[e.first]++;
		deg[e.second]++;
	}
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> hp;
	for(int i = 0; i < n; i++) {
		hp.push(std::pair<int, int>(deg[i], i));
	}
	while(!hp.empty()) {
		int on = hp.top().second;
		int d = hp.top().first;
		hp.pop();
		if(d != deg[on]) continue;
		cur.flip(on);
		deg[on] = -1;
		for(auto to : edges[on]) {
			if(deg[to] != -1) {
				deg[to] = -1;
				for(auto u : edges[to]) {
					if(deg[u] != -1) {
						deg[u]--;
						hp.push(std::pair<int, int>(deg[u], u));
					}
				}
			}
		}
	}
	fix(cur);
	assert(cur.bad == 0);
	return cur;
}

int inter(const std::set<int> &a, const std::set<int> &b) {
	if(a.size() > b.size()) {
		return inter(b, a);
	}
	int ans = 0;
	for(auto x : a) {
		ans += b.count(x);
	}
	return ans;
}

void go(int alpha, int beta) {
	Solution cur;
	std::vector<int> deg(n, 0);
	std::vector<std::set<int>> graph(n);
	for(auto e : ed) {
		graph[e.first].insert(e.second);
		graph[e.second].insert(e.first);
		deg[e.first]++;
		deg[e.second]++;
	}
	std::set<std::pair<int, int>> cands;
	for(int i = 0; i < n; i++) {
		cands.insert(std::pair<int, int>(deg[i], i));
	}
	while(!cands.empty()) {
		//std::cerr << "remaining " << cands.size() << " candidates" << std::endl;
		long long kek[] = {(long long) -1e18, -1};
		int rep = 1000;
		for(auto wtf : cands) {
			rep--;
			if(rep == 0) break;
			int on = wtf.second;
			long long value = ((int) cands.size() - 1 - (int) graph[on].size()) * alpha + (int) graph[on].size() * beta;
			std::set<int> curAdj;
			for(auto to : graph[on]) {
				value += deg[to];
			}
			curAdj.insert(on);
			for(auto to : graph[on]) {
				if(value <= kek[0]) {
					break;
				}
				value -= inter(graph[to], curAdj) * beta;
				curAdj.insert(to);
			}
			if(value > kek[0]) {
				kek[1] = on;
				kek[0] = value;
			}
		}
		int rem = (int) kek[1];
		std::vector<int> wtf(1, rem);
		for(auto to : graph[rem]) wtf.push_back(to);
		cur.flip(rem);
		for(auto on : wtf) {
			cands.erase(std::pair<int, int>(deg[on], on));
			deg[on] = -1;
		}
		for(auto on : wtf) {
			for(auto to : graph[on]) {
				if(deg[to] != -1) {
					cands.erase(std::pair<int, int>(deg[to]--, to));
					graph[to].erase(on);
					cands.insert(std::pair<int, int>(deg[to], to));
				}
			}
		}
	}
	fix(cur);
	assert(cur.bad == 0);
	if(cur.cur > best.cur) {
		best = cur;
	}
}

long double getDeg(int i) { return (long double) edges[i].size() / ed.size(); }

long double heuristic(Solution &cur, long double temp) {
	const long double alpha = 1, beta = 0;
	return cur.cur - alpha * cur.bad - beta * cur.actual;
}

std::vector<int> swappingPoints;
int threshold[ms];

bool anneal(Solution &cur, long double temp) {
	//if(swappingPoints.empty()) return false;
	long double delta = -heuristic(cur, temp);
	int id = std::uniform_int_distribution<int>(0, n - 1)(rng);
	//std::swap(swappingPoints[id], swappingPoints.back());
	//id = swappingPoints.back();
	cur.flip(id);
	if(cur.bad == 0 && cur.cur > best.cur) {
		best = cur;
	}
	delta += heuristic(cur, temp);
	if(delta < 0 && expl(delta * (1 + (cur.present[id] ? getDeg(id) : -getDeg(id))) / temp) < std::uniform_real_distribution<long double>(0, 1)(rng)) {
		//if(expl(delta * (1 + (cur.present[id] ? getDeg(id) : -getDeg(id))) / temp) < 0.01) threshold[id]++;
		//if(threshold[id] > 200) {
		//	swappingPoints.pop_back();
		//}
		cur.flip(id);
		return false;
	} else {
		//threshold[id] = 0;
		return true;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m;
	std::cin >> n >> m;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		ed.emplace_back(u, v);
	}
	for(int i = 0; i < n; i++) {
		std::sort(edges[i].begin(), edges[i].end());
	}
	std::sort(ed.begin(), ed.end());
	assert((int) (std::unique(ed.begin(), ed.end()) - ed.begin()) == (int) ed.size());
	if(0) {
		int trash;
		std::cin >> trash;
		Solution cur;
		for(int i = 0; i < n; i++) {
			int t;
			std::cin >> t;
			if(t) {
				cur.flip(i);
			}
		}
		fix(cur);
		std::cout << best.cur << '\n';
		for(int i = 0; i < n; i++) {
			std::cout << (best.present[i] ? 1 : 0) << (i + 1 == n ? '\n' : ' ');
		}
		return 0;
	}
	//best = greedy();
	go(10, 1);
	for(int rep = 0; rep < 1; rep++) {
		//break;
		Solution cur;
		for(int i = 0; i < n; i++) {
			if(rng() % 2) {
				break;
				cur.flip(i);
			}
		}
		if(0) {
			const int tot = 1e8;
			const long double maxT = 10;
			for(int i = 0; i < tot; i++) {
				long double T = maxT * (tot - i) / tot;
				if(i % 1000000 == 0) {
					std::cerr << "at " << i << " with (" << cur.cur << ", " << cur.bad << ", " << cur.actual << "), temp " << T << std::endl;
				}
				anneal(cur, T);
			}
		} else {
			const int tot = 2e6;
			const long double alpha = 0.98;
			swappingPoints.clear();
			for(int i = 0; i < n; i++) {
				swappingPoints.push_back(i);
				threshold[i] = 0;
			}
			long double T = 0.0001;
			int row = 0;
			while(row < 100) {
				auto delta = -heuristic(cur, T);
				int run = 0;
				for(int i = 0; i < tot; i++) {
					if(anneal(cur, T)) {
						run++;
						if(heuristic(cur, T) > heuristic(best, T)) {
							best = cur;
							fix(best, n);
						}
					}
				}
				delta += heuristic(cur, T);
				std::cerr << "delta was " << delta << ", got " << heuristic(cur, T) << " with (" << cur.cur << ", " << cur.bad << "), temp " << T << ", " << row << " in a row and " << swappingPoints.size() << " candidates" << std::endl;
				if(!run) break;
				if(delta > 0) {
					row = 0;
				} else {
					row++;
				}
				T *= alpha;
			}
		}
		std::cerr << "ended with (" << cur.cur << ", " << cur.bad << ", " << cur.actual << ")" << std::endl;
		fix(cur, n);
		std::cerr << "ended with (" << cur.cur << ", " << cur.bad << ", " << cur.actual << ")" << std::endl;
	}
	fix(best, n);
	std::cout << best.cur << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << (best.present[i] ? 1 : 0) << (i + 1 == n ? '\n' : ' ');
	}
}