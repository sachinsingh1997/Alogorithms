#include <iostream>
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define vi          vector<int>
#define mi          map<int,int>
#define loop(i,a,b)  for(int i=a;i<b;i++)
#define pi          pair<int,int>
using namespace std;
class DisjointSet{
unordered_map<int,int> m;
public:
        void makeset(vector<int> & v)
        {  for(int i:v)
            m[i]=i;
        }
        int Find(int k)
        {int t=k;
            while(m[t]!=t)
                t=m[t];
            return t;
        }
        void Union(int a,int b)
        {
            m[Find(a)]=Find(b);
        }
};
void kruskal(vector<pi> graph[],int edges,vi vertex)
{
    DisjointSet ds;
    ds.makeset(vertex);
    priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi> >> p;
    loop(i,0,edges)
    {
        for(j:graph[i])
        {
            int first=j.first;
            int weight=j.second;
            pair<int,pi>  x;
            x.first=weight;
            x.second.first=first;
            x.second.second=i;
            p.push(x);
        }
    }
    int w=0;
    while(!p.empty())
    {
        int n1=p.top().second.first;
        int n2=p.top().second.second;
        if(ds.Find(n1)!=ds.Find(n2))
        { ds.Union(n1,n2);
            w+=p.top().first;
            cout<<n1<<n2<<" ";
        }
        p.pop();
    }
}
int main()
{ int n;cin>>n;
    int edges;cin>>edges;
    vi vertex(n);
    loop(i,0,n)
    vertex[i]=i;
    vector<pi> graph[edges];
    for(int i=0;i<edges;i++)
    {
        int n1,n2,weight;
        cin>>n1>>n2>>weight;
        graph[n1].push_back({n2,weight});
    }
    kruskal(graph,edges,vertex);


}
