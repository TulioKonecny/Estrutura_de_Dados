
#include "TreeExplorer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

TreeExplorer::TreeExplorer() {}

void TreeExplorer::run() {
    int option;
    do {
        printMenu();
        std::cin >> option;
        processOption(option);
    } while (option != 0);
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

void TreeExplorer::processOption(int option) {
    switch (option) {
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
    std::string filename;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo: " << filename << std::endl;
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
    int size;
    std::cout << "Digite o número de elementos: ";
    std::cin >> size;

    std::cout << "Escreva os elementos: ";
    for (int i = 0; i < size; i++) {
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

    TreeNode* result = tree.search(intValue);
    if (result) {
        std::cout << "Elemento encontrado no endereço de memória: " << result << std::endl;
    } else {
        std::cout << "Elemento não encontrado na árvore." << std::endl;
    }
}

// Verifica se a árvore é completa
void TreeExplorer::checkCompleteTree() const {
    if (tree.isComplete()) {
        std::cout << "A árvore é completa." << std::endl;
    } else {
        std::cout << "TA árvore não é completa." << std::endl;
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
    std::cout << "BFS transversal: ";
    tree.printBFS();
}

// Converte a árvore em uma lista e ordena usando Bubble Sort
void TreeExplorer::convertAndSortWithBubbleSort() {
    std::vector<int> list = tree.toList();

    bubbleSort(list);

    std::cout << "Ordenando usando o Bubble Sort: ";
    printList(list);
}

// Converte a árvore em uma lista e ordena usando Selection Sort
void TreeExplorer::convertAndSortWithSelectionSort() {
    std::vector<int> list = tree.toList();

    selectionSort(list);

    std::cout << "Ordenando usando o Selection Sort: ";
    printList(list);
}

// Converte a árvore em uma lista e ordena usando Insertion Sort
void TreeExplorer::convertAndSortWithInsertionSort() {
    std::vector<int> list = tree.toList();

    insertionSort(list);

    std::cout << "Ordenando usando o Insertion Sort: ";
    printList(list);
}

// Converte a árvore em uma lista e ordena usando Shell Sort
void TreeExplorer::convertAndSortWithShellSort() {
    std::vector<int> list = tree.toList();

    shellSort(list);

    std::cout << "Ordenando usando o Shell Sort: ";
    printList(list);
}

// Implementa o algoritmo Bubble Sort para ordenação
void TreeExplorer::bubbleSort(std::vector<int>& list) {
    int size = list.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

// Implementa o algoritmo Selection Sort para ordenação
void TreeExplorer::selectionSort(std::vector<int>& list) {
    int size = list.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(list[i], list[minIndex]);
    }
}

// Implementa o algoritmo Insertion Sort para ordenação
void TreeExplorer::insertionSort(std::vector<int>& list) {
    int size = list.size();
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

// Implementa o algoritmo Shell Sort para ordenação
void TreeExplorer::shellSort(std::vector<int>& list) {
    int size = list.size();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = list[i];
            int j;
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap) {
                list[j] = list[j - gap];
            }
            list[j] = temp;
        }
    }
}

// Imprime os elementos da lista
void TreeExplorer::printList(const std::vector<int>& list) const {
    for (int i : list) {
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

