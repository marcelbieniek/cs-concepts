#include <iostream>
#include <vector>
#include <algorithm>

// https://cses.fi/problemset/task/1068/
void weirdAlgorithm(int n)
{
    std::cout << n << " ";

    if (n == 1)
    {
        return;
    }

    return weirdAlgorithm(n % 2 == 0 ? n / 2 : n * 3 + 1);
}

int main()
{
    // int n;
    // std::cin >> n;
    // weirdAlgorithm(n);

    return 0;
}
