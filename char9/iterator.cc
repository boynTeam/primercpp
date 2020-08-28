#include <vector>
#include <iostream>

using namespace std;
vector<int>::iterator find(vector<int> &vec, int value)
{
    auto begin = vec.begin();
    while (begin != vec.end())
    {
        begin++;
        if (value == *begin)
        {
            return begin;
        }
    }
    return vec.end();
}

int main(int argc, char const *argv[])
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    cout << *find(vec,5) << endl;
    cout << *find(vec,16) << endl;
    return 0;
}
