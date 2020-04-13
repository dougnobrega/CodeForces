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
int degree[100001];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	priority_queue<pii> v[n];
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		v[x].push(MP(0,i+1));
	}
	vpi ans;
	
	if(v[0].size() != 1){
		cout << "-1" << endl;
	}else{
		for(int i = 0; i < n-1; i++){
			for(int j = 0; j < (int)v[i+1].size(); j++){
				if(v[i].size() == 0 || v[i].top().F == -k){
					cout << "-1" << endl;
					return 0;
				}	
				auto top = v[i].top();
				v[i].pop();
				auto top2 = v[i+1].top();
				v[i+1].pop();
				ans.emplace_back(top.S,top2.S);
				degree[top.S]++;
				degree[top2.S]++;
				v[i].push(MP(-degree[top.S], top.S));
				v[i+1].push(MP(-degree[top2.S], top2.S));
			}
		}
		cout << ans.size() << endl;
		for(auto edge : ans){
			cout << edge.F << " " << edge.S << endl;
		} 
	}
	
	return 0;
}

