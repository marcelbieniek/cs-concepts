#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

// https://cses.fi/problemset/task/1083
void missingNumber()
{
    std::size_t size;
    std::cin >> size;

    std::vector<int> input{};
    for (std::size_t i = 0; i < (size - 1); ++i) // (size - 1) because one element is missing
    {
        int num;
        std::cin >> num;
        input.push_back(num);
    }

    std::sort(input.begin(), input.end());

    if (input.front() != 1)
    {
        std::cout << '1' << std::endl;
        return;
    }

    if (input.back() != size)
    {
        std::cout << size << std::endl;
        return;
    }

    for (auto it = input.begin() + 1; it != input.end() - 1; ++it)
    {
        std::cout << *it << std::endl;
        auto nextIt = std::next(it);
        if (nextIt != input.end() && *nextIt != *it + 1)
        {
            std::cout << *it + 1 << std::endl;
            return;
        }
    }
}

// https://cses.fi/problemset/task/1094
void increasingArray()
{
    std::size_t size;
    std::cin >> size;

    std::vector<int> input{};
    for (std::size_t i = 0; i < size; ++i)
    {
        int num;
        std::cin >> num;
        input.push_back(num);
    }

    int minMoves{};
    for (auto it = input.begin() + 1; it < input.end(); ++it)
    {
        auto prevIt = std::prev(it);

        int currentEl = *it;
        int prevEl = *prevIt;
        if (currentEl < prevEl)
        {
            int movesNeeded = prevEl - currentEl;
            minMoves += movesNeeded;
            *it += movesNeeded;
        }
    }

    std::cout << minMoves << std::endl;
}

// https://cses.fi/problemset/task/1069
int repetitions(const std::string& sequence, std::string possibleChars)
{
    if (possibleChars.empty())
    {
        return 0;
    }

    char currentLetter = possibleChars[0];
    possibleChars.erase(0, 1);

    int maxRepLen = 0;
    for (auto it = sequence.begin(); it < sequence.end(); ++it)
    {
        int repLen = 0;
        while (*it == currentLetter)
        {
            repLen++;

            it = std::next(it);
        }

        if (repLen > maxRepLen)
        {
            maxRepLen = repLen;
        }
    }

    int res = repetitions(sequence, possibleChars);
    return res > maxRepLen ? res : maxRepLen;
}

int main()
{
    // int n;
    // std::cin >> n;
    // weirdAlgorithm(n);

    // missingNumber();

    // increasingArray();

    // std::cout << repetitions("ATTCGGGA", "ACGT") << std::endl;

    return 0;
}
