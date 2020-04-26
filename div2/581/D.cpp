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
#define MOD 998244353ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
void check(vpll pts, vector<char> c){
	//every logo in horizontal
	if(pts[0].F + pts[1].F + pts[2].F == min({pts[0].S, pts[1].S, pts[2].S}) and min({pts[0].S, pts[1].S, pts[2].S}) == max({pts[0].S, pts[1].S, pts[2].S})){
		int p = 0;
		cout << pts[0].F + pts[1].F + pts[2].F << endl;
		for(auto pt : pts){
			for(int i = 0; i < pt.F; i++){
				for(int j = 0; j < pt.S; j++){
					cout << c[p];
				}
				cout << endl;
			}
			p++;
		}
		exit(0);
	}
	if(pts[0].F + pts[1].S == pts[0].S and pts[1].S == pts[2].S and pts[0].S == pts[1].F + pts[2].F){
		cout << pts[0].F + pts[1].S << endl;
		int p = 0;
		for(int i = 0; i < pts[0].F; i++){
			for(int j = 0; j < pts[0].S; j++){
				cout << c[p];
			}
			cout << endl;
		}
		p++;
		for(int i = 0; i < pts[1].S; i++){
			for (int j = 0; j < pts[1].F + pts[2].F; j++){
				int pp = p;
				if(j >= pts[1].F) pp++;
				cout << c[pp];
			}
			cout << endl;
		}
		
		exit(0);
	}
	
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	pll sz[3];
	
	for(int i = 0; i < 3; i++){
		cin >> sz[i].F >> sz[i].S;
	}
	
	for(int i = 0; i < (1 << 3); i++){
		pll pts[3] = sz;
		for (int j = 0; j < 3; j++){
			if(i & (1 << j)){
				swap(pts[j].F, pts[j].S);
			}
		}	
		check({pts[0], pts[1], pts[2]}, {'A','B','C'});
		check({pts[0], pts[2], pts[1]}, {'A','C','B'});
		check({pts[1], pts[0], pts[2]}, {'B','A','C'});
		check({pts[1], pts[2], pts[0]}, {'B','C','A'});
		check({pts[2], pts[0], pts[1]}, {'C','A','B'});
		check({pts[2], pts[1], pts[0]}, {'C','B','A'});
	}
	cout << -1 << endl;
	return 0;
}



