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
char v[4][4];
int main(){
	REP(i,0,4)
		REP(j,0,4)
			cin >> v[i][j];
	REP(i,1,4){
		REP(j,1,4){
			int ponto = 0, hashtag = 0;
			if(v[i][j] == '#'){
				hashtag++;
			}else{
				ponto++;
			}
			if(v[i][j-1] == '#'){
				hashtag++;
			}else{
				ponto++;
			}
			if(v[i-1][j] == '#'){
				hashtag++;
			}else{
				ponto++;
			}
			if(v[i-1][j-1] == '#'){
				hashtag++;
			}else{
				ponto++;
			}
			if(ponto == 4 || hashtag == 4 || (ponto == 3 && hashtag == 1) || (hashtag == 3 && ponto == 1)){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
