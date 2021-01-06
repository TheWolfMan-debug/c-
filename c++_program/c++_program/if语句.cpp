#include <iostream>

//判断每个值连续输入多少次

int main()
{
    int currVal = 0, val = 0;
    //if条件语句保证有值可以操作
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
    //输入文件结束符结束输入 或者 输入错误数据结束输入
    return 0;
}
