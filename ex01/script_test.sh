#!/bin/bash

echo -n "3 4 + = "
./rpn "3 4 +"

echo -n "8 2 - = "
./rpn "8 2 -"

echo -n "6 7 * = "
./rpn "6 7 *"

echo -n "9 3 / = "
./rpn "9 3 /"

echo -n "3 4 + 2 * = "
./rpn "3 4 + 2 *"

echo -n "8 2 / 3 - = "
./rpn "8 2 / 3 -"

echo -n "5 1 2 + 4 * + 3 - = "
./rpn "5 1 2 + 4 * + 3 -"

echo -n "2 3 + 4 5 + * = "
./rpn "2 3 + 4 5 + *"

echo -n "0 5 + = "
./rpn "0 5 +"

echo -n "9 0 * = "
./rpn "9 0 *"

echo -n "7 2 + 3 * = "
./rpn "7 2 + 3 *"

echo -n "2 5 * 4 + = "
./rpn "2 5 * 4 +"

echo -n "1 2 + 3 4 + * = "
./rpn "1 2 + 3 4 + *"

echo -n "2 3 4 * + = "
./rpn "2 3 4 * +"

echo -n "9 8 + 7 6 + * = "
./rpn "9 8 + 7 6 + *"

echo -n "0 9 / = "
./rpn "0 9 /"

echo -n "5 6 9 + "
./rpn "5 6 9 +"

echo -n "Empty string ="
./rpn ""

echo -n "4 l 2 - + (wrong format) = "
./rpn "4 l 2 - +"