# Hash table optimization

## Introduction
This is a students project from [Ded's](ded32.ru) course of 2nd semester in MIPT.  

## Goals
The main tasks of the project:

- [x] Create a Hash table class
- [x] Write various hash functions to check their effectivity.
- [x] Use some different methods to optimize speed of work of hash table. 
- [x] Show the results to interested people.
- [x] Be impressive
- [ ] ~~Find a gf~~

## Dependencies

* My [double linked list](https://github.com/Mikipaw/MIPT-1sem/tree/master/MIPT_1sem/List) (upgraded) from 1st semester in MIPT
* The _simple_string_ class and some functions with it came from my [Onegin project](https://github.com/Mikipaw/MIPT-1sem/tree/master/MIPT_1sem/Onegin)
* 5 interesting hash functions were given by [Ded](ded32.ru)
* [Callgrind](https://valgrind.org/docs/manual/cl-manual.html) profiler
* [CLion perf](https://www.jetbrains.com/help/clion/cpu-profiler.html) profiler

## Little ~~ending~~ theoretical information.

In computing, a hash table, also known as hash map, is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

Ideally, the hash function will assign each key to a unique bucket, but most hash table designs employ an imperfect hash function, which might cause hash collisions where the hash function generates the same index for more than one key. Such collisions are typically accommodated in some way.

### Complexity

Let's see the complexity of standard C++ containers:

![alt text](pictures/img.png)

What can we say about hash table?

* Insert — O(1)
* Remove — O(1)
* Find — O(1)
* Memory — O(N)

But it really depends on hash-function. So this values are for good function with small number of collisions.
In bad cases we may get a O(N) complexity for any of method.

### Separate chaining

In separate chaining, the process involves building a linked list with key-value pair for each search array index. 
The collided items are chained together through a double linked list, which can be traversed to access the item with a unique search key. 
Collision resolution through chaining i.e. with a linked list is a common method of implementation.

In my program I used this method to solve the problem with collisions.

## Working process

### Creating a hash table class.

I created a hash table class.

### Effectivity of hash functions.

