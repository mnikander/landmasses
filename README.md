# Landmasses

Count the number of islands in a map.
Each map is encoded as a text file of ASCII characters.
A `.` encodes water and other symbols encode forests, buildings, and other terrain types.

## Getting started

```bash
# out-of-source build
cd landmasses && mkdir out && cd out && cmake .. && cd ..
cmake --build out/
./out/landmasses resources/map1_6islands.txt
```

## Approach

This is a connected components problem.
The connected components are determined using depth-first search with a 3x3 image kernel.
The runtime and memory usage are both in O(n).

## Program structure

1. Input
    - Parse and check command line argument
    - Open the file (if possible)
    - Read file and copy contents into a 2d nested array which distinguishes only between water and non-water pixels
2. Connected components
    - Iterate over all points and start a DFS, clustering any unassigned neighboring points
    - Return the number of clusters found
3. Output
    - Print the author name and number of landmasses to the console
