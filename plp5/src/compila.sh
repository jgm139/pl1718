#!/bin/bash

flex plp5.l
bison -d plp5.y
g++ -w -o plp5 plp5.tab.c lex.yy.c
./plp5 tests/j09.fnt > j09.cod
g++ -w -o m2r m2r.c
./m2r j09.cod