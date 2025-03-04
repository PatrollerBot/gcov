#include <stdio.h>
#include <cmath>
#include <vector>
#include <iostream>
#include<time.h>

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
//scramble the Vector
void scrambleVector(std::vector<std::vector<int>>& refVec, int input){
    int scrambleMax, temp, pos1, pos2, pos3, pos4;
    scrambleMax = refVec.size() * refVec.size();
    srand(time(NULL));
    pos1 = rand()%refVec.size();
    srand(input);
    pos2 = rand()%refVec.size();
    srand(time(NULL));
    pos3 = rand()%refVec.size();
    srand(input+1);
    pos4 = rand()%refVec.size();
    
    for(int k = 0; k < scrambleMax; k++){
        //get 2 random spots in array
        srand(time(NULL));
        pos1 = rand()%refVec.size();
        srand(input);
        pos2 = rand()%refVec.size();
        srand(time(NULL));
        pos3 = rand()%refVec.size();
        srand(input+1);
        pos4 = rand()%refVec.size();
        
        //swap
        temp = refVec[pos1][pos2];
        refVec[pos1][pos2] = refVec[pos3][pos4];
        refVec[pos3][pos4] = temp;
    }
}
int main()
{
    int t = clock();
    std::vector<std::vector<int>> theVector(250, std::vector<int>(250)); //create vector named theVector
    int input;
    std::cout << "Please enter any integer \n";
    std::cin >> input;
    std::cout << "\n";
    
    fillVector(theVector, input);
    scrambleVector(theVector, input);
    printVector(theVector);
    std::cout << "\nRuntime: " << clock()-t << " milliseconds";
    

    return 0;
}