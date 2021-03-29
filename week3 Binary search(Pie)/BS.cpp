#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath

/*
�G���j�M�k:
���䪺�Ȭ����k�䪺�Ȫ��ɭ�
    �����k�������ȧ@������
    �p�G������,���Ⱦa��
    �_�h,�k�Ⱦa��
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
        sum += floor(Pie[i] / area);	//�D�X�J�|�j�p�`�M
    return sum >= f + 1;	//�W�L�B�ͼ�+1(�n��ۤv��i�h)
}

int main()
{
    cin >> T;	//�@���X������
    while(T--)	
    {
        maxf = -1.0;
        cin >> n >> f;	//�����ƶq�B�B�ͼƶq
        for (int i = 0; i < n; i++)
        {
            cin >> x;	//�C�@�Ӭ����b�|�j�p
            Pie[i] = pi*x*x;	//��X�C�@�Ӭ������n
            maxf = max(maxf, Pie[i]);	
        }
        double l = 0, r = maxf;
        while (r - l > 1e-4)	//�Y�|���ͪ�
        {
            double mid = (r + l) / 2.0;	//�i��G���j�M
            if (judge(mid))	
                l = mid;
            else
                r = mid;
        }
        printf("%.4f\n", l);	//��X���G���p���I��4��
    }
    return 0;
}