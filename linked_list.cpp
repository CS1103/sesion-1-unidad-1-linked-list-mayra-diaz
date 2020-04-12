//
// Created by mayra on 2020-04-11.
//

#include "linked_list.h"

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other){
    size_ = 0;
    int s = other.size();
    auto actual = other.getHead();
    while(s--){
        this->push_back(actual->value_);
        actual = actual->next_;
    }
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept{
    size_ = other.size();
    head = other.getHead();
    tail = other.getTail();
    other.clear();
}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    if (size_ != 0){
        while(size_--)
            this->pop_back();
    }
    size_ = 0;
    int s = other.size();
    auto actual = other.getHead();

    while(s--){
        this->push_back(actual->value_);
        actual = actual->next_;
    }
    return *this;
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    if (size_ != 0){
        while(size_--)
            this->pop_back();
    }
    size_ = other.size();
    head = other.getHead();
    tail = other.getTail();
    other.clear();
    return  *this;
}

void utec::first::linked_list_t::push_front(int value) {
    head = new node_t{value, head};
    if (tail == nullptr) tail = head;
    size_++;
}

void utec::first::linked_list_t::push_back(int value) {
    auto aux = new node_t{value, nullptr};
    if (tail == nullptr) head = tail = aux;
    else{
        tail->next_ = aux;
        tail = aux;
    }
    size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if (index == 0)
        this->push_front(value);
    else if (index == size_)
        this->push_back(value);
    else if (head == tail){
        head = new node_t{value, tail};
        if (tail == nullptr) tail = head;
    }
    else {
        p_item(index - 1)->next_ = new node_t{value, p_item(index)};
        size_++;
    }
}

void utec::first::linked_list_t::pop_front() {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size_ = 0;
    } else {
        auto aux = head->next_;
        delete head;
        head = aux;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() {
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        size_ = 0;
    }
    else {
        auto aux = p_item(size_ - 2);
        delete tail;
        tail = aux;
        tail->next_= nullptr;
        size_--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if (head == tail) head = tail = nullptr;
    else if (index == 0)
        this->pop_front();
    else if (index == size_)
        this->pop_back();
    else{
        auto aux = p_item(index + 1);
        delete p_item(index);
        p_item(index - 1)->next_ = aux;
        size_--;
    }
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}

int utec::first::linked_list_t::item(size_t index) const {
    auto actual = head;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

utec::node_t *utec::first::linked_list_t::p_item(size_t index) const {
    auto actual = head;
    while (index--)
        actual = actual->next_;
    return actual;
}

string utec::first::linked_list_t::complete_list() {
    string list;
    for (int j = 0; j <size_ ; ++j) {
        list += " " + to_string(this->item(j));
    }
    return list;
}

void utec::first::linked_list_t::clear() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

utec::first::linked_list_t::~linked_list_t() {
    auto aux = this->getHead();
    while (aux!= nullptr){
        auto aux_2 = aux->next_;
        delete aux;
        aux = aux_2;
    }
    delete head;
    this->clear();
}

