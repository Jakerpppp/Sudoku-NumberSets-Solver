#ifndef SetSolverSquareSet_h
#define SetSolverSquareSet_h

// Do not add any additional classes.
#include <vector>
#include <string>


class SetSolverSquareSet
{
public:

    std::vector<int>set;
    int square;



    SetSolverSquareSet()
    {
        for (int i = 1; i < 10; i++) {
            set.push_back(i);
        }
    }

    void setSquare(int squareIn)
    {
        square = squareIn;
    }

    int getLengthOfSet()
    {
        return set.size();
    }

    void removeNumberFromSet(int num) 
    {
        auto itr = set.begin();
        while (itr != set.end()) {
            int value = *itr;
            if (value == num) {
                set.erase(itr);
                break;
            }
            ++itr;
        }
    }

    void clearSet()
    {
        set.clear();
    }

    int getCandiate()
    {
        return set[0];
    }

    int getSquare() 
    {
        return square;
    }

    bool isEmpty()
    {
        return square == 99;
    }

    bool isBlack()
    {
        return square <= 0;
    }

    bool isBlackWithoutNumber()
    {
        return square == 0;
    }

    bool isBlackWithNumber()
    {
        return square < 0;
    }

    bool isFilled()
    {
        return square < 10 && square > 0;
    }

};

#endif /* SetSolverSquareSet_h */
