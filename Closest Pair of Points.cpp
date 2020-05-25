//Closest Pair of Points using Divide and Conquer algorithm
/*
author: Sachin Singh
codeforces : darkshadow_
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define vi          vector<int>
#define mi          map<int,int>
#define loop(i,a,b)  for(int i=a;i<b;i++)

class point{
public:
    int x;
    int y;
};
bool xcomp(point p1,point p2)
{
    return p1.x<p2.x;
}
bool ycomp(point p1,point p2)
{
    return p1.y<p2.y;
}

float mindist(int s,int e,vector<point> &v)
{
    if(e-s==1)
    {
         float x=(float)sqrt(pow(abs(v[s].x-v[e].x),2)+pow(abs(v[s].y-v[e].y),2));
            return x;
    }
    else
    {
        float x=(float)sqrt(pow(abs(v[s].x-v[e].x),2)+pow(abs(v[s].y-v[e].y),2));
        float y=(float)sqrt(pow(abs(v[s+1].x-v[e].x),2)+pow(abs(v[s+1].y-v[e].y),2));
        float z=(float)sqrt(pow(abs(v[s].x-v[s+1].x),2)+pow(abs(v[s].y-v[s+1].y),2));
        return min({x,y,z});
    }
}
float compy(vector<point> v,float d)
{ float t=INT_MAX;
    int n=v.size();
    loop(i,0,n)
    {
        loop(j,i+1,n)
        {
            if(v[j].y-v[i].y<=d)
            {float x=(float)sqrt(pow(abs(v[i].x-v[j].x),2)+pow(abs(v[i].y-v[j].y),2));
                t=min(t,x);
            }
            else
                break;

        }
    }
    return t;
}


float divide(int s,int e,vector<point> &v)
{
    if(e-s<=3)
        return mindist(s,e,v);

    float dl=divide(s,(s+e)/2,v);
    float dr=divide((s+e)/2+1,e,v);
    float d=min(dl,dr);
    int mid =v[(s+e)/2].x;
    vector<point> v2;
    loop(i,s,e+1)
    {if(abs(v[i].x-mid)<=d)
            v2.pb(v[i]);
    }
    sort(v2.begin(),v2.end(),ycomp);
    d=min(d,compy(v2,d));
    return d;
}
void solve()
{
    int n;cin>>n;
    vector<point> v(n);
    loop(i,0,n)
    cin>>v[i].x;
    loop(i,0,n)
    cin>>v[i].y;
    //cout<<v[0].y;
    sort(v.begin(),v.end(),xcomp);
   cout<< divide(0,n-1,v)<<endl;

}
int main()
{ int t;
cin>>t;
while(t--)
{
    solve();
}
}
