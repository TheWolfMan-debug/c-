#include<iostream>
using namespace std;
void insert_sort(int a[],int n)
{
    int i,j;
    for(i=1; i<n; i++)   //循环从第2个元素开始
    {
        if(a[i]<a[i-1])
        {
            int temp=a[i];
            for(j=i-1; j>=0 && a[j]>temp; j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=temp;//此处就是a[j+1]=temp;
        }
    }
}

int main()
{
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=7;
    insert_sort(a,n);
    for(int i=0; i<=n; i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
