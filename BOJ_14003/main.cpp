#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int N;
vl Aj;
vl L;
vl dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N;
	Aj = vl(N);
	L.reserve(N);
	dp = vl(N, -1);
	auto sidx = int{ 0 };
	auto dpnow = int{ -1 };
	for (auto i = 0; i < N; ++i) {
		cin >> Aj[i];

		if (0 == L.size()) {
			L.push_back(Aj[i]);
			dp[i] = L.size();
		}
		else {
			if (L.back() < Aj[i]) {
				L.push_back(Aj[i]);
				dp[i] = L.size();
			}
			else {
				auto pos = lower_bound(L.begin(), L.end(), Aj[i]);
				*pos = Aj[i];
				dp[i] = distance(L.begin(), pos) + 1;
			}
		}

		if (dpnow < dp[i]) {
			sidx = i;
			dpnow = dp[i];
		}
	}

	cout << L.size() << '\n';
	auto st = stack<int>{};
	st.push(Aj[sidx]);
	for (auto i = sidx - 1; 0 <= i; --i) {
		if (Aj[i] < Aj[sidx] &&
			dp[i] + 1 == dp[sidx]) {
			st.push(Aj[i]);
			sidx = i;
		}
	}

	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}