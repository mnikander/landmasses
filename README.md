# Landmasses

Count the number of islands in a map of characters.

# Getting started

```bash
cd landmasses
mkdir out
cd out
cmake ..
cd ..
cmake --build out/  # out-of-source build
./out/landmasses path/to/map.txt
```

# Approach

This is a connected components problem.
The connected components are determined using depth-first search with a 3x3 image kernel.
The runtime and memory usage are both in O(n).

# Program structure

- 1. Input
    - a. Parse and check command line argument
    - b. Open the file (if possible)
    - c. Read file and copy contents into a 2d nested array which distinguishes only between water and non-water pixels
- 2. Connected components
    - a. Iterate over all points and start a DFS, clustering any unassigned neighboring points
    - c. Return the number of clusters found
- 3. Output
    - a. Print the author name and number of landmasses to the console
