
#include "TreeExplorer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

TreeExplorer::TreeExplorer() {}

void TreeExplorer::run() {
    int intOption;
    do {
        printMenu();
        std::cin >> intOption;
        processOption(intOption);
    } while (intOption != 0);
}

// Imprime o menu de opções
void TreeExplorer::printMenu() const {
    std::cout << " " << std::endl;
    std::cout << "====== Explorador de Árvores ======" << std::endl;
    std::cout << "1. Construir árvore por arquivo de texto" << std::endl;
    std::cout << "2. Construir árvore por input" << std::endl;
    std::cout << "3. Informações da árvore" << std::endl;
    std::cout << "4. Inserção de um elemento" << std::endl;
    std::cout << "5. Remoção de um elemento" << std::endl;
    std::cout << "6. Busca do endereço de memória de um elemento" << std::endl;
    std::cout << "7. A árvore é completa?" << std::endl;
    std::cout << "8. A árvore é perfeita?" << std::endl;
    std::cout << "9.  Exibição da árvore utilizando BFS" << std::endl;
    std::cout << "10. Ordenar com Bubble Sort" << std::endl;
    std::cout << "11. Ordenar com Selection Sort" << std::endl;
    std::cout << "12. Ordenar com Insertion Sort" << std::endl;
    std::cout << "13. Ordenar com Shell Sort" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << " " << std::endl;

    std::cout << "Escolha sua opção: ";
 
}

void TreeExplorer::processOption(int intOption) {
    switch (intOption) {
        case 1:
            constructTreeFromFile();
            break;
        case 2:
            constructTreeFromInput();
            break;
        case 3:
            startTime = std::chrono::steady_clock::now();
            printTreeInfo();
            printTimeElapsed();
            break;
        case 4:
            startTime = std::chrono::steady_clock::now();
            insertElement();
            printTimeElapsed();
            break;
        case 5:
            startTime = std::chrono::steady_clock::now();
            removeElement();
            printTimeElapsed();
            break;
        case 6:
            startTime = std::chrono::steady_clock::now();
            searchElement();
            printTimeElapsed();
            break;
        case 7:
            startTime = std::chrono::steady_clock::now();
            checkCompleteTree();
            printTimeElapsed();
            break;
        case 8:
            startTime = std::chrono::steady_clock::now();
            checkPerfectTree();
            printTimeElapsed();
            break;
        case 9:
            startTime = std::chrono::steady_clock::now();
            printBFS();
            printTimeElapsed();
            break;
        case 10:
            startTime = std::chrono::steady_clock::now();
            convertAndSortWithBubbleSort();
            printTimeElapsed();
            break;
        case 11:
            startTime = std::chrono::steady_clock::now();
            convertAndSortWithSelectionSort();
            printTimeElapsed();
            break;
        case 12:
            startTime = std::chrono::steady_clock::now();
            convertAndSortWithInsertionSort();
            printTimeElapsed();
            break;
        case 13:
            startTime = std::chrono::steady_clock::now();
            convertAndSortWithShellSort();
            printTimeElapsed();
            break;
        case 0:
            std::cout << "Saindo... Até a proxima!" << std::endl;
            break;
        default:
            std::cout << "Opção Inválida. Por favor, tente novamente." << std::endl;
            break;
    }
}

 // Constrói a árvore a partir de um arquivo
void TreeExplorer::constructTreeFromFile() {
    std::string strFilename;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> strFilename;

    std::ifstream file(strFilename);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo: " << strFilename << std::endl;
        return;
    }

    int intValue;
    while (file >> intValue) {
        tree.insert(intValue);
    }

    std::cout << "Árvore construida por arquivo com sucesso." << std::endl;
}

// Constrói a árvore a partir de entradas do usuário
void TreeExplorer::constructTreeFromInput() {
    int intSize;
    std::cout << "Digite o número de elementos: ";
    std::cin >> intSize;

    std::cout << "Escreva os elementos: ";
    for (int i = 0; i < intSize; i++) {
        int intValue;
        std::cin >> intValue;
        tree.insert(intValue);
    }

    std::cout << "Árvore construida por input com sucesso." << std::endl;
}

// Imprime informações sobre a árvore
void TreeExplorer::printTreeInfo() const {
    std::cout << "Altura da árvore: " << tree.getHeight() << std::endl;
    std::cout << "Tamanho da árvore: " << tree.getSize() << std::endl;
}

// Insere um elemento na árvore
void TreeExplorer::insertElement() {
    int intValue;
    std::cout << "Digite o elemento para inserir: ";
    std::cin >> intValue;

    tree.insert(intValue);

    std::cout << "Elemento inserido com sucesso." << std::endl;
}

// Remove um elemento da árvore
void TreeExplorer::removeElement() {
    int intValue;
    std::cout << "Digite o elemento para remover: ";
    std::cin >> intValue;

    if (tree.remove(intValue)) {
        std::cout << "Elemento removido com sucesso." << std::endl;
    } else {
        std::cout << "Elemento não encontrado na árvore." << std::endl;
    }
}

// Busca um elemento na árvore
void TreeExplorer::searchElement() {
    int intValue;
    std::cout << "Digite o elemento que deseja buscar: ";
    std::cin >> intValue;

    TreeNode* ptrResult = tree.search(intValue);
    if (ptrResult) {
        std::cout << "Elemento encontrado no endereço de memória: " << ptrResult << std::endl;
    } else {
        std::cout << "Elemento não encontrado na árvore." << std::endl;
    }
}

// Verifica se a árvore é completa
void TreeExplorer::checkCompleteTree() const {
    if (tree.isComplete()) {
        std::cout << "A árvore é completa." << std::endl;
    } else {
        std::cout << "A árvore não é completa." << std::endl;
    }
}

// Verifica se a árvore é perfeita
void TreeExplorer::checkPerfectTree() const {
    if (tree.isPerfect()) {
        std::cout << "A árvore é perfeita." << std::endl;
    } else {
        std::cout << "A árvore não é perfeita." << std::endl;
    }
}

// Imprime a árvore utilizando BFS (Busca em Largura)
void TreeExplorer::printBFS() const {
    std::cout << "BFS: ";
    tree.printBFS();
}

// Converte a árvore em uma lista e ordena usando Bubble Sort
void TreeExplorer::convertAndSortWithBubbleSort() {
    std::vector<int> vecList = tree.toList();

    bubbleSort(vecList);

    std::cout << "Ordenando usando o Bubble Sort: ";
    printList(vecList);
}

// Converte a árvore em uma lista e ordena usando Selection Sort
void TreeExplorer::convertAndSortWithSelectionSort() {
    std::vector<int> vecList = tree.toList();

    selectionSort(vecList);

    std::cout << "Ordenando usando o Selection Sort: ";
    printList(vecList);
}

// Converte a árvore em uma lista e ordena usando Insertion Sort
void TreeExplorer::convertAndSortWithInsertionSort() {
    std::vector<int> vecList = tree.toList();

    insertionSort(vecList);

    std::cout << "Ordenando usando o Insertion Sort: ";
    printList(vecList);
}

// Converte a árvore em uma lista e ordena usando Shell Sort
void TreeExplorer::convertAndSortWithShellSort() {
    std::vector<int> vecList = tree.toList();

    shellSort(vecList);

    std::cout << "Ordenando usando o Shell Sort: ";
    printList(vecList);
}

// Implementa o algoritmo Bubble Sort para ordenação
void TreeExplorer::bubbleSort(std::vector<int>& vecList) {
    int intSize = vecList.size();
    for (int i = 0; i < intSize - 1; i++) {
        for (int j = 0; j < intSize - i - 1; j++) {
            if (vecList[j] > vecList[j + 1]) {
                std::swap(vecList[j], vecList[j + 1]);
            }
        }
    }
}

// Implementa o algoritmo Selection Sort para ordenação
void TreeExplorer::selectionSort(std::vector<int>& vecList) {
    int intSize = vecList.size();
    for (int i = 0; i < intSize - 1; i++) {
        int intMinIndex = i;
        for (int j = i + 1; j < intSize; j++) {
            if (vecList[j] < vecList[intMinIndex]) {
                intMinIndex = j;
            }
        }
        std::swap(vecList[i], vecList[intMinIndex]);
    }
}

// Implementa o algoritmo Insertion Sort para ordenação
void TreeExplorer::insertionSort(std::vector<int>& vecList) {
    int intSize = vecList.size();
    for (int i = 1; i < intSize; i++) {
        int intKey = vecList[i];
        int j = i - 1;
        while (j >= 0 && vecList[j] > intKey) {
            vecList[j + 1] = vecList[j];
            j--;
        }
        vecList[j + 1] = intKey;
    }
}

// Implementa o algoritmo Shell Sort para ordenação
void TreeExplorer::shellSort(std::vector<int>& vecList) {
    int intSize = vecList.size();
    for (int intGap = intSize / 2; intGap > 0; intGap /= 2) {
        for (int i = intGap; i < intSize; i++) {
            int intTemp = vecList[i];
            int j;
            for (j = i; j >= intGap && vecList[j - intGap] > intTemp; j -= intGap) {
                vecList[j] = vecList[j - intGap];
            }
            vecList[j] = intTemp;
        }
    }
}

// Imprime os elementos da lista
void TreeExplorer::printList(const std::vector<int>& vecList) const {
    for (int i : vecList) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Calcula e imprime o tempo decorrido desde o início da operação
void TreeExplorer::printTimeElapsed() {
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeElapsed = endTime - startTime;
    std::cout << "Tempo gasto: " << timeElapsed.count() << " segundos" << std::endl;
}
