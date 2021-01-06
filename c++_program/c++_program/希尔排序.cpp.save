/*#include<iostream>

using namespace std;
const int INCRGAP = 2;

void shellSort(int a[],int len)
{
    int insertNum = 0;
    unsigned gap = len/INCRGAP; // 步长初始化
    while(gap) // while gap>=1
    {
        for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
        {
            insertNum = a[i];//将当前的元素值先存起来方便后面插入
            unsigned j = i;
            while (j >= gap && insertNum < a[j-gap])//寻找插入位置
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
        }
        gap = gap/INCRGAP;
    }
}
int main()
{
    int array[11] = {2, 1, 4, 3, 11, 6, 5, 7, 8, 10, 15};
    shellSort(array, 11);
    for(auto it: array)
    {
        cout<<it<<" ";
    }
    return 0;
}*/


#include<iostream>
using namespace std;
void shellSort(int arr[], int n)
{
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = 0; i < gap; i++)
        {
            for (j = i + gap; j < n; j += gap)
            {
                for (int k = j; k > i && arr[k] < arr[k-gap]; k -= gap)
                {
                    swap(arr[k-gap], arr[k]);
                }
            }
        }
    }
}

int main()
{
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=8;
    shellSort(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
