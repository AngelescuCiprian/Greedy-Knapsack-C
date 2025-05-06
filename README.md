# Greedy-Knapsack-C
ATP
Implementare în C a problemei rucsacului (Knapsack) folosind algoritmi greedy. Sunt incluse patru metode de selecție: în ordine inițială, sortare după cost, valoare și raport valoare/cost.
# Greedy Knapsack - C Implementation

This project contains a C implementation of the **Knapsack Problem** using several **Greedy strategies**. The program reads item data from a file and applies multiple sorting strategies to determine the most valuable combination that fits into a backpack with limited capacity.

## Features

Implemented greedy strategies:
1. **Random order** – selects items as they are read.
2. **Sorted by cost (ascending)**
3. **Sorted by value (descending)**
4. **Sorted by value/cost ratio (descending)**

Each strategy uses the same selection logic: add items one by one as long as they fit into the backpack, without exceeding its capacity.

---

## Input File Format (`ghiozdan.txt`)

The input file must contain:

[number_of_items] [backpack_capacity]
[cost_1] [cost_2] ... [cost_n]
[value_1] [value_2] ... [value_n]

### Example:
5 10
2 3 4 5 9
3 4 8 8 10

