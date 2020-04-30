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
const int INVALID = -1;

int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int LEFT = 1;
const int RIGHT = 0;
const int UP = 3;
const int DOWN = 2;

struct node{
	int value;
	struct node * ptr[4];
};
node matrix[1002][1002];

bool valid(int i, int j){
	if(i < 0 || i > 1 + n || j < 0 || j > 1 + m) return 0;
	return 1;
}


void modify(int a, int b, int c, int d, int h, int w){
	node *it1 = &matrix[a][0]; 
	node *it2 = &matrix[c][0];
	for (int i = 0; i < b; i++) it1 = it1->ptr[RIGHT]; //pick the correct initial cell - 1
	for (int i = 0; i < d; i++) it2 = it2->ptr[RIGHT]; //pick the correct initial cell - 1
	
	node *itr1 = it1;
	node *itr2 = it2;
	
	for (int i = 0; i < w - 1; i++){
		swap(itr1->ptr[UP]->ptr[DOWN], itr2->ptr[UP]->ptr[DOWN]);
		swap(itr1->ptr[UP], itr2->ptr[UP]);
		itr1 = itr1->ptr[RIGHT];
		itr2 = itr2->ptr[RIGHT];
	}
	swap(itr1->ptr[UP]->ptr[DOWN], itr2->ptr[UP]->ptr[DOWN]);
	swap(itr1->ptr[UP], itr2->ptr[UP]);
	
	for (int i = 0; i < h - 1; i++){
		swap(itr1->ptr[RIGHT]->ptr[LEFT], itr2->ptr[RIGHT]->ptr[LEFT]);
		swap(itr1->ptr[RIGHT], itr2->ptr[RIGHT]);
		itr1 = itr1->ptr[DOWN];
		itr2 = itr2->ptr[DOWN];	
	}
	swap(itr1->ptr[RIGHT]->ptr[LEFT], itr2->ptr[RIGHT]->ptr[LEFT]);
	swap(itr1->ptr[RIGHT], itr2->ptr[RIGHT]);
	
	itr1 = it1;
	itr2 = it2;

	for (int i = 0; i < h - 1; i++){
		swap(itr1->ptr[LEFT]->ptr[RIGHT], itr2->ptr[LEFT]->ptr[RIGHT]);
		swap(itr1->ptr[LEFT], itr2->ptr[LEFT]);
		itr1 = itr1->ptr[DOWN];
		itr2 = itr2->ptr[DOWN];	
	}
	swap(itr1->ptr[LEFT]->ptr[RIGHT], itr2->ptr[LEFT]->ptr[RIGHT]);
	swap(itr1->ptr[LEFT], itr2->ptr[LEFT]);
		
	for (int i = 0; i < w - 1; i++){
		swap(itr1->ptr[DOWN]->ptr[UP], itr2->ptr[DOWN]->ptr[UP]);
		swap(itr1->ptr[DOWN], itr2->ptr[DOWN]);
		itr1 = itr1->ptr[RIGHT];
		itr2 = itr2->ptr[RIGHT];
	}
	swap(itr1->ptr[DOWN]->ptr[UP], itr2->ptr[DOWN]->ptr[UP]);
	swap(itr1->ptr[DOWN], itr2->ptr[DOWN]);
	
}


void generateConnections(){
	for(int i = 0; i <= n + 1;i++){
		for(int j = 0; j <= m + 1;j++){
			for (int k = 0; k < 4; k++){
				matrix[i][j].value = INVALID;
				if(valid(i + dx[k], j + dy[k])) matrix[i][j].ptr[k] = &matrix[i + dx[k]][j + dy[k]];
				else matrix[i][j].ptr[k] = nullptr; 
			}
		}	
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> n >> m >> q;
	generateConnections();
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m ;j++){
			cin >> matrix[i][j].value;
		}
	}
	
	while(q--){
		int a, b, c, d, h, w;
		cin >> a >> b >> c >> d >> h >> w;
		modify(a, b, c, d, h, w);
	}
	
	for (int i = 1; i <= n; i++){
		node *now = &matrix[i][0];
		while(now != nullptr){
			if(now->value != INVALID) cout << now->value << " ";
			now = now->ptr[0];
		}
		cout << endl;
	}
	
	return 0;
}


