#include <stdio.h>
#include <cmath>
#include <vector>
#include <iostream>

//fill Vector with values
void fillVector(std::vector<std::vector<int>>& refVec, int input){
    refVec[0][0] = input;
    refVec[1][0] = input + 1;
    
    for(int j = 1; j < refVec.size(); j++){
        for(int i = 0; i < 2; i++){
            refVec[i][j] = input + refVec[i][j-1];
        }
    }
    
    for(int j = 0; j < refVec.size(); j++){
        for(int i = 2; i < refVec.size(); i++){
            refVec[i][j] = refVec[i-2][j] + refVec[i-1][j];
        }
    }
}

//print out the Vector
void printVector(std::vector<std::vector<int>>& refVec){
    for(int j = 0; j < refVec.size(); j++){
        for(int i = 0; i < refVec.size(); i++){
            std::cout << refVec[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> theVector(500, std::vector<int>(500)); //create vector named theVector
    int input;
    std::cout << "Please enter any integer \n";
    std::cin >> input;
    std::cout << "\n";
    
    fillVector(theVector, input);
    printVector(theVector);
    

    return 0;
}