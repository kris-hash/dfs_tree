#include <iostream>
#include<fstream>

using namespace std;

int g[1000][1000];
bool visited[1000];

void dfs(int v, int n) {
	if (visited[v] == true)
		return;
	visited[v] = true;
	for (int i = 0; i < n; i++)
	{
		if (g[v][i] == true)
		{
			dfs(i, n);
		}
	}
	return;
}

int main() {
	ifstream f1("input.txt");
	ofstream f2("output.txt");
	int n, m;
	f1 >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		f1 >> a >> b;
		a--; b--;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	dfs(0, n);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			f2 << "NO";
			return 0;
		}
	}

	bool b = true;
	bool e = (m - n + 1) == false; // auf_1_weniger
	if (b && e) {

		f2 << "YES" << endl;
	}
	else {
		f2 << "NO" << endl;
	}

	return 0;
}