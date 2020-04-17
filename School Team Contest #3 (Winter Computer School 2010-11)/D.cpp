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
	vector<pair<int,pii > > timestamp(n);
	for (int i = 0; i < n; i++){
		cin >> timestamp[i].S.F >> timestamp[i].F;
		timestamp[i].S.S = i;
	}
	vi ans(n);
	sort(all(timestamp));
	set<int> mark;
	for (int i = 0; i < n; i++){
		int date = timestamp[i].S.F;
		while(mark.count(date)){
			date++;
		}
		mark.insert(date);
		ans[timestamp[i].S.S] = date;
	}
	for(auto date : ans){
		cout << date << " ";
	}
	cout << endl;
	return 0;
}

