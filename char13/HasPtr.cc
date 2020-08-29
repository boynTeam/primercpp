#include <string>


class HasPtr {
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& ptr) {
        delete this->ps;
        ps = new std::string(*ptr.ps);
        i = 0;
    }
    HasPtr& operator=(const HasPtr& ptr) {
        delete this->ps;
        this->ps = new std::string(*ptr.ps);
        this->i = ptr.i;
        return *this;
    }
    ~HasPtr() {
        delete ps;
    }
private:
    std::string* ps;
    int i;
};