#include<iostream>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

class point
{
	public:
		double x,y;
};

point P[10004];

bool cmp( point a, point b )
{
    return a.x < b.x;
}

double dist( point a, point b )
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));//畢氏定理兩點距離
}

double mindist( int a, int b )
{
    if ( a > b ) {return 40004;}//切到只剩1個點，return int
    int l = (a+b)/2,r = (a+b)/2,mid = (a+b)/2; //line:左集合與右集合的中間線x座標
    double d = min( mindist( a, mid-1 ), mindist( mid+1, b ) );//一直左右分找到最小的距離

    while ( l >= a && d > P[mid].x-P[l].x ){ l --;}//找到中線左右邊d距離的那條線
    while ( r <= b && d > P[r].x-P[mid].x ){ r ++;}

    for ( int i = l+1 ; i < r ; ++ i )
        for ( int j = i+1 ; j < r ; ++ j )
            d = min(d,dist(P[i],P[j]));//再次驗證是否有距離小於d的兩個點

    return d;
}

int main()
{
    int n;

    while ( cin>>n )
    {
        if(n==0){break;}
        for ( int i = 0 ; i < n ; ++ i )
		{cin>>P[i].x>>P[i].y;}

        sort( P, P+n, cmp );
        double d = mindist( 0, n-1 );
        if ( d >= 10000 )
            cout<<"INFINITY"<<endl;
        else printf("%.4lf\n",d);
    }
    return 0;
}
