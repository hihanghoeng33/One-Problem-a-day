#include <stdio.h>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>

using namespace std;

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

struct FloatingPointCompare
{
    bool operator()(const double& lhs, const double& rhs) const
    {
        const double epsilon = 1e-9;
        return lhs + epsilon < rhs;
    }
};

int n;
double w, v;

double to_radian(double degree)
{
    return degree * (M_PI / 180.0);
}

struct pedestrian
{
    public:
    double x;
    double a;

    void set(double x, double a)
    {
        this->x = x;
        this->a = a;
    }
};

pedestrian p[10001];

int calc_group(set<double, FloatingPointCompare>& occupied, int t, vector<int>& indexers)
{
    int group_max = 0;
    double time = t * 1.0;
    double vertical_speed = w / time;
    double max_angle = acos(vertical_speed / v);
    double max_horizontal_speed = sin(max_angle) * v;
    
    for(int m = -1; m <= 1; m += 2)
    {
        map<double, vector<int>, FloatingPointCompare> line_sweep;
        double mul = m * 1.0;

        for(int i = 0; i < indexers.size(); i++)
        {
            int index = indexers[i];

            double angle = to_radian(p[index].a / 60.0);
            // printf("p[index].a = %lf\n", p[index].a);
            double pedestrian_horizontal_speed = tan(angle) * vertical_speed;
            printf("theta = %lf tan = %lf\n", angle, tan(angle));
            printf("pedestrian_horizontal_speed = %lf\n", pedestrian_horizontal_speed);
            double displacement = (pedestrian_horizontal_speed - max_horizontal_speed * mul) * time;

            double left_bound, right_bound;
            printf("displacement = %lf\n", displacement);
            if(displacement > 0.0)
            {
                left_bound = p[index].x;
                right_bound = p[index].x + displacement;
            }
            else
            {
                right_bound = p[index].x;
                left_bound = p[index].x + displacement;
            }
            printf("left_bound = %lf right_bound = %lf\n", left_bound, right_bound);
            if(line_sweep.find(left_bound) == line_sweep.end())
            {
                vector<int> events;
                events.push_back(1);
                line_sweep[left_bound] = events;
            }
            else
            {
                vector<int> events = line_sweep[left_bound];
                events.push_back(1);
                line_sweep[left_bound] = events;
            }

            if(line_sweep.find(right_bound) == line_sweep.end())
            {
                vector<int> events;
                events.push_back(0);
                line_sweep[right_bound] = events;
            }
            else
            {
                vector<int> events = line_sweep[right_bound];
                events.push_back(0);
                line_sweep[right_bound] = events;
            }
        }

        int current_overlap = 0;
        printf("line_sweep.size() = %d\n", line_sweep.size());
        for(auto it = line_sweep.begin(); it != line_sweep.end(); it++)
        {
            int add = 0;
            int sub = 0;
            
            vector<int> events = it->second;
            printf("events.size() = %d\n", events.size());
            for(int i = 0; i < events.size(); i++)
            {
                printf("events[%d] = %d\n", i, events[i]);
                if(events[i])
                {
                    add++;
                }
                else
                {
                    sub++;
                }
            }

            printf("add: %d sub: %d\n", add, sub);
            if(occupied.find(it->first) == occupied.end())
            {
                current_overlap += add;
                if(current_overlap > group_max)
                {
                    group_max = current_overlap;
                }
            }
            else
            {
                if(current_overlap > group_max)
                {
                    group_max = current_overlap;
                }
                current_overlap += add;
            }
            current_overlap -= sub;
        }
    }
    return group_max;
}

int main()
{
    int t;
    t = getNum();
    
    while (t--)
    {
        int w_i, v_i;
        n = getNum();
        w_i = getNum();
        v_i = getNum();

        w = w_i * 1.0;
        v = v_i * 1.0;

        set<double, FloatingPointCompare> occupied;
        unordered_map<int, vector<int>> group_pedestrian;

        for(int i = 0; i < n; i++)
        {
            int x, t, a;
            x = getNum();
            t = getNum();
            a = getNum();

            double vertical_speed = w / (t * 1.0);

            if(vertical_speed > v)
            {
                continue;
            }
            
            p[i].set(x * 1.0, a * 1.0);
            occupied.insert(x * 1.0);

            if(group_pedestrian.find(t) == group_pedestrian.end())
            {
                vector<int> indexer;
                indexer.push_back(i);

                group_pedestrian[t] = indexer;
            }
            else
            {
                vector<int> indexer = group_pedestrian[t];
                indexer.push_back(i);

                group_pedestrian[t] = indexer;
            }
        }

        int current_max = 0;
        for(auto i = group_pedestrian.begin(); i != group_pedestrian.end(); i++)
        {
            int current_collision = calc_group(occupied, i->first, i->second);

            if(current_collision > current_max)
            {
                current_max = current_collision;
            }
        }

        printf("%d\n", current_max);
    }

    return 0;
}