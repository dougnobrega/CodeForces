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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	set<pair<int,pii> > segment, order;
	for (int i = 0; i < n; i++){
		int j = i;
		while(j < n and v[i] == v[j]) j++;
		order.insert(MP(-(j-i), MP(i, v[i])));
		segment.insert(MP(i, MP(-(j-i), v[i])));
		i = j - 1;
	}
	int ans = 0;
	W(segment.size());
	while(!segment.empty()){
		int sz, pos, val;
		sz = (*order.begin()).F;
		pos = (*order.begin()).S.F;
		val = (*order.begin()).S.S;
		order.erase(order.begin());
		auto it2 = segment.find(MP(pos, MP(sz, val)));
		
		it2 = segment.erase(it2);
		ans++;
		if(it2 != segment.begin() && it2 != segment.end()){
			auto it = prev(it2);
			if(it->S.S == it2->S.S){
				int pos1 = it->F;
				int sz1 = it->S.F;
				int val1 = it->S.S;
				order.erase(MP(sz1, MP(pos1,val1)));
				segment.erase(it);
				
				int pos2 = it2->F;
				int sz2 = it2->S.F;
				int val2 = it2->S.S;		
				order.erase(MP(sz2, MP(pos2,val2)));
				segment.erase(it2);
				
				order.insert(MP(sz1 + sz2, MP(pos1, val1)));
				segment.insert(MP(pos1, MP(sz1 + sz2, val1)));
				
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
