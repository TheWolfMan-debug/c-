#include <iostream>

//�ж�ÿ��ֵ����������ٴ�

int main()
{
    int currVal = 0, val = 0;
    //if������䱣֤��ֵ���Բ���
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << currVal << " occurs " << cnt << " times:" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    else if(currVal < '48' || currVal > '57')
    {
        std::cout << "The type of the data is error!!!" << std::endl;
    }
    else
    {
        std::cout << "No numbers in!!!" << std::endl;
    }
    //�����ļ��������������� ���� ����������ݽ�������
    return 0;
}
