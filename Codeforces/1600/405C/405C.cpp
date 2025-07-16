#include<stdio.h>
#include<vector>

using namespace std;
// input is large 
int main(){
    int n, t;
    scanf("%d" , &n);
    vector<int>diagnol(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)scanf("%d", &diagnol[i]);
            else scanf("%d", &t);
        }
    }
    scanf("%d" , &t);
    for(int i=0; i<t; i++){
        int k,c;
        scanf("%d" , &k);
        if(k == 1){
            scanf("%d" , &c);
            diagnol[c-1] = !diagnol[c-1];
        }
        else if(k == 2){
            scanf("%d" , &c);
            diagnol[c-1] = !diagnol[c-1];
        }
        else{
            int s = 0;
            for(int i=0; i<n; i++){
                s += diagnol[i];
            }
            printf("%d" , s%2);
        }
    }
}