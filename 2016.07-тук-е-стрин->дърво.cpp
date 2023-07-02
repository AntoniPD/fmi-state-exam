//
// Created by Antoni Dobrenov on 1.07.23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>


struct Node {
    int data;
    std::vector<Node *> children;

    Node(int data) : data(data) {};
};

void zadacha(std::string treeInTxt) {
    for (int i = 0; i < treeInTxt.size(); i++) {
        std::cout << treeInTxt[i];
    }
}

bool isCharADigit(char a) {
    return a >= '0' && a <= '9';
}

int numFromString(std::string treeInTxt, int &i) {
    int num = 0;
    while (isCharADigit(treeInTxt[i])) {
        num *= 10;
        num += (treeInTxt[i] - '0');
        i++;
    }

    return num;
}

Node *fen(std::string treeInTxt) {
    std::stack<Node *> nodesStack;
    std::stack<int> parentheses;
    int i = 1;
    parentheses.push(i);
    Node *tree = new Node(numFromString(treeInTxt, i));
    nodesStack.push(tree);
    while (i < treeInTxt.size()) {
        if (treeInTxt[i] == '(') {
            parentheses.top()++;
        } else if (treeInTxt[i] == ')') {
            parentheses.top()--;
            if (parentheses.top() == 0) {
                parentheses.pop();
                nodesStack.pop();
            }
        } else if (isCharADigit(treeInTxt[i])) {
            Node *newNode = new Node(numFromString(treeInTxt, i));
            nodesStack.top()->children.push_back(newNode);
            nodesStack.push(newNode);
            parentheses.push(0);
        }
        i++;
    }

    return tree;
}

int depth(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    int dep = 1;
    for (int i = 0; i < root->children.size(); i++) {
        dep = std::max(dep, 1 + depth(root->children[i]));
    }

    return dep;
}

//void myf(std::string treeInTxt, Node* tree) {
//    std::stack<char> stChars;
//    for (int i = 0; i < treeInTxt.size(); i ++) {
//        switch (treeInTxt[i]) {
//            case '(':
//                stChars.push(treeInTxt[i]);
//                break;
//            case ' ':
//                break;
//            case ')':
//
//            case ',':
//                break;
//            default:
//                int num = 0;
//                while(treeInTxt[i] >= '0' && treeInTxt[i+1] <= '9')
//                {
//                    num *= 10;
//                    num += (treeInTxt[i] - '0');
//                    i++;
//                }
//                tree = new Node(num);
//
//        }
//    }
//}

void LevelOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    // Standard level order traversal code
    // using queue
    std::queue<Node *> q;  // Create a queue
    q.push(root); // Enqueue root
    while (!q.empty()) {
        int n = q.size();

        // If this node has children
        while (n > 0) {
            // Dequeue an item from queue and print it
            Node *p = q.front();
            q.pop();
            std::cout << p->data << " ";

            // Enqueue all children of the dequeued item
            for (int i = 0; i < p->children.size(); i++)
                q.push(p->children[i]);
            n--;
        }

        std::cout << std::endl; // Print new line between two levels
    }
}

void printTree(Node *tree) {
    std::cout << tree->data << " -> ";
    for (int i = 0; i < tree->children.size(); i++) {
        std::cout << tree->data << std::endl;
        printTree(tree->children[i]);
    }
}


int main() {
    std::ofstream outputFile("example.txt");
    if (outputFile.is_open()) {
        outputFile << "(5 ((9 ()), (1 ((4 ()), (12 ()), (42 (12 (18 ()))))))";
        outputFile.close();
        std::cout << "File created and written successfully.\n";
    } else {
        std::cout << "Failed to create the file.\n";
        return 1;
    }

    // Read from the file
    std::string line;
    std::ifstream inputFile("example.txt");
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
        std::cout << "File read successfully.\n";
    } else {
        std::cout << "Failed to open the file.\n";
        return 1;
    }

    // Примерен обхождащ алгоритъм за дървото (preorder traversal)
    Node *tree = fen(line);
    LevelOrderTraversal(tree);
    std::cout << std::endl;
    std::cout << depth(tree);
    return 0;
}