#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::cout;

istream& readAndReset(istream& is) {
    auto ori_state = is.rdstate();
    is.clear();
    string word;
    while(is>>word) {
        cout << word << std::endl;
    }
    is.setstate(ori_state);
}


int main(int argc, char const *argv[])
{
    readAndReset(std::cin);
    return 0;
}
