#include <stdio.h>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct pedestrian {
    public:
    double x;
    double a;

    void set(double x, double a) {
        this->x = x;
        this->a = a;
    }
};
int n;
double w,v,x,t,a;
pedestrian p[10001];

int getNum()
{
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

struct FloatingPointCompare {
    bool operator()(const double& lhs, const double& rhs) const {
        const double epsilon = 1e-9;
        return lhs + epsilon < rhs;
    }
};

double to_radian(double degree) {
    return degree * (M_PI / 180.0);
}
void assign_to_group(double x, double t, double a, int i, unordered_map<int,vector<int>>& group_pedestrian) {
    double vertical_speed = w / t;
    if (vertical_speed > v) return;
    p[i].set(x, a);
    group_pedestrian[t].push_back(i);
}
int sweep_line(vector<pair<double, int>>& events, const set<double, FloatingPointCompare>& occupied) {
    sort(events.begin(), events.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        if (fabs(a.first - b.first) > 1e-9) return a.first < b.first;
        return a.second > b.second;
    });
    int max_overlap = 0;
    int current_overlap = 0;
    for (size_t i = 0; i < events.size();) {
        double pos = events[i].first;
        int add = 0, sub = 0;
        while (i < events.size() && fabs(events[i].first - pos) < 1e-9) {
            if (events[i].second == 1) add++;
            else sub++;
            ++i;
        }
        if (occupied.find(pos) == occupied.end()) {
            current_overlap += add;
            max_overlap = max(max_overlap, current_overlap);
        } 
        else {
            max_overlap = max(max_overlap, current_overlap);
            current_overlap += add;
        }
        current_overlap -= sub;
    }
    return max_overlap;
}
int get_group_max(set<double, FloatingPointCompare>& occupied, double time, vector<int>& indexers) {
    int group_max = 0;
    double vertical_speed = w / time;
    double max_horizontal_speed = sin(acos(vertical_speed / v)) * v;
    // Left and right direction 
    for (int m = -1; m <= 1; m += 2) {
        vector<pair<double, int>> events;
        double mul = m * 1.0;
        for (int i = 0; i < indexers.size(); i++) {
            int index = indexers[i];
            double angle = to_radian(p[index].a / 60.0);
            double pedestrian_horizontal_speed = tan(angle) * vertical_speed;
            double displacement = (pedestrian_horizontal_speed - max_horizontal_speed * mul) * time;
            double interval[2] = {p[index].x, p[index].x + displacement};
            if (interval[0] > interval[1]) swap(interval[0], interval[1]);
            events.emplace_back(interval[0], 1); // Interval Start
            events.emplace_back(interval[1], 0); // Interval End
        }
        int current_max = sweep_line(events, occupied);
        group_max = max(group_max, current_max);
    }
    return group_max;
}

int main() {
    int T;
    T = getNum();
    while (T--) {
        n = getNum();
        w = getNum() * 1.0;
        v = getNum() * 1.0;
        set<double, FloatingPointCompare> occupied;
        unordered_map<int, vector<int>> group_pedestrian;
        for(int i = 0; i < n; i++) {
            x = getNum() * 1.0;
            t = getNum() * 1.0;
            a = getNum() * 1.0;
            occupied.insert(x);
            assign_to_group(x, t, a, i, group_pedestrian);
        }
        int max_collisions = 0;
        for(auto i = group_pedestrian.begin(); i != group_pedestrian.end(); i++) {
            int current_collision = get_group_max(occupied, i->first, i->second);
            max_collisions = max(max_collisions, current_collision);
        }
        printf("%d\n", max_collisions);
    }
    return 0;
}