//Score: 0/100
//WA
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-5;
double getRadLen(double l,double d) //issue
{
    double theta = atan(2.0*d/l);//圆周角
    return theta*d+theta*l*l/2.0/d;
}

int main()
{
    double len,temp,coff;
    while(scanf("%lf%lf%lf",&len,&temp,&coff)==3)
    {
        if(len<0||temp<0||coff<0)
        {
            break;
        }
        double radLength = len*(1+temp*coff);
        //printf("radLen=%lf\n",radLength);
        double l=0,r=radLength/PI;
        double mid;
        //二分高度差
        while(r-l>EPS)
        {
            //printf("l=%lf d=%lf radLen=%lf\n",len,mid,getRadLen(len,mid));
            mid=(l+r)/2.0;
            if(getRadLen(len,mid)-radLength>EPS)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        printf("%.3lf\n",r);
    }
    return 0;
}
