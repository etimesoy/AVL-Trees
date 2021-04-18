#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <dirent.h>
#include <time.h>
#include <map>
#include <windows.h>
#include "AVLTree.hpp"
using namespace std;

unsigned int countOfFilesInDirectory(string pathToDir) {
    DIR *dir = opendir((pathToDir).c_str());
    struct dirent *entry;
    unsigned int countOfFiles = 0;
    while ( (entry = readdir(dir)) != NULL)
        if (string(entry->d_name) != "." && string(entry->d_name) != "..")
            ++countOfFiles;
    closedir(dir);
    return countOfFiles;
}

template<typename T>
double averageTimeComplexityForOperation(T (AVLTree::*pt2Func)(int), const int countOfNumbers, AVLTree* tree) {
    const int countOfTestsForOperation = 5000;
    int startTime = clock();
    for (int j = 0; j < countOfTestsForOperation; j++) {
        (tree->*pt2Func)(rand() % (2 * countOfNumbers) - countOfNumbers);
    }
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void updateMeasurements(map <unsigned int, double> &findMeasurements,
                       map <unsigned int, double> &insertMeasurements,
                       map <unsigned int, double> &removeMeasurements,
                       unsigned int countOfNumbers,
                       double averageFindTime, double averageInsertTime, double averageRemoveTime) {
    if (findMeasurements.find(countOfNumbers) == findMeasurements.end())
        findMeasurements[countOfNumbers] = averageFindTime;
    else
        findMeasurements[countOfNumbers] = (findMeasurements[countOfNumbers] + averageFindTime) / 2;
    if (insertMeasurements.find(countOfNumbers) == insertMeasurements.end())
        insertMeasurements[countOfNumbers] = averageInsertTime;
    else
        insertMeasurements[countOfNumbers] = (insertMeasurements[countOfNumbers] + averageInsertTime) / 2;
    if (removeMeasurements.find(countOfNumbers) == removeMeasurements.end())
        removeMeasurements[countOfNumbers] = averageRemoveTime;
    else
        removeMeasurements[countOfNumbers] = (removeMeasurements[countOfNumbers] + averageRemoveTime) / 2;
}

void printMeasurements(map <unsigned int, double> findMeasurements,
                       map <unsigned int, double> insertMeasurements,
                       map <unsigned int, double> removeMeasurements) {
    map <unsigned int, double>::iterator it = findMeasurements.begin();
    cout << "Find measurements:" << endl;
    while (it != findMeasurements.end()) {
        cout << it->first << ": " << it->second << endl;
        it++;
    }
    cout << endl;
    it = insertMeasurements.begin();
    cout << "Insert measurements:" << endl;
    while (it != insertMeasurements.end()) {
        cout << it->first << ": " << it->second << endl;
        it++;
    }
    cout << endl;
    it = removeMeasurements.begin();
    cout << "Remove measurements:" << endl;
    while (it != removeMeasurements.end()) {
        cout << it->first << ": " << it->second << endl;
        it++;
    }
    cout << endl;
}

pair<unsigned int, AVLTree*> readDataFromFile(ifstream& file) {
    int countOfNumbers, firstNumber, number;
    file >> countOfNumbers >> firstNumber;
    AVLTree* tree = new AVLTree(firstNumber);
    for (int j = 1; j < countOfNumbers; j++) {
        file >> number;
        tree->insert(number);
    }
    return pair<int, AVLTree*>(countOfNumbers, tree);
}

bool DirectoryExists(LPCTSTR szPath) {
    DWORD dwAttrib = GetFileAttributes(szPath);
    return (dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

void printMeasurementsIntoFiles(map <unsigned int, double> findMeasurements,
                                map <unsigned int, double> insertMeasurements,
                                map <unsigned int, double> removeMeasurements) {
    string outputDirName = "testsMeasurementsResults";
    if (!DirectoryExists("testsMeasurementsResults"))
        mkdir(outputDirName.c_str());
    map <unsigned int, double> :: iterator it;

    ofstream findFile(outputDirName + "/find.txt", ios_base::out);
    for (it = findMeasurements.begin(); it != findMeasurements.end(); it++) {
        findFile << it->first << ": " << it->second << endl;
    }
    findFile.close();

    ofstream insertFile(outputDirName + "/insert.txt", ios_base::out);
    for (it = insertMeasurements.begin(); it != insertMeasurements.end(); it++) {
        insertFile << it->first << ": " << it->second << endl;
    }
    insertFile.close();

    ofstream removeFile(outputDirName + "/remove.txt", ios_base::out);
    for (it = removeMeasurements.begin(); it != removeMeasurements.end(); it++) {
        removeFile << it->first << ": " << it->second << endl;
    }
    removeFile.close();
}

int main() {
    srand(time(NULL));
    unsigned int countOfTestFiles = countOfFilesInDirectory("../tests/");
    map <unsigned int, double> findMeasurements;  // ключи - размеры входных данных
    map <unsigned int, double> insertMeasurements;  // значения - время выполнения операций
    map <unsigned int, double> removeMeasurements;

    for (int i = 1; i <= countOfTestFiles; i++) {
        ifstream file("../tests/" + to_string(i) + ".txt");
        auto [countOfNumbers, tree] = readDataFromFile(file);

        double averageFindTime = averageTimeComplexityForOperation<bool>(&AVLTree::find, countOfNumbers, tree);
        double averageInsertTime = averageTimeComplexityForOperation<void>(&AVLTree::insert, countOfNumbers, tree);
        double averageRemoveTime = averageTimeComplexityForOperation<bool>(&AVLTree::remove, countOfNumbers, tree);
        updateMeasurements(findMeasurements, insertMeasurements, removeMeasurements, countOfNumbers,
                           averageFindTime, averageInsertTime, averageRemoveTime);

        delete tree;
        tree = nullptr;
        file.close();
    }

    printMeasurementsIntoFiles(findMeasurements, insertMeasurements, removeMeasurements);

    system("pause");
    return 0;
}
