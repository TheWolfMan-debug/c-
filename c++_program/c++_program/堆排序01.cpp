#include <stdio.h>

/* Function: �����������ڵ������ĩβԪ�ص�ֵ*/
void Swap(int *heap, int len)
{
    int temp;

    temp = heap[0];
    heap[0] = heap[len-1];
    heap[len-1] = temp;
}

/* Function: �����󶥶� */
void BuildMaxHeap(int *heap, int len)
{
    int i,temp;
    for (i = len/2-1; i >= 0; i--)
    {
        if ((2*i+1) < len && heap[i] < heap[2*i+1])    /* ���ڵ���������� */
        {
            temp = heap[i];
            heap[i] = heap[2*i+1];
            heap[2*i+1] = temp;
            /* ��齻������������Ƿ�����󶥶����� ��������� �����µ��������ṹ */
            if ((2*(2*i+1)+1 < len && heap[2*i+1] < heap[2*(2*i+1)+1]) || (2*(2*i+1)+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
        if ((2*i+2) < len && heap[i] < heap[2*i+2])    /* ���ڵ���������� */
        {
            temp = heap[i];
            heap[i] = heap[2*i+2];
            heap[2*i+2] = temp;
            /* ��齻������������Ƿ�����󶥶����� ��������� �����µ��������ṹ */
            if ((2*(2*i+2)+1 < len && heap[2*i+2] < heap[2*(2*i+2)+1]) || (2*(2*i+2)+2 < len && heap[2*i+2] < heap[2*(2*i+2)+2]))
            {
                BuildMaxHeap(heap, len);
            }
        }
    }
}

int main()
{
    int a[8]= {70,50,30,20,10,70,40,60};
    int n=8;
    int i;

    for (i = n; i > 0; i--)
    {
        BuildMaxHeap(a, i);
        Swap(a, i);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
