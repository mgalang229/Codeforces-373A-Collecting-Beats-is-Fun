#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	int n = 4;
	vector<vector<char>> a(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	// count the number of frequency of every digit because this will determine 
	// the number of panels that Cucumber boy needs to press every time 'i'
	// if there exists a time 'i' wherein the number of panels that Cucumber boy needs to
	// press is STRICTLY greater than the number of panels that he can press using his two hands,
	// then it is impossible to press all the panels in perfect timing
	vector<int> counter(10, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != '.') {
				counter[a[i][j] - '0']++;
			}
		}
	}
	bool checker = true;
	for (int i = 0; i < (int) counter.size(); i++) {
		checker &= (counter[i] <= (2 * k));
	}
	cout << (checker ? "YES" : "NO") << '\n';
	return 0;
}
