#!/bin/bash

echo -n "3 4 + = "
./RPN "3 4 +"

echo -n "8 2 - = "
./RPN "8 2 -"

echo -n "6 7 * = "
./RPN "6 7 *"

echo -n "9 3 / = "
./RPN "9 3 /"

echo -n "3 4 + 2 * = "
./RPN "3 4 + 2 *"

echo -n "8 2 / 3 - = "
./RPN "8 2 / 3 -"

echo -n "5 1 2 + 4 * + 3 - = "
./RPN "5 1 2 + 4 * + 3 -"

echo -n "2 3 + 4 5 + * = "
./RPN "2 3 + 4 5 + *"

echo -n "0 5 + = "
./RPN "0 5 +"

echo -n "9 0 * = "
./RPN "9 0 *"

echo -n "7 2 + 3 * = "
./RPN "7 2 + 3 *"

echo -n "2 5 * 4 + = "
./RPN "2 5 * 4 +"

echo -n "1 2 + 3 4 + * = "
./RPN "1 2 + 3 4 + *"

echo -n "2 3 4 * + = "
./RPN "2 3 4 * +"

echo -n "9 8 + 7 6 + * = "
./RPN "9 8 + 7 6 + *"

echo -n "0 9 / = "
./RPN "0 9 /"

echo -n "5 6 9 + "
./RPN "5 6 9 +"

echo -n "Empty string ="
./RPN ""

echo -n "4 l 2 - + (wrong format) = "
./RPN "4 l 2 - +"