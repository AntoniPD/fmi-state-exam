//
// Created by Antoni Dobrenov on 1.07.23.
//
#include <iostream>
#include <vector>

int sizeOfString(const char *str) {
    int size = 0;
    while (str[size]) {
        size++;
    }
    return size;
}

void zad1(const char *str) {
    const int stringSize = sizeOfString(str);
    int map[stringSize];
    int i = 0;
    while (str[i] != '\0') {
        char currentChar = str[i];
        int j = i + 1;
        map[i] = 0;
        while (str[j] != '\0') {
            if (str[i] == str[j]) {
                map[i] = j - i;
            }
            j++;
        }
        i++;
    }

    int max = map[0];
    int pos = 0;
    for (int i = 0; i < stringSize; i++) {
        if (map[i] > max) {
            max = map[i];
            pos = i;
        }
    }
    std::cout << "max dist: " << max << " , pos: " << pos << " , " << pos + max;
}

struct Node {
    int data;
    std::vector<Node *> children;

    Node(int data) : data(data) {};
};

void f(int K, int n, int currentIndex, int* arr, Node* tree, int depth) {
    if (tree->children.empty() && currentIndex < n && depth < K) {
        depth++;
        int copyK = K;
        while(copyK > 0 && currentIndex < n) {
            tree->children.push_back(new Node(arr[currentIndex]));
            currentIndex++;
            copyK--;
        }
        for (int i = 0; i < tree->children.size(); i ++) {
            f(K, n, (currentIndex + i*K), arr, tree->children[i], depth);
        }
    }
    return;
}

void printTree(Node* tree) {
    std::cout << tree->data;
    for (int i = 0; i < tree->children.size(); i ++) {
        printTree(tree->children[i]);
    }
}

void zad2(int K, int arr[], int n) {
    if (n < 1) {
        return;
    }
    Node *tree = new Node(arr[0]);
    f(K, n, 1, arr, tree, 1);
    std::cout << tree->data;
}




int main() {
    char arr[] = "this is just a simple example";
    int ar[15] = {1, 2, 3, 4, 5 ,6,7,8,9,10, 11, 12, 13, 14, 15};
    int n = sizeof(arr) / sizeof(*arr);
    zad2(3, ar, 15);
    zad1(arr);
    std::cout << std::endl;

    return 0;
}