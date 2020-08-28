#include <vector>
#include <string>
#include <iostream>
using std::vector;

int main() {
    vector<int> ivec;
    vector<int> ivec2(ivec);
    vector<std::string> svec{10,"hi"};

    // std::string word;
    // vector<std::string> text;
    // while(std::cin>>word) {
    //     text.push_back(word);
    // }
    // std::cout << "Word size:" << text.size() << std::endl;
    // int num;
    // vector<int> numbers;
    // while(std::cin>>num) {
    //     numbers.push_back(num);
    // } 
    // std::cout << "Numbers size:" << numbers.size() << std::endl;

    // std::string word;
    // vector<std::string> text;
    // while(std::cin>>word) {
    //     for(int i =0;i<word.size();i++) {
    //         if (word[i]>=97 && word[i]<=122) {
    //             word[i] = word[i]-32;
    //         }
    //     }
    //     text.push_back(word);
    // }

    // for(auto w : text) {
    //     std::cout << w << std::endl;
    // }

    int num;
    vector<int> numbers;
    while(std::cin>>num) {
        numbers.push_back(num);
    }

    for(int i = 0;i<numbers.size()/2+1;i++) {
        int fro = i;
        int back = numbers.size() - i -1;
        if(fro==back) {
            std::cout << numbers[fro] << std::endl;
            continue;
        }
        std::cout << numbers[fro] + numbers[back] << std::endl;
    }
} 