#include <string>
#include <memory>
#include <set>
#include <iostream>

#pragma once

class Message {
    friend class Folder;
public:
    explicit Message(const std::string& str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

class Folder {
    friend class Message;
private:
    std::set<Message*> messages;
public:
    void addMsg(Message*);
    void remMsg(Message*);
};

