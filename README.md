sic
===

Single-Instruction Computer (SIC) Simulator

A SIC Factorial (Programming assignment due to [Dr. Mayer Goldberg](http://www.little-lisper.org))
------------------------------------------------------------------
In their classical tome Computer Organization & Design, the 
Hardware/Software Interface, authors Patterson and Hennessy introduce the 
Single-Instruction Computer (SIC, pronounced "sick"). The original 
description of the SIC micro-architecture has no registers, a single 
assembly instruction, an unspecified address size, no mechanism for IO, and 
no clear mechanism for termination. We need to decide arbitrarily on some 
of these issues:
- The address space is 32/64-bit wide. This is also the smallest addressible 
  chunk of memory.
- The single assembly language instruction is `SBN`, which stands for 
  *Subtract-and-Branch-if-Negative*. The format of the instruction is<br>
  <br>
      `SBN A, B, C`<br>
  <br>
  and its semantics is as follows:<br>
  <br>
      `if ((Memory[A] -= Memory[B]) < 0) goto C;`<br>
  <br>
  The encoding of this command takes up three 32/64-bit words, and consists of 
  the encoding of A, followed by the encoding of B, followed by the 
  encoding of C.
- The execution of a SIC program terminates at the instruction 
  `SBN 0, 0, 0`, which is encoded as three consecutive 32/64-bit zeros. This 
  instruction doesn't accomplish anything useful, so it s a good choice for 
  a termination criterion.
- Upon termination of the SIC program, the program dumps some output. The 
  output is determined by the following conventions:
  1. If `Memory[0]` is non-zero, then the output is a contiguous list of 
     unsigned integers. Otherwise it s a string of characters, each one of 
     which comes from a contiguous address.
  2. `Memory[1]` contains the number of characters or signed integers that 
     are to be printed.
  3. `Memory[2]` contains the location from which the list of integers or 
     characters should be printed.
     
A SIC program can, therefore, output any number of integers, or a string of 
any length.

*Programmer: I.A.Smith, February 2005*

