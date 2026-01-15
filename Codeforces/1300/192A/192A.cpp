#include<set>
#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int N = 1e5 + 1;
	set<long long>s;
	for(int i=1; i<N; i++){
		s.insert((i* 1LL * (i + 1)) / 2);
	}
	for(auto c: s){
		if(s.count(n - c) > 0){
			cout << "YES\n";
			return 0;
		}
	}
	cout <<"NO\n";
}