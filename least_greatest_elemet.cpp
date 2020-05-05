/* \
author: darkshadow_

*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int          long long
#define pb          push_back
#define vi          vector<int>
#define mi          map<int,int>
#define loop(i,a,b)  for(int i=a;i<b;i++)
#define pi          pair<int,int>
struct tree{
struct tree* left,*right;
int val;
};
tree* getnode(int x)
{
    struct tree* temp=new tree;
    temp->left=NULL;
    temp->right=NULL;
    temp->val=x;
    return temp;
}

//returns the value least greater element  in the tree
int treesearch(int x,tree *root)
{
    if(root->val>x)
    {
        if(!root->left)
            return root->val;
        else
        { int m=treesearch(x,root->left);
        if(m==-1)
            return root->val;
            return min(root->val,m);
        }
    }
    else if(root->val<x)
    {
        if(!root->right)
            return -1;
        else
           return treesearch(x,root->right);
    }
    else
           return treesearch(x,root->right);
}
//insert values to binary search tree
insertion(int x,tree* root)
{

    if(root->val>x)
    {
        if(!root->left)
            root->left=getnode(x);
        else
            insertion(x,root->left);

    }
    if(root->val<x)
    {
        if(!root->right)
            root->right=getnode(x);
        else
            insertion(x,root->right);
    }
}
int32_t main()
{
    vi v={ 8, 58, 91, 18, 31, 32, 63, 92,
                  43, 3, 91, 93, 25, 80, 28 };
       int n=v.size();
    reverse(v.begin(),v.end());
    struct tree* root;
    root=getnode(v[0]);
    v[0]=-1;
    for(int i=1;i<n;i++)
    {   int x=v[i];
        v[i]=treesearch(x,root);
         insertion(x,root);
    }
    reverse(v.begin(),v.end());
    loop(i,0,n)
    cout<<v[i]<<" ";
    cout<<endl;

}

