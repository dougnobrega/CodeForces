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
ll mat[1001][1001];

ll getCost(vll& cost, int mid){
	ll ans = 0;
	for (int i = 0; i < (int) cost.size(); i++){
		ll dist = abs((i - mid)*4  + 2);
		ans += cost[i] * dist * dist;
	}
	return ans;
}

int binarySearch(vll& cost){
	int lo = 0, hi = cost.size(), mid;
	while(lo < hi){
		mid = (lo+hi)>>1;
		if(getCost(cost, mid) <= getCost(cost, mid + 1)){
			hi = mid;
		}else{
			lo = mid + 1;
		}
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vll sum_row(n);
	vll sum_collumn(m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
			sum_row[i] += mat[i][j];
			sum_collumn[j] += mat[i][j];
		}
	}
	pii idx = {binarySearch(sum_row), binarySearch(sum_collumn)};
	cout << getCost(sum_row, idx.F) + getCost(sum_collumn, idx.S) << endl;
	cout << idx.F << " " << idx.S << endl;
	return 0;
}

