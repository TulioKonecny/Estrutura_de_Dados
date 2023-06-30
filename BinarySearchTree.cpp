
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear();
}

void BinarySearchTree::clear() {
    clear(root);
    root = nullptr;
}

// Limpa a árvore, liberando a memória ocupada pelos nós
void BinarySearchTree::clear(TreeNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Insere um valor na árvore
void BinarySearchTree::insert(int intValue) {
    insert(root, intValue);
}

void BinarySearchTree::insert(TreeNode*& node, int intValue) {
    if (!node) {
        node = new TreeNode(intValue);
    } else if (intValue < node->data) {
        insert(node->left, intValue);
    } else if (intValue > node->data) {
        insert(node->right, intValue);
    }
}

// Remove um valor da árvore
bool BinarySearchTree::remove(int intValue) {
    return remove(root, intValue);
}

bool BinarySearchTree::remove(TreeNode*& node, int intValue) {
    if (!node) {
        return false;
    } else if (intValue < node->data) {
        return remove(node->left, intValue);
    } else if (intValue > node->data) {
        return remove(node->right, intValue);
    } else {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        } else if (!node->left) {
            TreeNode* temp = node;
            node = node->right;
            delete temp;
        } else if (!node->right) {
            TreeNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            TreeNode* minNode = node->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            node->data = minNode->data;
            return remove(node->right, minNode->data);
        }
        return true;
    }
}

// Procura um valor na árvore
TreeNode* BinarySearchTree::search(int intValue) const {
    return search(root, intValue);
}

TreeNode* BinarySearchTree::search(TreeNode* node, int intValue) const {
    if (!node || node->data == intValue) {
        return node;
    } else if (intValue < node->data) {
        return search(node->left, intValue);
    } else {
        return search(node->right, intValue);
    }
}

// Verifica se a árvore é completa
bool BinarySearchTree::isComplete() const {
    int size = getSize();
    return isComplete(root, 0, size);
}

bool BinarySearchTree::isComplete(TreeNode* node, int index, int size) const {
    if (!node) {
        return true;
    }
    if (index >= size) {
        return false;
    }
    return isComplete(node->left, 2 * index + 1, size) && isComplete(node->right, 2 * index + 2, size);
}

// Verifica se a árvore é perfeita
bool BinarySearchTree::isPerfect() const {
    int height = getHeight();
    int size = getSize();
    return size == (1 << height) - 1;
}

// Imprime a árvore em ordem de largura (BFS)
void BinarySearchTree::printBFS() const {
    printBFS(root);
}

void BinarySearchTree::printBFS(TreeNode* node) const {
    if (!node) {
        return;
    }

    std::vector<TreeNode*> queue;
    queue.push_back(node);

    while (!queue.empty()) {
        TreeNode* curr = queue.front();
        queue.erase(queue.begin());

        std::cout << curr->data << " ";

        if (curr->left) {
            queue.push_back(curr->left);
        }
        if (curr->right) {
            queue.push_back(curr->right);
        }
    }

    std::cout << std::endl;
}

// Obtém a altura da árvore
int BinarySearchTree::getHeight() const {
    return getHeight(root);
}

int BinarySearchTree::getHeight(TreeNode* node) const {
    if (!node) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

// Obtém o tamanho da árvore (número de nós)
int BinarySearchTree::getSize() const {
    return getSize(root);
}

int BinarySearchTree::getSize(TreeNode* node) const {
    if (!node) {
        return 0;
    }
    return getSize(node->left) + getSize(node->right) + 1;
}

// Converte a árvore em uma lista ordenada
std::vector<int> BinarySearchTree::toList() const {
    std::vector<int> list;
    convertToList(root, list);
    return list;
}

void BinarySearchTree::convertToList(TreeNode* node, std::vector<int>& list) const {
    if (!node) {
        return;
    }
    convertToList(node->left, list);
    list.push_back(node->data);
    convertToList(node->right, list);
}

