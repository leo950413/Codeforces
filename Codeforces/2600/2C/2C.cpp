#include<cmath>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

// https://xuanwo.io/2014/11/06/cf-2c/
const double eps = 1e-6;

struct Circle{
    double x, y, r;
};

Circle circles[3];

double dis(double x1, double y1, double x2, double y2){
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}


double calc_error(double x, double y){
    double ratios[3];
    
    for(int i=0; i<3;i++){
        ratios[i] = dis(x, y, circles[i].x, circles[i].y) / circles[i].r;
    }
    
    double errorSum = 0;
    for (int i = 0; i < 3; i++){
        double delta = ratios[i] - ratios[(i+1) % 3];
        errorSum += delta * delta;
    }
    
    return errorSum;
}

int main() {
    double best_x = 0, best_y = 0; 
    
    for(int i=0; i<3; i++){
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
        best_x += circles[i].x;
        best_y += circles[i].y;
    }
    best_x /= 3.0;
    best_y /= 3.0;

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    double stepSize = 1.0;
    while(stepSize > eps){
        double curr = calc_error(best_x, best_y);
        int next_direction = -1;
        
        for(int i = 0; i < 4; i++){
            double nx = best_x + directions[i][0] * stepSize;
            double ny = best_y + directions[i][1] * stepSize;
            
            double next = calc_error(nx, ny);
            
            if(next < curr){
                curr = next;
                next_direction = i;
            }
        }
        
        if(next_direction != -1){
            best_x += directions[next_direction][0] * stepSize;
            best_y += directions[next_direction][1] * stepSize;
        } 
        else{// if the result is not improving -> decrease step size
            stepSize /= 2.0;
        }
    }
    if(calc_error(best_x , best_y) <= eps)cout << fixed << setprecision(5) << best_x << " " << best_y << "\n";

}