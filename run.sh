#!/bin/sh
g++ fcfs.cpp -o run
./run
python3 plot.py
g++ round.cpp -o run
./run
python3 plot.py
g++ banker_algo.cpp -o run
./run
