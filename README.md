# CS341_Programs
Programs that I wrote for my college course about computational theory.

p1_19s_ar793.cpp (Project 1): 
A program that functions as a DFA that recognizes the language L over a given alphabet. To define L, first let P = {a, b, c, ..., z} as the set of lowercase Roman letters. Also, let D = {.} and 0 = {@}. Finally, let S = P U D U 0. In other words, S is the set of all lowercase Roman letters, the period, and the @ symbol.
Now, let the following strings be defined as:
  S1 = PP*, which consists of strings over P of length one or more
  S2 = DPP*,  which consists of strings starting with a period & followed by one or more symbols from P
  S3 = {.com}
Then, the following sets of strings are also defined as:
  L1 = (S1)(0)(S1)(S3)
  L2 = (S1)(S2*)(0)(S1)(S2*)(S3)
  L = L1 U L2
The program utilizes a large switch statement to process input and continues to ask the user for more input until they decide to end the program by inputting 'n'.
