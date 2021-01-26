#include <bits/stdc++.h>
using namespace std;
 
int main(){
	string txt;
	cin >> txt;
	set<char> letras;
	for(int i = 0; i < txt.size();i++){
		letras.insert(txt[i]);
	}
	if(letras.size() & 1){
		cout << "IGNORE HIM!" << endl;
	}else{
		cout << "CHAT WITH HER!" << endl;
	}
	return 0;
}

