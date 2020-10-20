# 2-opt swap

The *2-opt* is an algorithm that locally reduces the length of a path between points. It helps in the resolution of the [Travelling Salesman Problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem).


This mini-project is made with the C++ library [SFML](https://www.sfml-dev.org/index-fr.php).


## Explanation of the problem

The traveling salesman problem consists of a set of *n* cities, where each city can reach all the other cities with a road. The goal for the traveling salesman is to visit all those cities once and get back to his depart point, using the shortest road as possible.



## Modelisation

The set of all cities is represented with a weighted complete graph, the weight of each edge corresponding to the distance between the two cities.

It is impossible to know efficiently the exact solution of such a problem, as soon as the number of cities is large (even 20 cities can take a relly long time), the complexity of the algorithm consisting of testing all the paths is in *O(n!)*. The algorithm of the *2-opt*, which runs in *O(n²)*, will only give a relatively small path, but we won't be any mean to know if the result will be the shortest...




## Compile the program

To build the executable file, just type ```make``` in a terminal in the current folder.


## Run the simulation

The generated executable is `2_opt`.

```
usage : 2_opt [options]
        -h              show help
        -n number       set the number of cities (default 10, de type int)
        -x|-y number    size of the window (default 800*600)
```



More about *2-opt* : [Wikipedia](https://en.wikipedia.org/wiki/2-opt).
