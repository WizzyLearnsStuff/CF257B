#include<iostream>

using namespace std;

struct ret {
	int sc[2];
};

struct ret solve(int n, int m, int l) {
	if (n < m) swap(n, m);

	int sc[2] = {0};

	const int p = n + m;
	l == 1 ? n-- : m--;
	for (int i = 1; i < p; i++) {
		if (i % 2) {
			if (l > 0 && m > 0) {
				m--;
				sc[1]++;
				l = 1 - l;
			}
			else if (l == 0 && n > 0) {
				n--;
				sc[1]++;
				l = 1 - l;
			}
			else if (l > 0 && n > 0) {
				n--;
				sc[0]++;
			}
			else {
				m--;
				sc[0]++;
			}
		}
		else {
			if (l > 0 && n > 0) {
				n--;
				sc[0]++;
			}
			else if (l == 0 && m > 0) {
				m--;
				sc[0]++;
			}
			else if (l > 0 && m > 0) {
				m--;
				l = 1 - l;
				sc[1]++;
			}
			else {
				n--;
				l = 1 - l;
				sc[1]++;
			}
		}
	}

	ret r;
	r.sc[0] = sc[0];
	r.sc[1] = sc[1];
	return r;
}

int main() {
	int n, m;
	cin >> n >> m;

	ret t = solve(n, m, 1);
	ret b = solve(n, m, 0);

	if (t.sc[0] >= b.sc[0]) cout << t.sc[0] << ' ' << t.sc[1];
	else cout << b.sc[0] << ' ' << b.sc[1]; 	
}
