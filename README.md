#Brainfuck interpreter

##What it Bf?
Brainfuck is an esoteric programming language who consists of an 30kb array of data, a pointer for accesing the array and a 8 instruction set:
- ">" increments the pointer.
- "<" decrements the pointer.
- "+" increments the byte at the pointer.
- "-" decrements the byte at the pointer.
- "." outputs the byte at the pointer.
- "," inputs a byte on the byte at the pointer.
- "[" if the byte at the pointer is 0, jumps into the command after the closing "]".
- "]" if he byte at the pointer isn't 0, jumps into the command after the opening "['.

There is some examples at /demos/

##So what does this program do?
The program interprets code written in the bf format

##Installation:
-make bf-interp.c (or compile it direcly with gcc).

#Usage:
- ./bf-interp "file" (any exension as long it has text)


[Wikipedia bf entry](https://en.wikipedia.org/wiki/Brainfuck)
