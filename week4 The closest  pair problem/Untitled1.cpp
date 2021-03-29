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
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));//����w�z���I�Z��
}

double mindist( int a, int b )
{
    if ( a > b ) {return 40004;}//����u��1���I�Areturn int
    int l = (a+b)/2,r = (a+b)/2,mid = (a+b)/2; //line:�����X�P�k���X�������ux�y��
    double d = min( mindist( a, mid-1 ), mindist( mid+1, b ) );//�@�����k�����̤p���Z��

    while ( l >= a && d > P[mid].x-P[l].x ){ l --;}//��줤�u���k��d�Z���������u
    while ( r <= b && d > P[r].x-P[mid].x ){ r ++;}

    for ( int i = l+1 ; i < r ; ++ i )
        for ( int j = i+1 ; j < r ; ++ j )
            d = min(d,dist(P[i],P[j]));//�A�����ҬO�_���Z���p��d������I

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
