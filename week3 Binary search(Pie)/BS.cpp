#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath

/*
二元搜尋法:
當左邊的值相離右邊的值的時候
    取左右中間的值作為嘗試
    如果派夠分,左值靠近
    否則,右值靠近
*/

using namespace std;
const int maxn = 10000;
const double pi = acos(-1.0); //arccos(-1) = pi
int T;
int n, f;
int x;
double maxf;
double Pie[maxn];

bool judge(double area)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += floor(Pie[i] / area);	//求出蛋糕大小總和
    return sum >= f + 1;	//超過朋友數+1(要把自己算進去)
}

int main()
{
    cin >> T;	//共有幾筆測資
    while(T--)	
    {
        maxf = -1.0;
        cin >> n >> f;	//派的數量、朋友數量
        for (int i = 0; i < n; i++)
        {
            cin >> x;	//每一個派的半徑大小
            Pie[i] = pi*x*x;	//算出每一個派的面積
            maxf = max(maxf, Pie[i]);	
        }
        double l = 0, r = maxf;
        while (r - l > 1e-4)	//若尚未趨近
        {
            double mid = (r + l) / 2.0;	//進行二元搜尋
            if (judge(mid))	
                l = mid;
            else
                r = mid;
        }
        printf("%.4f\n", l);	//輸出結果取小數點後4位
    }
    return 0;
}