#include <cstdio>
#include <cmath>
using namespace std;

double xStart, xFinish, yStart, yFinish, ang, v0, v1;
double eps = 1e-6;
double tmin = 0, tmax = 1e5;
double ymin = 0, ymax = 1e5;

double computeTernary();
double computeTotal(double t, double y);
double computeTernary_Y(double t);
double distance(double x1, double y1, double x2, double y2);

double computeTotal(double t, double y){
    double dt = t*tan(ang);
    double sp = distance(xStart, yStart, 0, y);
    double pf = distance(xFinish, yFinish, dt, t);
    double op = distance(0, y, dt, t);
    return sp/v0 + op/v1 + pf/v0;
}

double computeTernary_Y(double t){
    double left = ymin, right = ymax;
    double mid1, mid2;
    while(right-left>eps){
        mid1 = left + (right-left)/3.0;
        mid2 = right - (right-left)/3.0;
        double y1 = computeTotal(t, mid1);
        double y2 = computeTotal(t, mid2);

        if(y1 < y2){
            right = mid2;
        }else{
            left = mid1;
        }
    }
    return (left + right) / 2.0;
}

double computeTernary(){
    double left = tmin, right = tmax;
    double mid1, mid2;
    while(right-left>eps){
        mid1 = left + (right-left)/3.0;
        mid2 = right - (right-left)/3.0;
        double y1 = computeTernary_Y(mid1);
        double y2 = computeTernary_Y(mid2);

        double time1 = computeTotal(mid1, y1);
        double time2 = computeTotal(mid2, y2);
        if(time1 < time2){
            right = mid2;
        }else{
            left = mid1;
        }
    }
    double best_t = (left + right) / 2.0;
    double best_y = computeTernary_Y(best_t);
    return computeTotal(best_t, best_y);
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xStart, &yStart, &xFinish, &yFinish, &ang, &v0, &v1);
    double minTime = computeTernary();
    printf("%.3f\n", minTime);
    return 0;
}
