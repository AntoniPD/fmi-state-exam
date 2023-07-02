//
// Created by Antoni Dobrenov on 4.06.23.
//
#include <iostream>

template<typename T>
struct node {
    T data;
    node *next;

    node(T const &data, node *next = nullptr) : data(data) {}
};

template<typename T>
class List {
private:
    node<T> *start, *end, *current;

    void copy(List const &cpy) {
        start = end = nullptr;
        node<T> *p = cpy.start;
        while (p) {
            addToEnd(p->data);
            p = p->next;
        }
    }

    void erase() {
        node<T> *p = start;
        while (start != nullptr) {
            p = start;
            start = start->next;
            delete p;
        }
        end = nullptr;
    }

public:

    node<T> *getStart() {
        return start;
    }

    List() : start(nullptr), end(nullptr), current(nullptr) {
        std::cout << "List()\n";
    }

    List(List const &cpy) {
        copy(cpy);
        std::cout << "&List()\n";
    }

    ~List() {
        erase();
        std::cout << "~List()\n";
    }

    List &operator=(List const &cpy) {
        if (this != &cpy) {
            erase();
            copy(cpy);
        }
        return *this;
    }

    bool addToEnd(T const &x) {
        node<T> *p = new node<T>(x);
        if (!start) {
            start = p;
        } else {
            end->next = p;
        }
        end = p;
        return true;
    }

    void print() {
        node<T> *p = start;
        while (p != nullptr) {
            std::cout << p->data << ',';
            p = p->next;
        }
        std::cout << std::endl;
    }

    T getCurrent() {
        return current->data;
    }

    void addAtStart(T const &x) {
        node<T> *p = new node<T>(x);
        p->next = start;
        if (!end) {
            end = p;
        }
        start = p;
    }

    void addAfter(node<T> *elem, const T &x) {
        node<T> *p = new node<T>(x, elem->next);
        elem->next = p;
        if (elem == end) {
            end = p;
        }
    }

    void addBefore(node<T> *p, const T &x) {
        node<T> *q = new node<T>(p->data, p->next);
        p->next = q;
        p->data = x;
        if (end == p) {
            end = q;
        }
    }

};
//
//node<int>* copyEveryOther(node<int>* lst) {
//    if (!lst) return nullptr;
//    node<int>* result = new node<int>(lst->data);
//    node<int>* p = result;
//    while ((lst = lst->next) && (lst = lst->next) ) {
//        p->next = new node<int>(lst->data);
//        p = p->next;
//    }
//    return result;
//}

//struct node {
//        int data; // числов елемент
//        node* next; // следваща кутия в списъка
//// или nullptr, ако няма
//        node(int data, node* next = nullptr)
//        : data(data), next(next)
//        {}
//};

void mystery(node<int> *lst) {
    while (lst && lst->next) {
        lst->data += lst->next->data;
        lst->data /= 2;
        node<int> *tmp = lst->next;
        lst = lst->next = lst->next->next;
        delete tmp;
    }
}

void removeDuplicates(node<int> *list) {
    node<int> *p, *q, *dup;
    p = list;

    while (p != nullptr && p->next != nullptr) {
        q = p;

        while (q->next != nullptr) {
            if (p->data == q->next->data) {
                dup = q->next;
                q->next = q->next->next;
                delete dup;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

void reverseList(node<int> *list) {
    node<int> *current, *prev = nullptr, *next=nullptr;
    current = list;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
}

void splitLists(node<int>* list, int value, node<int>*& smaller, node<int>*& greater) {
    node<int>* current = list;
    node<int>* startSmaller, *startGreater;
    while (current != nullptr) {
        node<int>* newNode = new node<int>(current->data);
        if (current->data <= value) {
            if (smaller == nullptr) {
                smaller = newNode;
                startSmaller = smaller;
            } else {
                smaller->next = newNode;
                smaller = newNode;
            }
        } else {
            if (greater == nullptr) {
                greater = newNode;
                startGreater = greater;
            } else {
                greater->next = newNode;
                greater = newNode;
            }
        }
        current = current->next;
    }
    smaller = startSmaller;
    greater = startGreater;
}

void print(node<int>* start) {
    node<int> *p = start;
    while (p != nullptr) {
        std::cout << p->data << ',';
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    List<int> l = List<int>();
    l.addToEnd(1);
    l.addToEnd(2);
    l.addToEnd(3);
    l.addToEnd(4);
    l.addToEnd(5);
    l.addToEnd(6);
    l.addToEnd(7);
    l.addToEnd(8);
    node<int>* a;
    node<int>* b;
    splitLists(l.getStart(), 4, a, b);
    print(a);
    print(b);
    std::cout << std::endl;
//    removeDuplicates(l.getStart());
    reverseList(l.getStart());
    l.print();
//    node<int>* p = copyEveryOther(l.getStart());
//    while(p != nullptr) {
//        std::cout << p->data << ',' << std::endl;
//        p = p->next;
//    }

//    node* e = new node(56);
//    node* d = new node(20, e);
//    node* c = new node(10, d);
//    node* b = new node(4, c);
//    node* a = new node(2, b);
//    mystery(a);
//    while (a) {
//        std::cout << "[" << a->data << "] -> ";
//        a = a->next;
//    }
//    std::cout << "NULL";

//    List<int> a = l;
//    a.addToEnd(5);
//    l.print();
//    a.print();
    return 0;
}