//
// Created by Antoni Dobrenov on 1.07.23.
//
#include <iostream>
#include <fstream>
#include <algorithm>

int numberToDigits(int a, char* charArr) {
    if (a == 0) {
        charArr[0] = '0';
        charArr[1] = '\0';
    }

    int i = 0;

    while (a > 0) {
        charArr[i] = '0' + a % 10;
        i++;
        a = a / 10;
    }

    charArr[i] = '\0';

}

bool isALexLessThanB(int a, int b) {
    if (a == 0) true;
    if (b == 0) false;
    char aDigits[20];
    char bDigits[20];
    numberToDigits(a, aDigits);
    numberToDigits(b, bDigits);
    int aCounterDigits = strlen(aDigits) - 1;
    int bCounterDigits = strlen(bDigits) - 1;
    while (aCounterDigits >= 0 && bCounterDigits >= 0) {
        if (aDigits[aCounterDigits] < bDigits[bCounterDigits]) {
            return true;
        } else if (aDigits[aCounterDigits] > bDigits[bCounterDigits]) {
            return false;
        }
        aCounterDigits--;
        bCounterDigits--;
    }

    if (aCounterDigits == -1 && bCounterDigits == -1) {
        return false;
    }

    if (aCounterDigits == -1) {
        return true;
    }

    return false;

    return aDigits[aCounterDigits] < bDigits[bCounterDigits];
}

void sort_lex(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int k = i+1; k < n; k++) {
            if (isALexLessThanB(arr[k], arr[i])) {
                int swap = arr[i];
                arr[i] = arr[k];
                arr[k] = swap;
            }
        }
    }
}


struct Node {
    char symbol;
    Node* left;
    Node* mid;
    Node* right;

    Node(char symbol) : symbol(symbol), left(nullptr), mid(nullptr), right(nullptr) {};
};

int depth(Node* root) {
    if (root == nullptr){
        return 0;
    }
    return 1 + std::max(depth(root->left), std::max(depth(root->right), depth(root->mid)));
}

void readLastHelper(Node* root, int dep, int currDep, std::string& word) {
    if (root == nullptr) {
        return;
    }
    if (currDep == dep) {
        std::cout << root->symbol;
        word += root->symbol;
        return;
    }
    readLastHelper(root->left, dep, currDep+1, word);
    readLastHelper(root->mid, dep, currDep+1, word);
    readLastHelper(root->right, dep, currDep+1, word);

}

std::string readLast(Node* root) {
    int dep = depth(root);
    std::string word;
    readLastHelper(root, dep, 1, word);
    std::cout << std::endl;
    return word;
}

void serialize(Node* root, std::ofstream& out) {
    if (root == nullptr) {
        out << " *";
        return;
    }
    out << '(' << root->symbol << ' ';
    serialize(root->left, out);
    out << ' ';
    serialize(root->mid, out);
    out << ' ';
    serialize(root->right, out);
    out << ")";
}



int main() {
//    int arr[100];
//    int num = 12345;
//    numberToDigits(num, arr);

    int arr[6] = {13, 14, 7, 2018, 9, 0};
    sort_lex(arr, 6);

//    for (int i = 0; i < 6; i++) {
//        std::cout << arr[i] << ' ';
//    }

    Node* b = new Node('b');
    Node* x = new Node('x');
    Node* p = new Node('p');
    Node* q = new Node('q');
    Node* r = new Node('r');
    Node* c = new Node('c');
    Node* a = new Node('a');
    Node* y = new Node('y');
    Node* s = new Node('s');
    Node* t = new Node('t');

    b->left = x;
    b->mid = y;

    x->left = p;
    x->mid = q;
    x->right = r;

    r->left = c;
    r->right = a;

    y->right = s;

    s->mid = t;

    std::cout << depth(b);
    std::cout << std::endl;

    std::cout << readLast(b);

    std::ofstream ofstream("test.txt");
    serialize(b, ofstream);
//    if (ofstream.is_open()) {
//        ofstream << "(b (x (p * * *) (q * * *) (r (c * * *) * (a * * *))) (y * * (s * (t * * *) *)) *)";
//        ofstream.close();
//    } else {
//        std::cout << "ERROR CREATING FILE\n";
//        return 1;
//    }

    std::ifstream ifstream("test.txt");
    std::string line;
    if (ifstream.is_open()) {
        while(std::getline(ifstream, line)) {
            std::cout << "reading: " << line << std::endl;
        }
        ifstream.close();
    } else {
        std::cout << "ERROR READING FILE";
        return 1;
    }

    return 0;
}