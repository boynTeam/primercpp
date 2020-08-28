#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
int add_(int,int);
int sub_(int,int);
int mul_(int,int);
int div_(int,int);
typedef decltype(add_) *NumFunc;

int main() {
    vector<NumFunc> numFuncs;
    numFuncs.push_back(add_);
    numFuncs.push_back(sub_);
    numFuncs.push_back(mul_);
    numFuncs.push_back(div_);

    std::cout <<"Add:" << numFuncs[0](1,1) << std::endl;
    std::cout <<"Sub:" << numFuncs[1](2,1) << std::endl;
    std::cout <<"Mul:" << numFuncs[2](2,2) << std::endl;
    std::cout <<"Div:" << numFuncs[3](4,2) << std::endl;
}

int add_(int a,int b) {
    return a+b;
}

int sub_(int a,int b) {
    return a-b;
}

int mul_(int a,int b) {
    return a*b;
}

int div_(int a,int b) {
    return a/b;
}