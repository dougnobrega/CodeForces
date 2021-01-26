#include <bits/stdc++.h>
using namespace std;
// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int dist[301][301];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> dist[i][j];
		}
	}
	int m;
	cin >> m;
	for (int i_ = 0; i_ < m; i_++){
		int x, y, c;
		cin >> x >> y >> c;
		x--, y--;
		dist[x][y] = min(dist[x][y], c);
		dist[y][x] = min(dist[y][x], c);
		ll ans = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][y] + dist[y][j]);
				dist[i][j] = min(dist[i][j], dist[i][y] + dist[y][x] + dist[x][j]);
				ans += dist[i][j];
			}
		}
		cout << ans / 2 << " ";
	}
	cout << endl; 
	
	return 0;
}

