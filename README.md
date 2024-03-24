# Push_Swap : *Optimal and entirely functional*.

> This project is coded in C and aims to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

The Push_Swap project was a first step in implementing algorithms, and in this case **Sorting ALgorithms**. I had to research the classic sorting algorithms that already exist, and make one of my own so that it can be an even more optimized approach considering there are a set of rules the assignment asks to respect :
- There are 2 stacks, a and b.
- At the beginning :
  - The stack contains a random amound of numbers which cannot be duplicated.
  - The stack b is empty.
- The allowed operations are : **swap(stack)** meaning swap the first 2 elements, **push(stack)** meaning taking the first element and putting it at the top of the other stack, **rotate(stack)** meaning shifting up all elements of the stack by 1 and **reverse(rotate)** meaning shifting down all elements of the stack by 1.

The concept of the *analysis of algorithms* is the process of finding the **the computational complexity** of algorithms in computer science, and that was something I had to study and consider in implementing my sorting algorithm, whether is it by using **circular double linked lists** since they are easier to handle for the allowed operations, or **dimnishing the cost of execution** by making the steps of my algorithm less expensive and more optimized. The project asks for less than *5500* operations in sorting 500 random numbers for the maximal grade, which I have gotten.


