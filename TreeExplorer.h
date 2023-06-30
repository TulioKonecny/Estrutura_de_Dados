#ifndef TREE_EXPLORER_H
#define TREE_EXPLORER_H

#include "BinarySearchTree.h"
#include <chrono>

class TreeExplorer {
public:
    TreeExplorer();

    // Executa o explorador de árvore
    void run();

private:
    BinarySearchTree tree;
    std::chrono::steady_clock::time_point startTime;

    // Imprime o menu de opções
    void printMenu() const;
    
    // Processa a opção selecionada pelo usuário
    void processOption(int intOption);
    
    // Constrói a árvore a partir de um arquivo
    void constructTreeFromFile();
    
    // Constrói a árvore a partir de entradas do usuário
    void constructTreeFromInput();
    
    // Imprime informações sobre a árvore
    void printTreeInfo() const;
    
    // Insere um elemento na árvore
    void insertElement();
    
    // Remove um elemento da árvore
    void removeElement();
    
    // Procura por um elemento na árvore
    void searchElement();
    
    // Verifica se a árvore é completa
    void checkCompleteTree() const;
    
    // Verifica se a árvore é perfeita
    void checkPerfectTree() const;
    
    // Imprime a árvore em ordem de busca em largura (BFS)
    void printBFS() const;
    
    // Converte uma árvore binária em uma lista e ordena usando Bubble Sort
    void convertAndSortWithBubbleSort();
    
    // Converte uma árvore binária em uma lista e ordena usando Selection Sort
    void convertAndSortWithSelectionSort();
    
    // Converte uma árvore binária em uma lista e ordena usando Insertion Sort
    void convertAndSortWithInsertionSort();
    
    // Converte uma árvore binária em uma lista e ordena usando Shell Sort
    void convertAndSortWithShellSort();
    
    // Ordena uma lista usando Bubble Sort
    void bubbleSort(std::vector<int>& vecList);
    
    // Ordena uma lista usando Selection Sort
    void selectionSort(std::vector<int>& vecList);
    
    // Ordena uma lista usando Insertion Sort
    void insertionSort(std::vector<int>& vecList);
    
    // Ordena uma lista usando Shell Sort
    void shellSort(std::vector<int>& vecList);
    
    // Imprime uma lista de inteiros
    void printList(const std::vector<int>& vecList) const;
    
    // Imprime o tempo decorrido desde o início da execução
    void printTimeElapsed();
};

#endif

