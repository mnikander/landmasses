# Design

## Goal
- count the number of islands on a map

## Input
- take a filepath as a command line argument
- read text file from disk
- file contains a 50x80 array of chars
- characters: `('.', '+', '*', '@', '^')` referring to `(water, land, tree, building, mountain)`, respectively
- for the purpose of this exercise we need to distinguish between water '.', and non-water
- if they occur, buildings in the water, such as an offshore wind turbine, will be counted as an island

Will there ever be invalid symbols, like `#`?
Do I need to check for those?
[ ] TODO: decide what to do here...

## Processing
- put the data into an array
- distinguish between water and non-water pixels (the type of 'non-water' is not relevant)
- find connected components in the image
- count how many disjoint landmasses there are

Several approaches are possible here:
- depth-first or breadth first search (easy to implement, a bit slow though)
- a disjoint set datastructure (very fast, will probably take me longer than the time-limit to implement)
- multi-pass clustering (simple, but probably also quite slow)
- stixel-clustering (probably quite fast, but also a bit more complicated than DFS / BFS)

I'll go for the simplest solution first, but with proper tests.
If there is time leftover I can try one of the faster approaches, or to speed the approach up at least a little bit.

For the neighborhood search I will use a 3x3 kernel, to find neighboring non-water pixels.
With DSU I could probably shrink this to 2x2, but not with DFS/BFS, because there is no telling in what order the image will be traversed.

## Output
- output printed to console
- my name
- number of islands

## Datastructure

I need an image-like datatype, chiefly with coordinate access. 
Padding could be nice to have for runtime performance, to avoid clamping in the indices of the for-loops.
Maybe I'll at least do this, from the start...

I will probably need a 2d coordinate datatype, perhaps with arithmetic operations on it.

Since I need to transform the data a bit, a flat tensor with a multi-dimensional access is probably the easiest way to go, and it's most familiar.

The data itself is very small, 50x80 is only 4000 elements.
As chars it would be just 4K, which would fit into L1 cache.
There could be a lot of clusters though... one in every 2x2 tile of the map.
That would be up to 1000 clusters just in the 50x80 image, so an image of uint8_t is insufficient.
I should take 16 bits at least, but I might as well just take int, the image is so small it won't make a diffence anyway.
I can use negative values to encode some extra information, like 'water'.

Array or Vector?
- I could use an array for now, the dimensions are fixed
- an array will go on the stack and I'm unlikely to exceed the 2MB stack size at this point
- could switch to vector in the future, or just put the array on the stack, if the maps get larger

I'll take the array, it will probably execute faster.
