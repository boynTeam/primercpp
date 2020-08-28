#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void lambda_functions() {
    auto add = [](const int a,const int b) {return a+b;};
    
    int a = 0;
    auto add_n = [a](const int b) {return a+b;};

}

void elimDups(vector<string>& words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t sz,const string& word,const string& ending) {
    return (sz > 1) ? word+ending : word;
}

void biggies(vector<string> &words,vector<string>::size_type sz) {
    // 按照字典序排序,去除重复单词
    elimDups(words);
    // 按照长度排序
    stable_sort(words.begin(),words.end(),[](const string& s1,const string& s2){
        return s1.size() < s2.size();
    });

    // 第一个指向单词长度 >= sz的元素
    auto wc = find_if(words.begin(),words.end(),[sz](const string& s){return s.size()>=sz;});

    // 计算满足上面条件的元素数量
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count,"word","s") << " of length " << sz << " or longer " << endl;
    for_each(wc,words.end(),[](const string& s){cout << s << " ";});
    cout << endl;
}

void biggies_par(vector<string> &words,vector<string>::size_type sz) {
    // 按照字典序排序,去除重复单词
    elimDups(words);
    // 按照长度排序
    stable_sort(words.begin(),words.end(),[](const string& s1,const string& s2){
        return s1.size() < s2.size();
    });

    // 第一个指向单词长度 >= sz的元素
    auto wc = partition(words.begin(),words.end(),[sz](const string& s){return s.size()<sz;});

    // 计算满足上面条件的元素数量
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count,"word","s") << " of length " << sz << " or longer " << endl;
    for_each(wc,words.end(),[](const string& s){cout << s << " ";});
    cout << endl;
}

void biggies_stable_par(vector<string> &words,vector<string>::size_type sz) {
    // 按照字典序排序,去除重复单词
    elimDups(words);
    // 按照长度排序
    stable_sort(words.begin(),words.end(),[](const string& s1,const string& s2){
        return s1.size() < s2.size();
    });

    // 第一个指向单词长度 >= sz的元素
    auto wc = stable_partition(words.begin(),words.end(),[sz](const string& s){return s.size()<sz;});

    // 计算满足上面条件的元素数量
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count,"word","s") << " of length " << sz << " or longer " << endl;
    for_each(wc,words.end(),[](const string& s){cout << s << " ";});
    cout << endl;
}

void logger(vector<string> &words,vector<string>::size_type sz) {
    int cnt = count_if(words.begin(),words.end(),[sz](const string& s){return s.size()>=sz;});
}

void subOne() {
    int i = 5;
    auto sub = [&i]()mutable ->bool  {
        if (i>0) {
            i--;
            return true;
        }else {
            return false;
        }
    };
    while(sub()) {
        cout << i << endl;
    }
}



int main() {
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
    biggies_par(word,4);
    biggies(word,4);
    biggies_stable_par(word,4);
    subOne();
}