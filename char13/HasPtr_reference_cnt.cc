#include <string>


class HasPtr {
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr(const HasPtr& ptr) : ps(ptr.ps), i(ptr.i), use(ptr.use) {
        *use++;
    }
    HasPtr& operator=(const HasPtr& ptr) {
        ++* ptr.use;
        if (-- * use == 0) {
            delete ps;
            delete use;
        }
        ps = ptr.ps;
        use = ptr.use;
        i = ptr.i;
        return *this;
    }
    ~HasPtr() {
        if (-- * use == 0) {
            delete ps;
            delete use;
        }
    }
    void swap(HasPtr& lhs, HasPtr& rhs) {
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }
private:
    std::string* ps;
    int i;
    std::size_t* use; // 引用计数的计数器
};