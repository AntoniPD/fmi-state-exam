//
// Created by Antoni Dobrenov on 30.06.23.
//

#include <iostream>

struct node {
    unsigned data;
    node* next;
    node(unsigned data) : data(data), next(nullptr) {}
};

node* copyEveryOther(node* lst) {
    if (!lst) return nullptr;
    node* result = new node(lst->data);
    node* p = result;
    while ((lst = lst->next) && (lst = lst->next)) {
        p->next = new node(lst->data);
        p = p->next;
    }

    return result;
}

int main () {
    node* fst = new node(1);
    node* snd = new node(2);
    node* trd = new node(3);
    node* frd = new node(4);
    node* fifth = new node(5);

    fst->next = snd;
    snd->next = trd;
    trd->next = frd;
    frd->next = fifth;

    node* p = copyEveryOther(fst);
    while (p) {
        std::cout << p->data << ' ';
        p = p->next;
    }

    return 0;
}