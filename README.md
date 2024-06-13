# Landmasses

Count the number of islands in a map of characters.

# Getting started

Make sure you have _libgtest-dev_ installed, clone the repo and then:

```bash
cd landmasses
mkdir out
cd out
cmake ..
cd ..
cmake --build out/  # out-of-source build
./out/unit_tests
./out/landmasses path/to/map.txt
```

# Approach

This is a connected components problem.
The connected components are determined using depth-first search with a 3x3 image kernel.
The runtime and memory usage are both in O(n).
After the connected components have been determined, they are counted.

# Program structure

- 1. Input
    - a. Parse and check command line argument
    - b. Open the file (if possible)
    - c. Read file and copy contents into a char `Image` (adding one layer of padding around the outside)
- 2. Connected components
    - a. Transform the image to integers, distinguishing only between water and non-water pixels
    - b. Iterate over all points and start a DFS, searching for unassigned points
    - c. Count the number of clusters in the resulting image
- 3. Output
    - a. Print the author name and number of landmasses to the console
    - Optional: print the images to the console

# Potential improvements

- Counting the number of cluster is redundant with the current implementation, since that information is available inside the clustering and could be output directly, this could be a small runtime improvement
- Loop unrolling of the kernel might help

The biggest performance gain would probably be seen by switching to another algorithm such as a:
- _linear_ single-pass clustering a disjoint set union datastructure, which would have fewer cache misses, excellent prefetching, and only needs a 2x2 kernel
- stixel clustering where the contents of each row and clustered into 1d intervals, and those intervals are in turn merged across rows using an interval intersection operation

Implementing either one from scratch, with good test coverage and without an external library, would take more than an afternoon.
