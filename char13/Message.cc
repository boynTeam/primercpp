#include "Message.h"

Message::Message(const Message& m) :contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}
Message& Message::operator=(const Message& rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::add_to_Folders(const Message& msg) {
    for (auto f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for (auto f : this->folders) {
        f->remMsg(this);
    }
}

Message::~Message() {
    remove_from_Folders();
}


void Folder::addMsg(Message* m) {
    messages.insert(m);
}

void Folder::remMsg(Message* m) {
    messages.erase(m);
}