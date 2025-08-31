#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>
using namespace std;

struct node{
	int x, a, b; 
	bool operator <(const node &A) const{
		return a-b>A.a-A.b; // less cost go first
	}
}; 

int main(){
    string s;
    node n;
    priority_queue<node>q; 

    int q_num = 0;
    cin >> s;
    for(auto i : s){
        if(i == '?')q_num++;
    }
    if(s.size()%2){
        cout << "-1\n";
        return 0;
    }
    vector<int>a(q_num), b(q_num);
    for(int i=0; i<q_num; i++){
        cin >> a[i] >> b[i];
    }
    int left = 0, j = 0;
    long long ans = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '('){
            left++;
            continue;
        }
        if (s[i] == '?') {
            s[i] = ')';
            n.x = i;
            n.a = a[j]; 
            n.b = b[j];
            ans += b[j];
            j++;
            q.push(n);
        }
        if (s[i] == ')') {
            if(!left){
                if (q.empty()){
                    cout << -1;
                    return 0;
                }
                node best = q.top(); 
                q.pop();
                ans -= best.b;
                ans += best.a;
                s[best.x] = '(';
                left = 2; // remove ) to ( -> 1 + 1 = 2
            }
            left--;
        }
    }
    if(left){ // if pairing is not possible
        cout << "-1\n";
        return 0;
    }
    else{
        cout << ans << "\n";
        for(auto i : s)cout << i;
        cout << "\n";
    }
}