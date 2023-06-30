#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int intValue) : data(intValue), left(nullptr), right(nullptr) {}
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
    TreeNode* root;

    void clear(TreeNode* node);
    // Limpa a árvore a partir de um nó específico, liberando a memória ocupada pelos nós

    void insert(TreeNode*& node, int intValue);
    // Insere um novo elemento na árvore a partir de um nó específico

    bool remove(TreeNode*& node, int intValue);
    // Remove um elemento da árvore a partir de um nó específico

    TreeNode* search(TreeNode* node, int intValue) const;
    // Busca um elemento na árvore a partir de um nó específico e retorna o nó correspondente, se encontrado

    bool isComplete(TreeNode* node, int index, int size) const;
    // Verifica se a árvore a partir de um nó específico é completa

    int getHeight(TreeNode* node) const;
    // Retorna a altura da árvore a partir de um nó específico

    int getSize(TreeNode* node) const;
    // Retorna o número de elementos na árvore a partir de um nó específico

    void printBFS(TreeNode* node) const;
    // Imprime a árvore utilizando a estratégia de busca em largura (BFS) a partir de um nó específico

    void convertToList(TreeNode* node, std::vector<int>& list) const;
    // Converte a árvore em uma lista a partir de um nó específico
};

#endif

