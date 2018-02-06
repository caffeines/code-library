#include <bits/stdc++.h>
using namespace std;
#define N 100001
int arr[N];
int tree[N*3];
void init(int curr,int start,int end)
{
    if(end == start)
    {
        tree[curr] = arr[end];
        return;
    }
    int left = curr*2;
    int right = (curr*2)+1;
    int mid = (start+end)/2;
    init(left,start,mid);
    init(right,mid+1,end);
    tree[curr] = tree[left] + tree[right];
}

void update(int curr,int start, int end,int pos,int value)
{
    if(start==pos && end==pos)
    {
        tree[curr] = value;
        return;
    }
    if(start>end || start>pos || end<curr)
        return;
    int left = curr*2;
    int right = (curr*2)+1;
    int mid = (start+end)/2;

    update(left,start,mid,pos,value);
    update(right,mid+1,end,pos,value);
    tree[curr] = tree[left]+tree[right];
}
int query(int curr,int start,int end,int first,int last)
{
    if(start>=first && end<=last)
        return tree[curr];
    if(first>end || last<start)
        return 0;

    int left = curr*2;
    int right = (curr*2)+1;
    int mid = (start+end)/2;

    int q1 = query(left,start,mid,first,last);
    int q2 = query(right,mid+1,end,first,last);
    return q1+q2;


}
int main()
{
    arr[1]=3;arr[2]=2;arr[3]=1;arr[4]=4;arr[5]=5;//input in array
    init(1,1,5);//tree building here

    cout<<query(1,1,5,1,5)<<endl;//query
    update(1,1,5,3,1000);//update
    cout<<query(1,1,5,1,5)<<endl;

    return 0;
}
