#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>

struct TreeNode {
    int intData;
    TreeNode* ptrLeft;
    TreeNode* ptrRight;

    explicit TreeNode(int intValue) : intData(intValue), ptrLeft(nullptr), ptrRight(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void clear(); 
    // Limpa a árvore, liberando a memória ocupada pelos nós

    void insert(int intValue);
    // Insere um novo elemento na árvore

    bool remove(int intValue);
    // Remove um elemento da árvore

    TreeNode* search(int intValue) const;
    // Busca um elemento na árvore e retorna o nó correspondente, se encontrado

    bool isComplete() const;
    // Verifica se a árvore é completa

    bool isPerfect() const;
    // Verifica se a árvore é perfeita

    void printBFS() const;
    // Imprime a árvore utilizando a estratégia de busca em largura (BFS)

    int getHeight() const;
    // Retorna a altura da árvore

    int getSize() const;
    // Retorna o número de elementos na árvore

    std::vector<int> toList() const;
    // Converte a árvore em uma lista

private:
    TreeNode* ptrRoot;

    void clear(TreeNode* ptrNode);
    // Limpa a árvore a partir de um nó específico, liberando a memória ocupada pelos nós

    void insert(TreeNode*& ptrNode, int intValue);
    // Insere um novo elemento na árvore a partir de um nó específico

    bool remove(TreeNode*& ptrNode, int intValue);
    // Remove um elemento da árvore a partir de um nó específico

    TreeNode* search(TreeNode* ptrNode, int intValue) const;
    // Busca um elemento na árvore a partir de um nó específico e retorna o nó correspondente, se encontrado

    bool isComplete(TreeNode* ptrNode, int intIndex, int intSize) const;
    // Verifica se a árvore a partir de um nó específico é completa

    int getHeight(TreeNode* ptrNode) const;
    // Retorna a altura da árvore a partir de um nó específico

    int getSize(TreeNode* ptrNode) const;
    // Retorna o número de elementos na árvore a partir de um nó específico

    void printBFS(TreeNode* ptrNode) const;
    // Imprime a árvore utilizando a estratégia de busca em largura (BFS) a partir de um nó específico

    void convertToList(TreeNode* ptrNode, std::vector<int>& vecList) const;
    // Converte a árvore em uma lista a partir de um nó específico
};

#endif

