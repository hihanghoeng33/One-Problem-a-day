#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
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
 
struct AccuracyCompare {
    bool operator()(const double &lhs, const double &rhs) const {
        return lhs + EPS < rhs;
    }
};
 
struct People {
    double x0, a;
    void init(double x0, double a) { this->x0 = x0; this->a = a; }
};
 
People person[10010];
int tc, n, xi, ti, ai;
double vi, wi;
 
int compute(set<double, AccuracyCompare> &exist, int it, vector<int> &position) {
    int currMax = 0;
    double time = it, vy = wi / time;
    if (vy > vi) return 0;
    double max_angle = acos(vy / vi);
    double maxVx = sin(max_angle) * vi;
 
    for (int m : {-1, 1}) {
        vector<pair<double, int>> events;
        events.reserve(2 * position.size());
        double dirVx = maxVx * m;
 
        for (int index : position) {
            double theta = (person[index].a / 60.0 * M_PI) / 180.0 / 10.0;
            double vx = tan(theta) * vy;
            double displacement = (vx - dirVx) * time;
            double left = person[index].x0, right = person[index].x0 + displacement;
            if (left > right) swap(left, right);
            events.emplace_back(left, 1);
            events.emplace_back(right, -1);
        }
 
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            if (a.first + EPS < b.first) return true;
            if (b.first + EPS < a.first) return false;
            return a.second > b.second; 
        });
 
        int hit = 0;
        for(size_t i = 0; i < events.size(); ){
            double x = events[i].first;
            int plus = 0, minus = 0;
            while (i < events.size() && fabs(events[i].first - x) < EPS) {
                (events[i].second > 0 ? plus : minus)++;
                i++;
            }

            if (exist.find(x) == exist.end()) {
                hit += plus;
                currMax = max(currMax, hit);
            } else {
                currMax = max(currMax, hit);
                hit += plus;
            }
            hit -= minus;
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
        set<double, AccuracyCompare> exist;
        unordered_map<int, vector<int>> people_group;
 
        for (int i = 0; i < n; ++i) {
            xi = getNum(); ti = getNum(); ai = getNum();
            person[i].init(xi, ai * 10);
            exist.insert(xi);
            double vy = wi / ti;
            if (vy <= vi) people_group[ti].push_back(i);
        }
 
        int max_group = 0;
        for (auto &[key, group] : people_group)
            max_group = max(max_group, compute(exist, key, group));
        printf("%d\n", max_group);
    }
    return 0;
} 