#include<iostream>
#include<cstring>
#include<queue>
#include <iomanip>
using namespace std;
bool r[21][21];
int cnt = 1;
int dis[21];

void bfs(int s,int d) {
	queue< int > q;
	memset(dis, -1, sizeof(dis));
	dis[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == d) {
			break;
		}
		for (int i = 1;i <= 20;i++) {

			if (r[u][i] == 1 && dis[i]==-1) {
				q.push(i);
				dis[i] = dis[u] + 1;
			}
			
			
		}
		
	}
	cout << setw(2) << setfill(' ')<<s << " to " << setw(2) << setfill(' ')<< d << ": " << dis[d]<<endl;
}
void cal() {
	int c,s,d;
	cin >> c;
	cout << "Test Set #" << cnt << endl;
	for (int i = 0;i < c;i++) {
		cin >> s >> d;
		bfs(s, d);
	}
	cnt++;
	cout << endl;
}
int main() {
	int u,t;
	cin >> u;
	while (!cin.eof()) {
		memset(r, 0,sizeof(r));
		
		for (int i = 1;i <= u;i++) {
			cin >> t;
			r[1][t] = 1;
			r[t][1] = 1;
		}
		for (int i = 2;i <= 19;i++) {
			cin >> u;
			for (int j = 0;j < u;j++) {
				cin >> t;
				r[i][t] = 1;
				r[t][i] = 1;
			}
		}
		cal();
		cin >> u;
	}
	
	return 0;
}
