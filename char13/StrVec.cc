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