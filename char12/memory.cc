#include <memory>
#include <string>
#include <vector>
#include <iostream>

void read_in_vector_ptr(std::vector<std::string>* vec_ptr) {
    std::string word;
    while (std::cin >> word) {
        vec_ptr->push_back(word);
    }
}

void read_in_vector_shared(std::shared_ptr<std::vector<std::string>> vec_shared) {
    std::string word;
    while (std::cin >> word) {
        vec_shared->push_back(word);
    }
}

void print_vector_ptr(std::vector<std::string>* vec_ptr) {
    for (auto w : *vec_ptr) {
        std::cout << w << std::endl;
    }
}

void print_vector_shared(std::shared_ptr<std::vector<std::string>> vec_shared) {
    for (auto w : *vec_shared) {
        std::cout << w << std::endl;
    }
}

int main(int argc, char const* argv[])
{
    std::vector<std::string>* vec = new std::vector<std::string>();
    read_in_vector_ptr(vec);
    print_vector_ptr(vec);
    delete vec;

    std::shared_ptr<std::vector<std::string>> vec_shared = std::make_shared<std::vector<std::string>>();
    read_in_vector_shared(vec_shared);
    print_vector_shared(vec_shared);
    return 0;
}
