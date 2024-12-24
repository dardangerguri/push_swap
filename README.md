# push_swap

![](push_swap.gif)

Algorithm project in which we must sort a given list of random numbers using a limited set of instructions, with the goal of achieving the lowest possible number of actions.

## About the project

This project is designed to test your skills in data manipulation and optimization. The challenge is to sort a list of numbers using the least number of operations possible. The operations are limited to a specific set of instructions, making this a test of both your algorithmic thinking and your ability to work within constraints.

## Instructions

The list of numbers to be sorted will be provided as command line arguments. The set of instructions that can be used to manipulate the list are as follows:

- `pa` : take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` : take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `sa` : swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` : swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : `sa` and `sb` at the same time.
- `ra` : Shift all elements of stack A up by 1. The first element becomes the last one.
- `rb` : Shift all elements of stack B up by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : Shift all elements of stack A down by 1. The last element becomes the first one.
- `rrb` : Shift all elements of stack B down by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Running the project

To run the project, first clone the repository and navigate into the project directory. Then, use the `make` command to compile the project.

Once the project is compiled, you can run it with the following command:

``` bash
./push_swap <numbers>
```
The <numbers> should be replaced with the list of numbers you want to sort. These can be positive or negative integers, and there should not be any duplicates. For example:

``` bash
./push_swap 2147483647 4000 3 -33 -2147483648
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

You can check the correctness of the program with the provided checker:
``` bash
ARG="5 3 -6 0 -1"; ./push_swap $ARG | ./checker $ARG
```

