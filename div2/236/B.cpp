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

ll dp[1000010];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a, b, c;
	memset(dp,-1,sizeof dp);
	cin >> a >> b >> c;
	
	ll ans = 0LL;
	REP(i,1,a+1){
		REP(j,1,b+1){
			REP(k,1,c+1){
				int aux = i*j*k;
				//W(aux);
				if(dp[aux] == -1){
					dp[aux] = 0;
					for(int div = 1;div*div <= aux;div++){
						if(aux/div == div && aux%div == 0){
							dp[aux]++;
						}else{
							if(aux%div == 0){
								dp[aux]++;
							}
							if(aux%(aux/div) == 0){
								dp[aux]++;
							}
						}
					}
				}
				ans += dp[aux];
				if(ans > 1073741824)
					ans -= 1073741824;
			}
		}
	}
	cout << ans%1073741824 << endl;
	return 0;
}

