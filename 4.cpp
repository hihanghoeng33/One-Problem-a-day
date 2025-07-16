#include <cstdio>
#include <cmath>
using namespace std;

// Connection of two circles
int x1, y_1, r1, x2, y2, r2;

int distance(int x1, int y_1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y_1 - y2) * (y_1 - y2));
}

int main()
{
    scanf("%d %d %d %d %d %d", &x1, &y_1, &r1, &x2, &y2, &r2);

    int d = distance(x1, y_1, x2, y2);
    if (x1 == x2 && y_1 == y2)
    {
        if (r1 == r2)
        {
            printf("-1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    else
    {
        if (d > r1 + r2)
        {
            printf("0\n");
        }
        else if (d < fabs(r1 - r2))
        {
            printf("0\n");
        }
        else
        {
            if (d == r1 + r2)
            {
                printf("1\n");
            }
            else if (d == fabs(r1 - r2))
            {
                printf("1\n");
            }
            else if (d < (r1 + r2) && d > fabs(r1 - r2))
            {
                printf("2\n");
            }
        }
    }

    return 0;
}