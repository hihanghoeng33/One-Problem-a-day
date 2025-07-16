#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

const double EPS = 1e-9;

int getNum(){
    int res = 0;
    int mul = 1;

    char c;
    while (1)
    {
        c = getchar();
        if(c == '-')
        {
            mul = -1;
            continue;
        }

        if (c == ' ' || c == '\n')
            continue;
        else
            break;
    }
    res = (c - '0');
    while (1)
    {
        c = getchar();
        if (c >= '0' && c <= '9')
            res = (res << 1) + (res << 3) + (c - '0');
        else
            break;
    }

    return res * mul;
}


typedef struct AccuracyCompare {
    bool operator()(const double &lhs, const double &rhs) const {
        return lhs + EPS < rhs;
    }
}Ac;

typedef struct People{
    double x0;
    double a;
    void init(double x0, double a)
    {
        this->x0 = x0;
        this->a = a;
    }
}P;

P person[10010];
int tc, n, xi, ti, ai;
double vi, wi;
int compute(set<double, Ac> &exist, int it, vector<int> &position){
    int currMax = 0;
    double time = it * 1.0;
    double vy = wi / time;
    double max_angle = acos(vy / vi);
    double maxVx = sin(max_angle) * vi;
    for(int m = -1; m <= 1; m += 2){
        map<double, vector<int>, Ac> sweep_line;
        double tmp = m*1.0;
        for(int i = 0; i < position.size(); i++){
            int index = position[i];
            double theta = ((person[index].a / 60.0) * (M_PI / 180.0));
            double vx = tan(theta) * vy;
            double displacement = (vx - maxVx * tmp) * time;
            vector<int> events;
            double left_bound, right_bound;
            if(displacement > 0.0){
                left_bound = person[index].x0;
                right_bound = person[index].x0 + displacement;
            }else{
                right_bound = person[index].x0;
                left_bound = person[index].x0 + displacement;
            }
            if(sweep_line.find(left_bound) == sweep_line.end()){
                vector<int> events;
                events.push_back(1);
                sweep_line[left_bound] = events;
            }else{
                vector<int> events = sweep_line[left_bound];
                events.push_back(1);
                sweep_line[left_bound] = events;
            }
            int event_on_exist = 0;
            for (int e : events) {
                if (exist.find(e) != exist.end()) {
                    event_on_exist++;
                }
            }
            // printf("Events at pedestrian starting points (exist): %d\n", event_on_exist);


            if(sweep_line.find(right_bound) == sweep_line.end()){
                vector<int> events;
                events.push_back(0);
                sweep_line[right_bound] = events;
            }else{
                vector<int> events = sweep_line[right_bound];
                events.push_back(0);
                sweep_line[right_bound] = events;
            }
            // printf("Event at %.6lf (start)\n", left_bound);
        }
        // printf("Total sweep line: %d\n", sweep_line.size());

        int hit = 0;
        for(auto it = sweep_line.begin(); it!= sweep_line.end(); it++){
            int plus = 0, mins=0;
            vector<int> events = it->second;
            for(int i=0;i<events.size();i++){
                if(events[i]==1) {plus++;}
                else {mins++;}
            }
            // for(int e : events) {
            //     if(e==1) plus++;
            //     else mins++;
            // }
            bool isExist = exist.find(it->first) != exist.end();
            // printf("x = %.6lf, plus: %d, mins: %d, exist: %s", it->first, plus, mins, isExist ? "true" : "false");
            // printf("Processing point: %lf, plus: %d, mins: %d\n", it->first, plus, mins);
            // Update hit
            // if(isExist) printf(" | EXISTS\n");
            // else printf(" | NOT EXISTS\n");
            if(!isExist){
                hit+=plus;
                if(hit>currMax) currMax = hit;
                // printf("           | hit after = %d, currMax = %d\n", hit, currMax);
            }else{
                if(hit>currMax) currMax = hit;
                hit+=plus;
                // printf("           | hit after = %d, currMax = %d\n", hit, currMax);
            }
            hit-=mins;
            // printf("Current hit: %d, Current max: %d\n", hit, currMax);
        }
    }
    return currMax;
}

int main(){
    tc=getNum();
    while(tc--){
        n = getNum();
        int w = getNum();
        int v = getNum();
        wi=w*1.0, vi=v*1.0;
        set<double, Ac> exist;
        unordered_map<int, vector<int>> people_group;
        
        for(int i = 0; i < n; i++){
            xi = getNum();
            ti = getNum();
            ai = getNum();
    
            person[i].init(xi*1.0, ai*1.0);
            exist.insert(xi*1.0);
            double vy = w/(ti*1.0);
            vector <int> position;
      
            if(vy>v) continue;
           
            if(people_group.find(ti) == people_group.end()){
                position.push_back(i);
                people_group[ti] = position;
            }else{
                position = people_group[ti];
                position.push_back(i);
                people_group[ti] = position;
            }
        }

        int max_group = 0;
        for(auto it = people_group.begin(); it != people_group.end(); it++){
            int collision = compute(exist, it->first, it->second);
            if(collision > max_group){
                max_group = collision;
            }
        }
        printf("%d\n", max_group);
    }
    return 0;
}

