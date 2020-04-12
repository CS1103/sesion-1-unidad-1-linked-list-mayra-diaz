#include <iostream>
#include <string>
#include <cassert>
#include "linked_list.h"

using namespace std;
int main() {
    utec::linked_list_t l_list{};

    //Probar el metodo push_front;
    for(int i=0; i<10; ++i){
        l_list.push_front(i);
    }
    assert(l_list.complete_list() == " 9 8 7 6 5 4 3 2 1 0");


    //Verificar tamaño
    assert(l_list.size() == 10);


    //Verificar pop_front
    for(int i=0; i<5; ++i){
        l_list.pop_front();
    }
    assert(l_list.size() == 5);
    assert(l_list.complete_list() == " 4 3 2 1 0");


    //Probar el metodo push_back;
    for(int i=5; i<10; ++i){
        l_list.push_back(i);
    }
    assert(l_list.size() == 10);
    assert(l_list.complete_list() == " 4 3 2 1 0 5 6 7 8 9");


    //Verificar pop_back
    for(int i=0; i<5; ++i){
        l_list.pop_back();
    }
    assert(l_list.size() == 5);
    assert(l_list.complete_list() == " 4 3 2 1 0");


    //Verificar insert
    l_list.insert(2, 15);
    assert(l_list.size() == 6);
    assert(l_list.complete_list() == " 4 3 15 2 1 0");

    //Verificar erase
    l_list.erase(2);
    assert(l_list.size() == 5);
    assert(l_list.complete_list() == " 4 3 2 1 0");



    //Verificar Construcctores

    //copia de otro linked_list
    auto copy_1(l_list);
    assert(l_list.complete_list() == copy_1.complete_list());

    //sobrecarga del operador = con otro linked_list
    auto operator_1 = l_list;
    assert(l_list.complete_list() == operator_1.complete_list());

    copy_1.push_back(7);
    operator_1 = copy_1;
    assert(copy_1.complete_list() == operator_1.complete_list());

    /*
    //copia de otro linked_list usando MOVE
    string moved_1 = copy_1.complete_list();
    auto copy_2 = move(copy_1);
    assert(moved_1 == copy_2.complete_list());

    //sobrecarga del operador = con otro linked_list usando MOVE
    string moved_2 = operator_1.complete_list();
    auto operator_2 = move(operator_1);
    assert(moved_2 == copy_2.complete_list());
    */

    cout << "\nEjecución exitosa";
    return EXIT_SUCCESS;
}
