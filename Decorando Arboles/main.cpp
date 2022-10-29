#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> changeFunction (std::vector<std::string> matrix, int size, bool change);


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<std::string> matrix;
    int matrixSize;
    int zeroBinary = 0;
    int oneBinary = 0;
    std::cout <<"Digite el numero de la matriz cuadrada" << std::endl;
    std::cin >> matrixSize;
    std::cin.ignore();
   // matrix.resize(matrixSize);
    for (int i = 0; i < matrixSize; i++){
        std::string value;
        std::cout << "Digite un numero binario" << std::endl;
        std::getline(std::cin,value);
        matrix.push_back(value);
        zeroBinary += (int)count(matrix[i].begin(),matrix[i].end(),'0');
        oneBinary += (int)count(matrix[i].begin(),matrix[i].end(),'1');
    }
    if (zeroBinary==oneBinary){
        if (matrix[0][0]=='0')
        {
            matrix = changeFunction(matrix,matrixSize,true);

        }
        else{
            matrix = changeFunction(matrix,matrixSize,false);

        }

    }
    else if(zeroBinary > oneBinary)
    {
        matrix = changeFunction(matrix,matrixSize,true);
    }
    else
    {
        matrix = changeFunction(matrix,matrixSize,false);

    }
    std::for_each(matrix.begin(),matrix.end(), [](std::string &m){
        std::cout << m <<std::endl;
    });



    return 0;
}


std::vector<std::string> changeFunction (std::vector<std::string> matrix, int size, bool change){
    if (change) {
        for (int i = 0; i < size; i++) {
            std::replace(matrix[i].begin(), matrix[i].end(), '0', '*');
            std::replace(matrix[i].begin(), matrix[i].end(), '1', 'o');

        }
    }
    else {
        for (int i = 0; i < size; i++){
            std::replace(matrix[i].begin(),matrix[i].end(),'0','o');
            std::replace(matrix[i].begin(),matrix[i].end(),'1','*');
        }
    }
    return matrix;
}