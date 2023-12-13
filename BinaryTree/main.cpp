#include <iostream>

struct Node {
    int current;
    Node* prev;
    Node* l_child;
    Node* r_child;

    Node(int value, Node* l_v = nullptr, Node* r_v = nullptr) : current(value), l_child(l_v), r_child(r_v), prev(nullptr) {};
};

class BinaryTree {
public:
    BinaryTree() : Root(nullptr) {};
    void push_node(int value);
    bool find_node(int value);
    bool delete_node(int value);
    void clear_nodes(Node* root);

private:
    Node* Root;
};

void BinaryTree::clear_nodes(Node* root) {
    Node* l_temp = root->l_child;
    Node* r_temp = root->r_child;
    if (l_temp == nullptr && r_temp == nullptr)
        return;
    delete root;
    clear_nodes(l_temp);
    clear_nodes(r_temp);
}

bool BinaryTree::find_node(int value) {
    if (Root == nullptr)
        return false;
    Node* cur = Root;
    while (cur != nullptr && cur->current != value) {
        if (value <= cur->current) {
            cur = cur->l_child;
        } else {
            cur = cur->r_child;
        }
    }
    return (cur != nullptr && cur->current == value);
}

void BinaryTree::push_node(int value) {
    if (Root == nullptr) {
        Root = new Node(value);
        return;
    }

    Node* cur = Root;
    while (cur != nullptr) {
        if (value <= cur->current) {
            if (cur->l_child == nullptr) {
                cur->l_child = new Node(value);
                return;
            }
            cur = cur->l_child;
        } else {
            if (cur->r_child == nullptr) {
                cur->r_child = new Node(value);
                return;
            }
            cur = cur->r_child;
        }
    }
}

bool BinaryTree::delete_node(int value) {
    Node* parent = nullptr;
    Node* current = Root;

    while (current != nullptr && current->current != value) {
        parent = current;
        current = (value < current->current) ? current->l_child : current->r_child;
    }

    if (current == nullptr) {
        return false;
    }

    Node* replacement = (current->l_child == nullptr) ? current->r_child : current->l_child;

    if (parent == nullptr) {
        delete Root;
        Root = replacement;
    } else if (parent->l_child == current) {
        parent->l_child = replacement;
    } else {
        parent->r_child = replacement;
    }

    if (current->l_child != nullptr && current->r_child != nullptr) {
        Node* successorParent = current;
        Node* successor = current->r_child;

        while (successor->l_child != nullptr) {
            successorParent = successor;
            successor = successor->l_child;
        }

        current->current = successor->current;

        if (successorParent != current) {
            successorParent->l_child = successor->r_child;
        } else {
            current->r_child = successor->r_child;
        }

        delete successor;
    } else {
        delete current;
    }

    return true;
}

int main() {
    BinaryTree tree;

    tree.push_node(50);
    tree.push_node(30);
    tree.push_node(70);
    tree.push_node(20);
    tree.push_node(40);
    tree.push_node(60);
    tree.push_node(80);

    std::cout << "Node 40 is " << (tree.find_node(40) ? "found" : "not found") << std::endl;
    std::cout << "Node 90 is " << (tree.find_node(90) ? "found" : "not found") << std::endl;

    tree.delete_node(30);
    tree.delete_node(70);

    std::cout << "Node 30 is " << (tree.find_node(30) ? "found" : "not found") << std::endl;
    std::cout << "Node 70 is " << (tree.find_node(70) ? "found" : "not found") << std::endl;

    return 0;
}
