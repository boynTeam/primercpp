#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool sizeBiggerThan4(const string &s)
{
    return s.size() > 4;
}

int main(int argc, char const *argv[])
{
    vector<string> word{
        "fox",
        "quick",
        "jumps",
        "over",
        "fox",
        "jumps",
        "over",
        "the",
        "slow",
        "red",
        "turtle"};

    sort(word.begin(), word.end());
    auto end_unique = unique(word.begin(), word.end());
    word.erase(end_unique, word.end());
    for (auto &s : word)
    {
        cout << s << endl;
    }
    cout << "按长度排列" << endl;
    sort(word.begin(), word.end(), isShorter);
    for (auto &s : word)
    {
        cout << s << endl;
    }
    cout << "长度大于4" << endl;
    auto iter = partition(word.begin(), word.end(),sizeBiggerThan4);
    while(iter != word.begin()) {
        cout << *iter << endl;
        iter--;
    }
    
    return 0;
}