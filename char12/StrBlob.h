#include <memory>
#include <string>
#include <vector>
using namespace std;

class StrBlob {
    public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const {return data->size();};
    bool empty() const {return data->empty();};

    void push_back(const string& s) {data->push_back(s);};
    void pop_back();

    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    private:
    shared_ptr<vector<string>> data;
    void check(size_type i ,const string& msg) const {
        if (i >= data->size()) {
            throw out_of_range(msg);
        }
    }
};