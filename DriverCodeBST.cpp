#include "BinarySearchTree.h"
#include "TreeExplorer.h"


int main() {
    BinarySearchTree tree;

    // Insere elementos na árvore
     std::cout << "Inserindo: 50 30 20 40 70 60 80" << std::endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Realiza operações na árvore

    // Imprime a árvore em ordem de largura (BFS)
    std::cout << "Árvore em BFS:" << std::endl;
    tree.printBFS();

    // Altura da árvore
    std::cout << "Altura da árvore: " << tree.getHeight() << std::endl;

    // Quantidade de Elementos na árvore
    std::cout << "Número de elementos na árvore: " << tree.getSize() << std::endl;

    //Busca do endereço de memória de um elemento
    TreeNode* ptrNode1 = tree.search(40);
    if (ptrNode1) {
        std::cout << "Elemento 40 encontrado na árvore." << std::endl;
    } else {
        std::cout << "Elemento 40 não encontrado na árvore." << std::endl;
    }

    //Busca do endereço de memória de um elemento
    TreeNode* ptrNode2 = tree.search(100);
    if (ptrNode2) {
        std::cout << "Elemento 100 encontrado na árvore." << std::endl;
    } else {
        std::cout << "Elemento 100 não encontrado na árvore." << std::endl;
    }
    
    //Remoção de um elemento da árvore
    std::cout << "Remoção do 40." << std::endl;
    tree.remove(40);
    tree.printBFS();


    std::vector<int> vecList = tree.toList();
    std::cout << "Lista de elementos da árvore: ";
    for (int intElement : vecList) {
        std::cout << intElement << " ";
    }
    std::cout << std::endl;
    

    return 0;
}
