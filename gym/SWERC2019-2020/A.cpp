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
struct Edge{
	pii p;
	ll co2 = 0;
	ll km = 0;
	ll idx = 0;
	Edge(){
	}
	
	Edge(pii p){
		this->p = p;
		this->idx = indexP();
	}
	
	Edge(pii p, ll co2, ll km){
		this->p = p;
		this->co2 = co2;
		this->km = km;
		this->idx = indexP();
	}
	
	Edge(ll idx, ll co2, ll km){
		this->idx = idx;
		this->co2 = co2;
		this->km = km;
	}
	
	ll indexP(){
		return p.F*101 + p.S;
	}
	
	ll my_sqrt(ll x){
		ll ans = max(1LL, (ll)sqrt(x)-2);
		while(ans*ans < x)
			ans++;
		return ans;
	}
	
	ll distance(pii b){
		return my_sqrt((b.F-p.F)*(b.F-p.F) + (b.S-p.S)*(b.S-p.S));
	}
	
};

struct classcomp {
    bool operator() (const Edge& lhs, const Edge& rhs) const{
		if(lhs.co2 == rhs.co2)
			return lhs.km > rhs.km;
		return lhs.co2 > rhs.co2;
	}
};

Edge destination;
int limitKm;
int costPerKm[110];
pii stations[1010];
vector<pii> links[1010];

ll co2Calculated[13010][101];
vector<Edge> g[13010];

ll dijkstra(int idx){
	memset(co2Calculated, 0x3f, sizeof(co2Calculated));
	
	priority_queue<Edge, vector<Edge>, classcomp> pq;
	
	pq.push(Edge(idx, 0LL, 0LL));
		
	co2Calculated[idx][0] = 0;
	
	while(!pq.empty()){
		Edge u = pq.top();
		pq.pop();
		for(Edge to : g[u.idx]){
			ll new_km = u.km + to.km;
			if(new_km > limitKm)
				continue;
			
			if(co2Calculated[to.idx][new_km] > u.co2 + to.co2){
				co2Calculated[to.idx][new_km] = u.co2 + to.co2;
				 
				pq.push(Edge(to.idx, co2Calculated[to.idx][new_km], new_km));
			}
		}
	}
	
	ll ans = INFLL;
	for(int i=0; i<=limitKm; i++)
		ans = min(ans, co2Calculated[destination.idx][i]);	
	
	return ans < INFLL ? ans : -1 ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Edge home;
	cin >> home.p.F >> home.p.S;
	cin >> destination.p.F >> destination.p.S;
	
	home.idx = home.indexP();
	destination.idx = destination.indexP();
	
	cin >> limitKm;
	cin >> costPerKm[0];
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> costPerKm[i];
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> stations[i].F >> stations[i].S;
		
		int qtdLinks;
		
		cin >> qtdLinks;
		
		links[i].resize(qtdLinks);
		
		for (int j = 0; j < qtdLinks; j++){
			cin >> links[i][j].F >> links[i][j].S;
		}
	}
	
	for(int i=0; i<n; i++){
		int l = links[i].size();
		ll km = destination.distance(stations[i]);
		ll co2 = costPerKm[0] * km;
		g[Edge(stations[i]).indexP()].emplace_back(destination.p, co2, km);
		
		km = home.distance(stations[i]);
		co2 = costPerKm[0] * km;
		g[home.indexP()].emplace_back(stations[i], co2, km);
		
		for(int j = 0; j < l; j++){
			int m = links[i][j].F, tp = links[i][j].S;
			
			km = Edge(stations[i]).distance(stations[m]);
			co2 = costPerKm[tp] * km; 
			
			g[Edge(stations[i]).idx].emplace_back(stations[m], co2, km);		
		 	g[Edge(stations[m]).idx].emplace_back(stations[i], co2, km);
		}		
	}
	
	ll km = home.distance(destination.p);
	ll co2 = costPerKm[0] * km;
	
	g[home.idx].emplace_back(destination.p, co2, km);
	
	cout << dijkstra(home.indexP()) << endl;
	
	return 0;
}

