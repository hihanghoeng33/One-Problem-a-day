#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;
const double EPS = 1e-4;

int getNum() {
    int res = 0, mul = 1;
    char c;

    while (true) {
        c = getchar_unlocked();
        if (c == '-') mul = -1;
        else if (c >= '0' && c <= '9') break;
    }

    res = c - '0';
    while (true) {
        c = getchar_unlocked();
        if (c >= '0' && c <= '9')
            res = (res << 1) + (res << 3) + (c - '0');
        else
            break;
    }

    return res * mul;
}

struct pedestrian {
    double x, tan_a;
};

struct FloatingPointCompare{
    bool operator()(const double& lhs, const double& rhs) const{
        return lhs + EPS < rhs;
    }
};

pedestrian p[10001];

int main() {
    int t = getNum();

    while (t--) {
        int n = getNum();
        double w = (double)getNum(), v = (double)getNum();

        unordered_map<int, vector<int>> groups;
        unordered_set<int> occupied;

        for (int i = 0; i < n; ++i) {
            double xi = (double)getNum(), ti = (double)getNum(), ai = (double)getNum();

            double vy = w / ti;
            if (vy > v) continue;

            double a_rad = (ai / 60.0) * (M_PI / 180.0);
            occupied.insert(xi);
            p[i] = {xi, tan(a_rad)};
            groups[ti].push_back(i);
        }

        int max_collisions = 0;
        for (auto &[t, pedestrians] : groups) {

            int curr_collision = 0;
            double vy = w / t;
            double vx_max = sqrt(v * v - vy * vy);

            for(int m = -1; m <= 1; m+=2) {
                map<double, pair<int, int>, FloatingPointCompare> intervalGroups;

                for(int i : pedestrians) {
                    double vx = p[i].tan_a * vy;
                    double translation = (vx - vx_max * (double)m) * t;

                    double left, right;
                    if (translation > 0.0) {
                        left = p[i].x;
                        right = p[i].x + translation;
                    } else {
                        right =  p[i].x;
                        left = p[i].x + translation;
                    }
                    intervalGroups[left].first++;
                    intervalGroups[right].second--;
                }

                for(auto it = intervalGroups.begin(); it != intervalGroups.end(); it++) {
                    if(occupied.find(it->first) == occupied.end()) {
                        curr_collision += it->second.first;
                        max_collisions = max(max_collisions, curr_collision);
                    }else {
                        max_collisions = max(max_collisions, curr_collision);
                        curr_collision += it->second.first;
                    }
                    
                    curr_collision += it->second.second;
                }
            }

            max_collisions = max(max_collisions, curr_collision);
        }

        printf("%d\n", max_collisions);
    }

    return 0;
}
