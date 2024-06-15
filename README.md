# Landmasses

Count the number of islands in a map of characters.

# Getting started

```bash
# out-of-source build
cd landmasses && mkdir out && cd out && cmake .. && cd ..
cmake --build out/
./out/landmasses resources/map1_6islands.txt
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

# Known issues
- code was not split into header and source files, so linking will fail, if you try to incorporate it into more than one binary
