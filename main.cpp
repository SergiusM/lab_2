#include <iostream>
#include <algorithm>

// ���� �� � ������ s �������� �����
bool isConsist(int i, char c, std::string& s)
{
    if (i > s.length())
        return false;
    if (s[i] == c)
        return true;
    return isConsist(i + 1, c, s);
}

// ��������� f(n) = n * f(n-1)
int f(int n)
{
    // 1. ������������� �������
    if (n == 0)
        return 1;

    // 2. ������ �������� � ������������� �����������
    return n * f(n - 1);
}

int main()
{
    std::cout << f(6) << std::endl;
    std::string s = "bcad";
    std::cout << isConsist(0, 'e', s) << std::endl;

    int x[10] = { 1,2,3,462,621,6,2,6,7 };
    std::sort(x, x + 10);

    return 0;
}