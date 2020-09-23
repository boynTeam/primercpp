#include "StrVec.h"

void StrVec::push_back(const std::string& s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
    auto data = alloc.allocate(e - b);
    return { data,uninitialized_copy(b,e,data) };
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free;p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    this->elements = newdata.first;
    this->first_free = this->cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec& rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    this->elements = data.first;
    this->first_free = this->cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0;i != size(); i++) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}