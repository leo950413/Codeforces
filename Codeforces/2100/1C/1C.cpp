#include<iostream>
#include<math.h>
#include <iomanip>


using namespace std;

typedef long long ll;
typedef double db;
const int maxn=1e5+10;
const double PI=acos(-1.0);
const double eps=1e-4;

// https://www.cnblogs.com/ZERO-/p/10053832.html
struct point{
    double x, y;
};
double dis(point a, point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
// A confusing way to implement arccos using function overloading
// double acos(double a,double b,double c)
// 18 {
// 19     return acos((a*a+b*b-c*c)/(2*a*b));
// 20 }
double arccos(double a, double b, double c){
    double cs = (a*a+b*b-c*c)/(2*a*b);
    if(cs < -1.0) cs = -1.0; // for acos(x) x must in [-1,1]
    if(cs > 1.0) cs = 1.0;
    return acos(cs);
}

double fgcd(double a, double b){
    if(b<eps)return a;
    return fgcd(b, fmod(a,b));
}
int main(){
    point A,B,C;
    cin>>A.x>>A.y;
    cin>>B.x>>B.y;
    cin>>C.x>>C.y;
    double a=dis(B,C),b=dis(A,C),c=dis(A,B);
    double p=(a+b+c)/2;
    double s=sqrt(p*(p-a)*(p-b)*(p-c));
    double r=a*b*c/(4*s);
    double AA=arccos(r,r,a),BB=arccos(r,r,b),CC=2*PI-AA-BB;
    double angle=fgcd(AA,fgcd(BB,CC));
    double sr=(r*r*sin(angle))/2;
    double ans=sr*2*PI/angle;
    cout << fixed << setprecision(6) << ans << "\n";
}
