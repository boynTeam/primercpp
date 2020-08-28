#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec_int{1,2,3,4,5,6,7,8,8,8,9,10};
    cout << accumulate(vec_int.cbegin(),vec_int.cend(),0) << endl;

    vector<double> vec_double{1.1,2.0,3.0,4.0,5.0,6.0,7.0,8.0,8.0,8.0,9.0,10.0};
    cout << accumulate(vec_double.cbegin(),vec_double.cend(),0.0) << endl;

    vector<string> vec_str{"a","b","b","b"};
    cout << count(vec_str.cbegin(),vec_str.cend(),"a") << endl;
    cout << count(vec_str.cbegin(),vec_str.cend(),"b") << endl;
    return 0;
}
