#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include <set>
#include <map>
#include <sstream>

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s,
        std::shared_ptr<std::vector<std::string>> f,
        std::shared_ptr<std::set<int>> p) : word(s), lines(p), file(f) {
    }

private:
    std::string word;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<int>> lines;
};

class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&);

private:
    std::shared_ptr<std::vector<std::string>> file_content;
    std::map<std::string, std::shared_ptr<std::set<int>>> word_line_map;
};

std::string toLower(std::string& s);
std::string removePunct(const std::string& s);
std::string make_plural(size_t sz, const std::string& word, const std::string& ending);
std::ostream& print(std::ostream&, const QueryResult&);