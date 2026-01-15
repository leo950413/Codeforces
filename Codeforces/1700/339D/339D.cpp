#include<iostream>
#include<vector>
using namespace std;

int a[131072];
int t[131072 * 4]; // 2^17

void build(int a[], int v, int tl, int tr, int level){
    if(tl == tr){
        t[v] = a[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(a, v*2 ,tl ,tm, level-1);
        build(a, v*2+1, tm+1 , tr ,level-1);
        if(level % 2){
            t[v] = t[v*2] | t[v*2 + 1];
        }
        else{
            t[v] = t[v*2] ^ t[v*2 + 1];
        }
    }
}
void update(int v, int tl, int tr, int pos, int level, int nval){
    if(tl == tr){
        t[v] = nval;
    } 
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm){
            update(v*2, tl, tm, pos, level-1, nval);
        }
        else{
            update(v*2+1, tm+1, tr, pos, level-1, nval);
        }
        if(level % 2){
            t[v] = t[v*2] | t[v*2 + 1];
        }
        else{
            t[v] = t[v*2] ^ t[v*2 + 1];
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int total = 1;
    for(int i=0; i<n; i++)total *= 2;
    for(int i=0; i<total; i++)cin >> a[i];
    build(a, 1, 0 , total-1 , n);
    for(int i=0; i<m; i++){
        int p,b;
        cin >> p >> b;
        update(1, 0, total-1, p-1 ,n ,b);
        cout << t[1] << "\n";
    }
}