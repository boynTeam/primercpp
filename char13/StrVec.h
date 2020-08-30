#include <memory>
#include <string>
#pragma once
class StrVec {
public:
    StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {};
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    void check_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string* elements; // 数组的首元素
    std::string* first_free; // 数组第一个空闲元素
    std::string* cap; // 分配内存的尾后指针
};