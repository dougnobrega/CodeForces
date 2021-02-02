#include <bits/stdc++.h>

using namespace std;

// Prioridade
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)*(b))/__gcd((a), (b)))

// fim da Prioridade
ll k, n;
bool check(ll x){
	return ((k + k-x-1)*(x))>>1LL >= n-1LL;
}
int main(){
	cin >> n >> k;
	ll lo = 0, hi = k, mid = 0;
	while(lo <= hi){
		mid = (lo+hi)>>1LL;
		if(check(mid)){
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}if(lo >= k){
		cout << -1 << endl;
		return 0;
	}
	cout << lo << endl;
	return 0;
}
