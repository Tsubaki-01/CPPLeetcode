#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>

using namespace std;

// 定义点结构体
struct Point
{
    double x, y;
};

// 计算两点之间的距离
double dis(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// 分治函数
double Divide(Point *point, int left, int right, Point &p1, Point &p2)
{
    // 如果只有一个点，返回无穷大
    if (left == right)
    {
        return INFINITY;
    }
    // 如果只有两个点，直接返回距离
    if (left + 1 == right)
    {
        p1 = point[left];
        p2 = point[right];
        return dis(p1, p2);
    }
    // 大于两个点
    // 分别处理左右子集
    int mid = (left + right) >> 1;
    Point l1, l2, r1, r2;
    double d1 = Divide(point, left, mid, l1, l2);
    double d2 = Divide(point, mid + 1, right, r1, r2);
    double d;
    if (d1 < d2)
    {
        d = d1;
        p1 = l1;
        p2 = l2;
    }
    else
    {
        d = d2;
        p1 = r1;
        p2 = r2;
    }

    // 处理跨越子集的点对
    Point *temp = new Point[right - left + 1];
    int cnt = 0;
    for (int i = left; i <= right; i++)
    {
        if (fabs(point[i].x - point[mid].x) <= d)
        {
            temp[cnt++] = point[i];
        }
    }
    sort(temp, temp + cnt, [](const Point &p1, const Point &p2)
         { return p1.y < p2.y; });
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt && temp[j].y - temp[i].y < d; j++)
        {
            double t = dis(temp[i], temp[j]);
            if (t < d)
            {
                d = t;
                p1 = temp[i];
                p2 = temp[j];
            }
        }
    }
    delete[] temp;
    return d;
}

int main()
{
    // 设定随机数生成器和分布
    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<double> dist(0, 1);

    const int length = 500;           // 设定点的数量
    Point *point = new Point[length]; // 定义点数组

    // 遍历赋值并去重
    int cur_length = 0; // 当前点数组长度
    for (int i = 0; i < length; i++)
    {
        point[i].x = dist(eng);
        point[i].y = dist(eng);
        bool is_duplicate = false;
        for (int j = 0; j < cur_length; j++)
        {
            if (point[i].x == point[j].x && point[i].y == point[j].y)
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            cur_length++;
        }
    }
    // 暴力法求解
    const double INF = 1e9; // 设定初始结果为无穷大
    double ans1 = INF;
    Point p11, p12;
    // 遍历每一组可能，并选择最小值存入结果
    for (int i = 0; i <= cur_length - 1; i++)
    {
        for (int j = i + 1; j <= cur_length - 1; j++)
        {
            if (!(ans1 == min(ans1, dis(point[i], point[j]))))
            {
                p11 = point[i];
                p12 = point[j];
            }
            ans1 = min(ans1, dis(point[i], point[j]));
        }
    }

    cout << "最短距离为: " << ans1 << endl;
    cout << "两点分别为: (" << p11.x << ", " << p11.y << ") and (" << p12.x << ", " << p12.y << ")" << endl;
    // 分治法实现
    sort(point, point + cur_length, [](const Point &p1, const Point &p2)
         { return p1.x < p2.x; });

    Point p1, p2;
    double ans = Divide(point, 0, cur_length - 1, p1, p2);

    cout << "最短距离为: " << ans << endl;
    cout << "两点分别为: (" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y << ")" << endl;

    delete[] point;

    return 0;
}
