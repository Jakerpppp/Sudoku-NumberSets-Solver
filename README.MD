# 9x9 Sudoku NumberSets Solver in C++

Welcome to the 9x9 Sudoku NumberSets Solver implemented in C++!
- Made in October-November 2023

## Overview

This C++ project provides a solver for the 9x9 NumberSets puzzle, a challenging variation of Sudoku. The solver is designed to efficiently find solutions for 9x9 grids with added complexity, making it nearly instantaneous for all examples including extra difficulty boards. Implmented using efficient Backtracking algorithms.

## Features

1. **Efficient Solver:**
   - The solver is optimized for quick solutions, making it suitable for a wide range of 9x9 NumberSets puzzles.

2. **Sudoku-Like Rules:**
   - The NumberSets puzzle follows Sudoku-like rules, where each row, column, and 3x3 subgrid must contain unique numbers from 1 to 9.

3. **Custom Representation:**
   - Black spaces are represented as `0`.
   - White spaces are represented as `*`.
   - Black spaces with numbers are represented as negative values.

## NumberSets Puzzle

Rows and columns are divided into compartments. A compartment is a series of uninterrupted white cells. Each compartment needs to be filled with an unordered but uninterrupted set of numbers (1-9). Compartments do not necessarily need to continue each other's numbers. Numbers within a compartment can appear in any order. No single number can repeat in any row or column (irrespective of compartments).

## Testing

To ensure the correctness and functionality of the solver, you can run the provided test suite in **NumberSetSolveTest.cpp**. This test suite is designed to cover various scenarios and puzzle configurations, validating the solver's capability to handle different inputs and produce correct solutions.

### Steps to Run the Test Suite:
1. **Compile and Run:**
   - Use your preferred C++ compiler to build the test executable.
   - Execute the test suite to run a series of tests on the NumberSets Solver.
   ```bash
   g++ -o NumberSetSolveTest NumberSetSolveTest.cpp
   ./NumberSetSolveTest
   ```

3. **Review Results:**
   - The test suite will output the results of each test case, indicating whether the solver passed or failed each scenario.

### Additional Testing:

Feel free to extend the test suite or create new test cases to cover specific puzzle configurations or edge cases. Ensuring a comprehensive set of tests will enhance the robustness of the solver and confirm its reliability under various conditions.
