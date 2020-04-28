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
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade
vi in[10];
vi v(1010);
int n;
int dp[1010][1 << 8];

ll getAnswer(int len){
	vi counting(10, 0);
	memset(dp, -INF, sizeof dp);
	dp[0][0] = 0;
	for(int idx = 0; idx < n; idx++){
		for(int mask = 0; mask < (1 << 8) ; mask++){
			for (int num = 0; num < 8; num++){
				if(mask & (1 << num)) continue;
				//put only len
				int end = counting[num] + len - 1;
				if(end >= in[num].size()) continue;
				dp[in[num][end] + 1][mask | (1 << num)] = max(dp[in[num][end] + 1][mask | (1 << num)], dp[idx][mask]);
				//put len plus one
				end = counting[num] + len;
				if(end >= in[num].size()) continue;
				dp[in[num][end] + 1][mask | (1 << num)] = max(dp[in[num][end] + 1][mask | (1 << num)], dp[idx][mask] + 1);
			}
		}
		counting[v[idx]]++;
	}
	
	int answer = -1;
	
	for (int idx = 0; idx <= n; idx++){
		answer = max(answer, dp[idx][(1 << 8) - 1]);
	}
	
	if(answer == -1) return -1;
	
	return answer * (len + 1) + (8 - answer) * len;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> v[i];
		v[i]--;
		in[v[i]].PB(i);
	}
	
	int len = 0;
	int lo = 1, hi = n >> 3, mid;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(getAnswer(mid) != -1){
			len = mid;
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	int answer = getAnswer(len);
	if(len == 0){
		answer = 0;
		for (int i = 0; i < 8; i++){
			answer += !in[i].empty();
		}
	}
	cout << answer << endl;
	return 0;
}


