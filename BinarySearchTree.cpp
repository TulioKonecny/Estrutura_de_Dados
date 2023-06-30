
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : ptrRoot(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear();
}

//Limpa
void BinarySearchTree::clear() {
    clear(ptrRoot);
    ptrRoot = nullptr;
}

// Limpa a árvore, liberando a memória ocupada pelos nós
void BinarySearchTree::clear(TreeNode* ptrNode) {
    if (ptrNode) {
        clear(ptrNode->ptrLeft);
        clear(ptrNode->ptrRight);
        delete ptrNode;
    }
}

// Chama o inseridor um valor na árvore
void BinarySearchTree::insert(int intValue) {
    insert(ptrRoot, intValue);
}

// Insere um valor na árvore
void BinarySearchTree::insert(TreeNode*& ptrNode, int intValue) {
    if (!ptrNode) {
        ptrNode = new TreeNode(intValue);
    } else if (intValue < ptrNode->intData) {
        insert(ptrNode->ptrLeft, intValue);
    } else if (intValue > ptrNode->intData) {
        insert(ptrNode->ptrRight, intValue);
    }
}

// Chama o removedor de um valor
bool BinarySearchTree::remove(int intValue) {
    return remove(ptrRoot, intValue);
}

// Remove um valor da árvore
bool BinarySearchTree::remove(TreeNode*& ptrNode, int intValue) {
    if (!ptrNode) {
        return false;
    } else if (intValue < ptrNode->intData) {
        return remove(ptrNode->ptrLeft, intValue);
    } else if (intValue > ptrNode->intData) {
        return remove(ptrNode->ptrRight, intValue);
    } else {
        if (!ptrNode->ptrLeft && !ptrNode->ptrRight) {
            delete ptrNode;
            ptrNode = nullptr;
        } else if (!ptrNode->ptrLeft) {
            TreeNode* ptrTemp = ptrNode;
            ptrNode = ptrNode->ptrRight;
            delete ptrTemp;
        } else if (!ptrNode->ptrRight) {
            TreeNode* ptrTemp = ptrNode;
            ptrNode = ptrNode->ptrLeft;
            delete ptrTemp;
        } else {
            TreeNode* ptrMinNode = ptrNode->ptrRight;
            while (ptrMinNode->ptrLeft) {
                ptrMinNode = ptrMinNode->ptrLeft;
            }
            ptrNode->intData = ptrMinNode->intData;
            return remove(ptrNode->ptrRight, ptrMinNode->intData);
        }
        return true;
    }
}

// Chama o procurador um valor na árvore
TreeNode* BinarySearchTree::search(int intValue) const {
    return search(ptrRoot, intValue);
}

// Procura um valor na árvore
TreeNode* BinarySearchTree::search(TreeNode* ptrNode, int intValue) const {
    if (!ptrNode || ptrNode->intData == intValue) {
        return ptrNode;
    } else if (intValue < ptrNode->intData) {
        return search(ptrNode->ptrLeft, intValue);
    } else {
        return search(ptrNode->ptrRight, intValue);
    }
}

// Chama o Verificador se a árvore é completa
bool BinarySearchTree::isComplete() const {
    int intSize = getSize();
    return isComplete(ptrRoot, 0, intSize);
}

// Verifica se a árvore é completa
bool BinarySearchTree::isComplete(TreeNode* ptrNode, int intIndex, int intSize) const {
    if (!ptrNode) {
        return true;
    }
    if (intIndex >= intSize) {
        return false;
    }
    return isComplete(ptrNode->ptrLeft, 2 * intIndex + 1, intSize) && isComplete(ptrNode->ptrRight, 2 * intIndex + 2, intSize);
}

// Verifica se a árvore é perfeita
bool BinarySearchTree::isPerfect() const {
    int intHeight = getHeight();
    int intIndex = getSize();
    return intIndex == (1 << intHeight) - 1;
}

// Chama o print da árvore em ordem de largura (BFS)
void BinarySearchTree::printBFS() const {
    printBFS(ptrRoot);
}

// Imprime a árvore em ordem de largura (BFS)
void BinarySearchTree::printBFS(TreeNode* ptrNode) const {
    if (!ptrNode) {
        return;
    }

    std::vector<TreeNode*> queue;
    queue.push_back(ptrNode);

    while (!queue.empty()) {
        TreeNode* curr = queue.front();
        queue.erase(queue.begin());

        std::cout << curr->intData << " ";

        if (curr->ptrLeft) {
            queue.push_back(curr->ptrLeft);
        }
        if (curr->ptrRight) {
            queue.push_back(curr->ptrRight);
        }
    }

    std::cout << std::endl;
}

//Chama o obtedor da altura
int BinarySearchTree::getHeight() const {
    return getHeight(ptrRoot);
}
// Obtém a altura da árvore
int BinarySearchTree::getHeight(TreeNode* ptrNode) const {
    if (!ptrNode) {
        return 0;
    }
    int ptrLeftHeight = getHeight(ptrNode->ptrLeft);
    int ptrRightHeight = getHeight(ptrNode->ptrRight);
    return std::max(ptrLeftHeight, ptrRightHeight) + 1;
}

// Chama o obtedor do tamanho
int BinarySearchTree::getSize() const {
    return getSize(ptrRoot);
}
// Obtém o tamanho da árvore (número de nós)
int BinarySearchTree::getSize(TreeNode* ptrNode) const {
    if (!ptrNode) {
        return 0;
    }
    return getSize(ptrNode->ptrLeft) + getSize(ptrNode->ptrRight) + 1;
}

//Chama o conversor da árvore em uma lista ordenada
std::vector<int> BinarySearchTree::toList() const {
    std::vector<int> vecList;
    convertToList(ptrRoot, vecList);
    return vecList;
}

// Converte a árvore em uma lista ordenada
void BinarySearchTree::convertToList(TreeNode* ptrNode, std::vector<int>& vecList) const {
    if (!ptrNode) {
        return;
    }
    convertToList(ptrNode->ptrLeft, vecList);
    vecList.push_back(ptrNode->intData);
    convertToList(ptrNode->ptrRight, vecList);
}


