#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
int matriz[100][100];
int visitados[101];

int exist = 0;

void dfs(int u, int v){
	
	if(visitados[u]) return;
	if(u == v){ exist = 1; return; }
	else{
		visitados[u] = 1;

		for(int i = 0; i < m + 5; i++){
			if(matriz[u][i]) dfs(i, v);
		}
	}

}

int main()
{

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++) matriz[i][j] = 0;
	}
	for(int i = 0; i < 101; i++) visitados[i] = 0;

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> u >> v;
		matriz[u][v] = 1;
		matriz[v][u] = 1;
	}

	cin >> u >> v;
	dfs(u, v);

	if(exist) cout << "EXISTE\n";
	else cout << "NAO EXISTE\n";



	return 0;
}