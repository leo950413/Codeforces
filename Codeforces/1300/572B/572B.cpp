#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct orders
{
    public:
        char c;
        int p;
        int q;
    
        orders(char ch , int p_n, int q_n):c(ch),p(p_n),q(q_n){};
        bool operator<(const orders& o1) const{
            return o1.p < p;
        }

        orders operator+(const orders& o1){
            if(o1.c == c && o1.p == p){
                return orders(c , p , q+o1.q);
            }
        }
};

int main(){
    int n,s;
    cin >> n >> s;
    vector<orders>v;
    for(int i=0; i<n; i++){
        char c;
        int p,q;
        cin >> c >> p >> q;
        v.push_back(orders(c, p , q));
    }
    sort(v.begin() , v.end());
    // for(const orders &o : v){
    //     cout << o.c << " " << o.p << " " << o.q << "\n";
    // }
    vector<orders>ans;
    int i=0;
    while(i < v.size()){
        orders prev(v[i].c , v[i].p , v[i].q);    
        int j = i+1;
        while(j < v.size()){
            if(prev.c == v[j].c && prev.p == v[j].p){
                prev = prev + v[j];
            }
            else{
                break;
            }
            j++;
        }
        ans.push_back(prev);
        i = j;
    }
    int idx=0;
    while(ans[idx].c != 'B' && idx < ans.size()){
        idx++;
    }
    // choose s smallest 'S' choose s largest 'B' 
    // print them in ascending order.
    if(idx > s){ // 
        for(int i=idx-s; i<idx; i++){
            cout << ans[i].c << " " << ans[i].p << " " << ans[i].q << "\n";
        }
    }
    else{
        for(int i=0; i<idx; i++){
            cout << ans[i].c << " " << ans[i].p << " " << ans[i].q << "\n";
        }
    }
    int cnt = 0;
    for(int i=idx; i<ans.size(); i++){
        if(cnt == s){
            break;
        }
        cout << ans[i].c << " " << ans[i].p << " " << ans[i].q << "\n";
        cnt ++;
    }
}