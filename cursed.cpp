#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <map>
using namespace std;

const double EPS = 1e-9;

int getNum() {
    int res = 0, sign = 1;
    char c;
    while ((c = getchar()) != '-' && (c < '0' || c > '9')) {}
    if (c == '-') { sign = -1; c = getchar(); }
    res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + (c - '0');
    return res * sign;
}

struct People {
    double x0, a;
    void init(double x0, double a) { this->x0 = x0; this->a = a; }
};

People person[10010];
int tc, n, xi, ti, ai;
double vi, wi;

int compute(unordered_set<int> &exist, int it, vector<int> &position) {
    int currMax = 0;
    double time = it, vy = wi / time;
    double maxVx = sqrt(vi*vi - vy*vy);

    for (int m = -1; m <= 1; m += 2) {
        vector<pair<double, int>> events;
        events.reserve(2*position.size());
        double dirVx = maxVx * m;
        for (int index : position) {
            double theta = (person[index].a / 60.0) * (M_PI/180.0);
            double vx = tan(theta) * vy;
            double displacement = (vx - dirVx) * time;
            double left = person[index].x0, right = person[index].x0 + displacement;
            if (left > right) swap(left, right);
            events.emplace_back(left, 1);
            events.emplace_back(right, -1);
        }
        
        sort(events.begin(), events.end());

        int hit = 0;
        for (int it=0; it < events.size();) {
            int plus = 0, mins = 0;
            double x = events[it].first;
            while(it < events.size() && fabs(events[it].first - x) < EPS) {
                if (events[it].second == 1) plus++;
                else mins++;
                it++;
            }
            if (exist.find(x) == exist.end()) {
                hit += plus;
                if (hit > currMax) currMax = hit;
            } else {
                if (hit > currMax) currMax = hit;   
                hit += plus;
            }     
            hit -= mins;
        }
    }
    return currMax;
}

int main() {
    tc = getNum();
    while (tc--) {
        n = getNum(); 
        wi = getNum(); 
        vi = getNum();
        unordered_set<int> exist;
        unordered_map<int, vector<int>> people_group;
        
        //optimization
        for (int i = 0; i < n; ++i) {
            xi = getNum(); ti = getNum(); ai = getNum();
            person[i].init(xi*1.0, ai*1.0);
            exist.insert(xi);
            double vy = wi / ti;
            if (vy <= vi) people_group[ti].push_back(i);
            else continue;
        }

        int max_group = 0;
        for (auto it= people_group.begin(); it != people_group.end(); it++) {
            max_group = max(max_group, compute(exist, it->first, it->second));
        }
        printf("%d\n", max_group);
    }
    return 0;
}