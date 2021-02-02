#include <bits/stdc++.h>

using namespace std;
							// Typedef's  start //
typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii > vpi;

							//	Typedef's end //
							//	Define's start //
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

							// Define's end //
bitset<100010> vis;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vis.reset();
	int k,l,m,n,d;
	cin >> k >> l >> m >> n >> d;
	REP(i,1,d+1){
		if(i%k == 0){
			vis[i] = 1;
		}else if(i%l == 0){
			vis[i] = 1;
		}else if(i%m == 0){
			vis[i] = 1;
		}else if(i%n == 0){
			vis[i] = 1;
		}
	}
	cout << vis.count() << endl;
	return 0;
}
