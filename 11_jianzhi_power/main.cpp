#include <iostream>

using namespace std;

bool g_InvalidInput = false;
bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.000001) && (num1-num2 < 0.000001))
        return true;
    else
        return false;
}
/*double powerWithUnsignedExponent(double base, int exponent)
{
    double res = 1.0;
    for(int i =0; i <exponent; i++)
    {
        res *= base;
    }
    return res;
}*/
double powerWithUnsignedExponent(double base, int exponent)
{
    if(exponent == 0)
        return 1.0;
    if(exponent == 1)
        return base;
    double res = powerWithUnsignedExponent(base, exponent>>1);
    res *= res;
    if(exponent &0x1)
        res*=base;
    return res;
}
double Power(double base, int exponent)
{
    double res = 0.0;
    g_InvalidInput = false;
    if(equal(base, 0.0) && exponent<0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    if(exponent < 0)
    {
        res = powerWithUnsignedExponent(base,-exponent);
        res = 1.0/res;
    }
    else
        res = powerWithUnsignedExponent(base,exponent);
    return res;
}
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    cout << result << endl;
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main()
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;


}
