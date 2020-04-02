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
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
int dist[10003];
deque<pii> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dist,INF,sizeof dist);
	int n, m, k;
	cin >> n >> m >> k;
	vpi lights(k);
	int idx = 0;
	for (int i = 0; i < k; i++){
		cin >> lights[i].F >> lights[i].S;
		if(lights[i] == MP(1,1)) idx = i;
	}
	
	q.push_front(MP(0,idx));
	dist[idx] = 0;
	int ans = INF;
	while(!q.empty()){
		int d = q.front().F;
		idx = q.front().S;
		pii point = lights[idx];
		if(point == MP(n,m)) ans = min(dist[idx],ans);
		if(point.F == n-1 || point.F == n || point.S == m-1 || point.S == m) ans = min(ans,dist[idx]+1);
		q.pop_front();
		if(dist[idx] != d){
			continue;
		}
		for(int i = 0; i < k; i++){
			pii p = lights[i];
			if((abs(point.F - p.F) + abs(point.S - p.S)) <= 1 && dist[i] > dist[idx]){
				dist[i] = d ;
				q.push_front(MP(d,i));
			}else if(((abs(point.F - p.F) <= 2) || (abs(point.S - p.S) <= 2)) && dist[i] > dist[idx] + 1){
				dist[i] = d + 1;
				q.push_back(MP(d+1,i));
			}
		}
	}
	if(ans == INF){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
	return 0;
}

