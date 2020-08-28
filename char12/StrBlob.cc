#include "StrBlob.h"


StrBlob::StrBlob() : data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};

string& StrBlob::front() {
    this->check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    this->check(0,"back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front() const{
    this->check(0,"front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const{
    this->check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}
