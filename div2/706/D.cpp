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
const int K = 2;

struct Vertex {
    int next[K];
    int leaf = 0;

    Vertex() {
        fill(begin(next), end(next), -1);
	}
};

vector<Vertex> trie(1);

void add_number(ll value) {
    int v = 0;
    for(ll i = 32; i >= 0; i--) {
        int c = (value >> i) & 1;
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
		trie[v].leaf++;
    } 
}

void remove_number(ll value) {
    int v = 0;
    for(ll i = 32; i >= 0; i--) {
        int c = (value >> i) & 1LL;
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
	    trie[v].leaf--;
    }
    
}

ll search(ll value){
	ll ans = 0;
	int v = 0;
	for(ll i = 32; i >= 0; i--) {
        ll c = !((value >> i) & 1ll);
        if (trie[v].next[c] == -1 || trie[trie[v].next[c]].leaf == 0) {
            c = !c;
        }
        v = trie[v].next[c];
		ans += c*(1ll << i);
    } 
    return ans ^ value;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	add_number(0);
	while(q--){
		char op;
		ll x;
		cin >> op >> x;
		if(op == '+'){
			add_number(x);
		}else if(op == '-'){
			remove_number(x);
		}else{
			cout << search(x) << endl;
		}
	}
	return 0;
}

