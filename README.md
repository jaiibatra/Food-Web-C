Author
Jai Batra

Project Title
Totalistic Cellular Automaton

Project Goal
Simulate and evolve a one-dimensional cellular automaton using dynamic rules, ternary states, and periodic boundary conditions. The program demonstrates concepts in rule-based state transitions and cumulative counting over multiple generations.

Implementation Instructions
Step 1: Define the Cellular Automaton Rules
Implement setValArray() to convert an integer rule (0–2186) into a 7-trit ternary array, validating user input and preparing the rule set.
Step 2: Initialize the Cellular World
Create a cell struct with properties for the current state, cumulative activity count, and local sums.
Use initializeWorld() to configure a periodic world of 65 cells, starting with a single active cell in the middle.
Step 3: Simulate Local Sums
Implement setSums() to calculate local sums of each cell based on the status of its neighbors (left, me, right) under periodic boundary conditions.
Step 4: Evolve the Automaton
Write evolveWorld() to update the state of each cell using the precomputed rule set, modify the cumulative activity count, and compute the total status sum for all cells.
Step 5: Handle User Inputs
Validate user-provided rule numbers, initial states, and the number of generations with appropriate input prompts and error handling.
Step 6: Simulate Generations
Iteratively evolve the world for the specified number of generations, printing the world’s state and the total status sum at each step.
Step 7: Display Final Results
After all generations, output a cumulative activity map showing each cell's total activity over all steps. Handle single- and double-digit counts with proper formatting.
Program Features
Rule Conversion: Converts user-defined rules into a ternary system for state evolution.
Periodic Boundaries: Supports cyclic behavior by wrapping edges.
Visualization: Prints states of cells using +, -, and whitespace to indicate states 2, 1, and 0, respectively.
Cumulative Count: Tracks and displays the cumulative active status of each cell over all generations.
