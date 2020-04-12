#include <iostream>
#include <string>
#include <cassert>
#include "linked_list.h"

using namespace std;
int main() {
    utec::linked_list_t ll{};

    //Probar el metodo push_front;
    for(int i=0; i<10; ++i){
        ll.push_front(i);
    }
    assert(ll.complete_list() == " 9 8 7 6 5 4 3 2 1 0");


    //Verificar tamaño
    assert(ll.size() == 10);


    //Verificar pop_front
    for(int i=0; i<5; ++i){
        ll.pop_front();
    }
    assert(ll.size() ==5);
    assert(ll.complete_list() == " 4 3 2 1 0");


    //Probar el metodo push_back;
    for(int i=5; i<10; ++i){
        ll.push_back(i);
    }
    assert(ll.size()==10);
    assert(ll.complete_list() == " 4 3 2 1 0 5 6 7 8 9");


    //Verificar pop_back
    for(int i=0; i<5; ++i){
        ll.pop_back();
    }
    assert(ll.size() ==5);
    assert(ll.complete_list() == " 4 3 2 1 0");


    //Verificar insert
    ll.insert(2, 15);
    assert(ll.size() ==6);
    assert(ll.complete_list() == " 4 3 15 2 1 0");

    //Verificar erase
    ll.erase(2);
    assert(ll.size() ==5);
    assert(ll.complete_list() == " 4 3 2 1 0");



    //Verificar Construcctores
    //copia de otro linked_list
    utec::linked_list_t c1(ll);
    assert(ll.complete_list() == c1.complete_list());

    //copia de otro linked_list usando MOVE
    //utec::linked_list_t c2(&&ll);
    //assert(ll.complete_list() == c2.complete_list());

    //sobrecarga del operador = con otro linked_list
    utec::linked_list_t c3 = ll;
    assert(ll.complete_list() == c3.complete_list());

    c1.push_back(7);
    c3 = c1;
    assert(c1.complete_list() == c3.complete_list());

    //sobrecarga del operador = con otro linked_list usando MOVE
    //utec::linked_list_t c4 = ll;

    cout << "\nEjecución exitosa";
    return EXIT_SUCCESS;
}
