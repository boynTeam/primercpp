#include "TextQuery.h"
std::string toLower(std::string& s)
{
    for (int i = 0; i < s.size(); i++) {
        s[i] = char(tolower(s[i]));
    }
    return s;
}

std::string make_plural(size_t sz, const std::string& word, const std::string& ending)
{
    return (sz > 1) ? word + ending : word;
}

std::string removePunct(const std::string& s)
{
    std::ostringstream stream;
    for (const auto c : s) {
        if (!ispunct(c)) {
            stream << c;
        }
    }
    return stream.str();
}

TextQuery::TextQuery(std::ifstream& f) : file_content(new std::vector<std::string>)
{
    std::string line;
    while (getline(f, line)) {
        file_content->push_back(line);
        std::istringstream linestream(line);
        int n = file_content->size() - 1;

        std::string word;
        while (linestream >> word) {
            word = removePunct(toLower(word));
            if (word.empty()) {
                continue;
            }

            auto& lines = word_line_map[word];
            if (!lines) {
                lines.reset(new std::set<int>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string& word)
{
    static std::shared_ptr<std::set<int>> nodata =
        std::make_shared<std::set<int>>();

    auto loc = word_line_map.find(word);
    if (loc == word_line_map.end()) {
        return QueryResult(word, file_content, nodata);
    }
    else {
        return QueryResult(word, file_content, loc->second);
    }
}

std::ostream& print(std::ostream& os, const QueryResult& result)
{
    os << result.word << " occurs " << result.lines->size() << " " << make_plural(result.lines->size(), "time", "s") << std::endl;
    for (auto num : *result.lines) {
        os << "\t"
            << "(line " << num + 1 << ") "
            << *(result.file->begin() + num) << std::endl;
    }
    return os;
}
