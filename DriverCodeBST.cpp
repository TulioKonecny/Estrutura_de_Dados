#include "BinarySearchTree.h"

int main() {
    BinarySearchTree tree;

    // Insere elementos na árvore
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Realiza operações na árvore
    tree.printBFS();
    std::cout << "Altura da árvore: " << tree.getHeight() << std::endl;
    std::cout << "Número de elementos na árvore: " << tree.getSize() << std::endl;

    TreeNode* node = tree.search(40);
    if (node) {
        std::cout << "Elemento 40 encontrado na árvore." << std::endl;
    } else {
        std::cout << "Elemento 40 não encontrado na árvore." << std::endl;
    }

    tree.remove(40);

    std::vector<int> list = tree.toList();
    std::cout << "Lista de elementos da árvore: ";
    for (int element : list) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    tree.clear();

    return 0;
}
