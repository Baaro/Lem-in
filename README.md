# Lem-in
The goal of the project is to carry ant colony through the shortest path across the farm.
Where the farm is just an undirected graph represented in terms of rooms(vertices) and links(edges).

The program receives the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```

Example of an input:

At the beginning of the game all colony is the room *##start*. And the goal is to bring the to the room *##end*.
```
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
```

Example of an output in the following format:

*Lx-y Lz-w Lr-o*

*x, z, r* represents the ants’ numbers (going from 1 to *number_of_ants*) and *y,
w, o* represents the rooms’ names.
```
L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
```

## Install & Build & Run
```
git clone https://github.com/vsokh/lem-in.git && \
cd lem-in && \
git submodule update --init --recursive && \
make
```

## Preview

## Coding style
C code has written following [Norminette](https://github.com/vsokh/assembler/blob/master/docs/norme.en.pdf)(42 code style specifications for almost all C-based projects) rules.

## Author
vsokolog
