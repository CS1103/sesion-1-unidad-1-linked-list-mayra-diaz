//
// Created by mayra on 2020-04-11.
//

#ifndef UNO_LINKED_LIST_H
#define UNO_LINKED_LIST_H

#include <cctype>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

namespace utec {

    struct node_t{
        int value_ = 0;
        node_t* next_ = nullptr;
    };

    inline namespace first{
        class linked_list_t {
        private:
            node_t* head = nullptr;
            node_t* tail = nullptr;
            size_t size_ = 0;


            node_t* p_item(size_t index) const ;
        public:
            //constructores
            linked_list_t() = default;
            linked_list_t(const linked_list_t& other);
            linked_list_t (linked_list_t&& other) noexcept ;
            linked_list_t& operator=(const linked_list_t& other);
            linked_list_t& operator=(linked_list_t&& other) noexcept ;

            //destructor
            virtual ~linked_list_t()= default;

            //add operations
            void push_front(int value);
            void push_back(int value);
            void insert(size_t index, int value);

            // remove operations
            void pop_front();
            void pop_back();
            void erase(size_t index);

            //getters
            size_t size() const ;
            node_t *getHead() const {
                return head;}
            node_t *getTail() const {
                return tail;
            }

            //get item
            int item(size_t index) const ;

            //get list
            string complete_list();

        };
    }

}
#endif //UNO_LINKED_LIST_H
