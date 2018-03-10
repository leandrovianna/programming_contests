#!/bin/python3
# HackerRank - Revised Russian Roulette - revised-russian-roulette

import sys

def revisedRussianRoulette(doors):
    qtd1 = 0
    qtd2 = 0

    for door in doors:
        if door == 1:
            qtd2 += 1

    for i, door in enumerate(doors):
        door = doors[i]
        if door == 1:
            qtd1 += 1
            doors[i] = 0
            if i < len(doors)-1:
                doors[i+1] = 0
    return [qtd1, qtd2]


if __name__ == "__main__":
    n = int(input().strip())
    doors = list(map(int, input().strip().split(' ')))
    result = revisedRussianRoulette(doors)
    print(" ".join(map(str, result)))
