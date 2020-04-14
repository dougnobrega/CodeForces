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
int n;
vpi points;
int used[200010];

inline pii operator -(const pii &a, const pii &b) {
	return {a.F - b.F, a.S - b.S};
}

inline ll cross(pii a, pii b){
	return a.F * 1LL * b.S - a.S * 1LL * b.F;
}

bool generateNextLine(){
	int idx1 = -1, idx2 = -1;
	
	for (int i = 0; i < n; i++){
		if(used[i]) continue;
	
		if(idx1 == -1){
			idx1 = i;
		}else{
			idx2 = i;
			break;
		}
	}
	
	if(idx1 == -1 || idx2 == -1) return true;
	
	pii a = points[idx1], b = points[idx2];
	for (int i = 0; i < n; i++){
		if(!used[i] && cross(b-a, points[i] - a) != 0){
			return false;
		}
	}
	
	return true;
}

bool check(pii a, pii b){
	memset(used, 0, sizeof used);
	
	for (int i = 0; i < n; i++){
		if(cross(b-a, points[i] - a) == 0){
			used[i] = 1;
		}
	}
	
	return generateNextLine();
}

string solve(){
	if(n <= 4) return "YES";
	
	if(check(points[0],points[1]) || check(points[1],points[2]) || check(points[0],points[2])){
		return "YES";
	}else{
		return "NO";
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	
	points.resize(n);
	for (int i = 0; i < n; i++){
		cin >> points[i].F >> points[i].S;
	}
	
	cout << solve() << endl;
	return 0;
}

