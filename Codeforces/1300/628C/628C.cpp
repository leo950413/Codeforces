#include <stdio.h>
#include <string>

using namespace std;
char buf[200005];
bool valid(char c, int n){
    if(c + n <= 25 + 'a' && c + n >= 'a'){
        return true;
    }
    return false;
}
int main(){
    int n,k;
    scanf("%d %d" , &n , &k);
    scanf("%s", buf);
    string s = buf;
    for(int i=0; i<s.size(); i++){
    
        int t = max(abs(s[i] - 'a') , abs(s[i] - 'z'));
        if(k > t){
            if(valid(s[i] , -t)){
                s[i] -= t;
            }
            else{
                s[i] += t;
            }
            k -= t;
        }
        else{
            if(valid(s[i], k)){
                s[i] += k;
            }
            else{
                s[i] -= k;
            }
            k = 0;
            break;
        }
    }
    if(k != 0){
        printf("-1\n");
        return 0;
    }
    printf("%s\n", s.c_str());
}