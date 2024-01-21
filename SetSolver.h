#ifndef SetSolver_h
#define SetSolver_h

#include <string>
#include <iostream>
#include <memory>
#include "SetSolverSquareSet.h"

using std::vector;
using std::string;
//do not add additional libraries

//Final Test

class SetSolver
{
private:
    int boardSize = 9;
    vector<vector<SetSolverSquareSet>>board;
    
public:
SetSolver()
{
    
}

void PopulateBoard(vector<string>skeletonBoard)
{
    vector<SetSolverSquareSet> currentLine;
    int nextNumberNegative = 1;
    for (string str : skeletonBoard) {
        currentLine.clear();
        for (char letter: str) {

            SetSolverSquareSet square;
            if (letter == '0') {
                square.setSquare(0);
                currentLine.push_back(square);
            }

            else if (letter == '*') {
                square.setSquare(99);
                currentLine.push_back(square);
            }

            else if (letter == '-') {
                nextNumberNegative = -1;
            }

            else {
                square.setSquare(nextNumberNegative * (letter - '0'));
                currentLine.push_back(square);
                nextNumberNegative = 1;
            }

        }
        board.push_back(currentLine);
    }
}
    
int ReturnValue(size_t row, size_t col)
{
    return board[row][col].getSquare();
}

void reduceCandiateSet()
{
    //First remove all ones in same row and column it cant be in its set
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0 ; j < boardSize; j++) {
            if (!board[i][j].isEmpty() && !board[i][j].isBlackWithoutNumber()) {
                int num = board[i][j].getSquare();
                if (num < 0) {
                    num = num * -1;
                }
                for (int q = 0; q < boardSize; q++) {
                    board[i][q].removeNumberFromSet(num);
                    board[q][j].removeNumberFromSet(num);
                }
            }
        }
    }
}

bool isValid(int row, int col, int num) 
{
    // Check if the number is not in current row, current column

    for (int i = 0; i < boardSize; ++i) {

        if (board[row][i].getSquare() == num || board[i][col].getSquare() == num || board[row][i].getSquare() == num * -1 || board[i][col].getSquare() == num * -1) {
            return false;
        }
    }

    int right = col + 1;
    int left = col - 1;
    bool leftDone = false;
    bool rightDone = false;
    int maxCompartmentRow = 0;
    int minCompartmentRow = 10;
    int countSizeOfCompartmentRow = 1;
    while (!leftDone || !rightDone) {

        if (!leftDone && (left == -1 || board[row][left].isBlack())) {
            leftDone = true;
        }

        if (!rightDone && (right == 9 || board[row][right].isBlack())) {
             rightDone = true;
        }

        if (!leftDone && board[row][left].isEmpty() ) {
            countSizeOfCompartmentRow++;
        }

        if (!rightDone && board[row][right].isEmpty() ) {
            countSizeOfCompartmentRow++;
        }

        if (!leftDone && board[row][left].isFilled()) {
            countSizeOfCompartmentRow++;
            if (board[row][left].getSquare() > maxCompartmentRow) {
                maxCompartmentRow = board[row][left].getSquare();
            }
            if (board[row][left].getSquare() < minCompartmentRow) {
                minCompartmentRow = board[row][left].getSquare();
            }
        }

        if (!rightDone && board[row][right].isFilled()) {
            countSizeOfCompartmentRow++;
            if (board[row][right].getSquare() > maxCompartmentRow) {
                maxCompartmentRow = board[row][right].getSquare();
            }
            if (board[row][right].getSquare() < minCompartmentRow) {
                minCompartmentRow = board[row][right].getSquare();
            }
        }

        left--;
        right++;
    }

    if (minCompartmentRow != 10 && maxCompartmentRow != 0) {
        int upper_bound = minCompartmentRow + (countSizeOfCompartmentRow - 1);
        int lower_bound = maxCompartmentRow - (countSizeOfCompartmentRow - 1);
        if (num > upper_bound || num < lower_bound) {
            return false;
        }
    }

    int down = row + 1;
    int up = row - 1;
    bool upDone = false;
    bool downDone = false;
    int maxCompartmentCol = 0;
    int minCompartmentCol = 10;
    int countSizeOfCompartmentCol = 1;
    while (!upDone || !downDone) {

        if (!upDone && (up == -1 || board[up][col].isBlack())) {
            upDone = true;
        }
        if (!downDone && (down == 9 || board[down][col].isBlack())) {
            downDone = true;
        }
        if (!upDone && board[up][col].isEmpty() ) {
            countSizeOfCompartmentCol++;
        }

        if (!downDone && board[down][col].isEmpty() ) {
            countSizeOfCompartmentCol++;
        }

        if (!upDone && board[up][col].isFilled()) {
            countSizeOfCompartmentCol++;
            if (board[up][col].getSquare() > maxCompartmentCol) {
                maxCompartmentCol = board[up][col].getSquare();
            }
            if (board[up][col].getSquare() < minCompartmentCol) {
                minCompartmentCol = board[up][col].getSquare();
            }
        }

        if (!downDone && board[down][col].isFilled()) {
            countSizeOfCompartmentCol++;
            if (board[down][col].getSquare() > maxCompartmentCol) {
                maxCompartmentCol = board[down][col].getSquare();
            }
            if (board[down][col].getSquare() < minCompartmentCol) {
                minCompartmentCol = board[down][col].getSquare();
            }
        }

        up--;
        down++;
    }

    if (minCompartmentCol != 10 && maxCompartmentCol != 0) {
        int upper_bound = minCompartmentCol + (countSizeOfCompartmentCol - 1);
        int lower_bound = maxCompartmentCol - (countSizeOfCompartmentCol - 1);
        if (num > upper_bound || num < lower_bound) {
            return false;
        }
    }

    return true;
}

//Recursive Algorithm
bool solveSudoku() 
{
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            if (board[row][col].isEmpty()) {
                for (int num : board[row][col].set) {
                    if (isValid(row, col, num)) {
                        board[row][col].setSquare(num);
                        if (solveSudoku()) {
                            return true;
                        }
                        board[row][col].setSquare(99); // If placing the number doesn't lead to a solution, backtrack
                    }
                }
                return false; // If no number can be placed, backtrack
            }
        }
    }
    return true;

}


void Solve()
{  
    solveSudoku();
}


//Don't edit below this line    
    
};
#endif /* SetSolver_h */
