# CS 33211 Bankers Algorithm For Deadlock Avoidance

This project implements the Banker's Algorithm on a system of five processes with three resources. Each process P0-P4 starts with an allocated amount and a maximum amount for each resource. Each resource starts with an available amount that isn't yet being used by a process.

The main file, BankersAlgo.c, is commented in more depth about the implementation of this concept.

## To Compile and Run

Run these commands in your Linux terminal.

```bash
gcc BankersAlgo.c -o bankersAlgo
./bankersAlgo < inputSystem.txt
```

## Format for Inputs

The format for input files can be seen in format.txt, it goes as follows: in a .txt file, write a file in the format below.

```bash
Available Resources A B C

Allocation for P0 A B C
Allocation for P1 A B C
Allocation for P2 A B C
Allocation for P3 A B C
Allocation for P4 A B C

Max for P0 A B C
Max for P1 A B C
Max for P2 A B C
Max for P3 A B C
Max for P4 A B C
```

## Examples

As shown in the examples, if an input system is found to be in a safe state, this will be printed along with the safe sequence. If the input system is unsafe, this will be printed instead. First example, safeOne.txt is the example from the assignment page.

![image](https://github.com/user-attachments/assets/db275cea-2730-4ac9-93a5-b312a7c92f3c)

![image](https://github.com/user-attachments/assets/964cfd90-46ff-4409-9c7c-569e39433d02)

![image](https://github.com/user-attachments/assets/36308485-15d5-45a8-ab43-4ad449e13e02)

![image](https://github.com/user-attachments/assets/c6a2bc99-471b-47ab-93df-b4eeba20faed)








