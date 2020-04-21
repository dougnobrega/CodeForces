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
ll A, B, n;
ll calculateSum(ll l, ll r){
	ll first = (r - l + 1)*A ;
	ll second = B*(((l-1 + r-1)*(r - l + 1))/2);
	return first + second;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> A >> B >> n;
	for (int i = 0; i < n; i++){
		ll l, t, m;
		cin >> l >> t >> m;
		ll lo = l, hi = 1000010, mid;
		while(lo <= hi){
			mid = (lo + hi)/2;			
			if(A + (mid-1)*B <= t && calculateSum(l, mid) <= t*m){
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}
		if(lo == l) lo = 0;
		cout << lo - 1 << endl;
	}
	
	return 0;
}

