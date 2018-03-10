#!/bin/python3
# HackerRank - Ways to give a check - ways-to-give-a-check

import sys

KMOVES = [(2, 1), (2, -1), (1, 2), (-1, 2),
          (-2, 1), (-2, -1), (1, -2), (-1, -2)]

def onrange(i, j):
    return 0 <= i and i < 8 and 0 <= j and j < 8


def is_check(board, i, j):
    # print(i, j)
    # print(board)

    for mi, mj in KMOVES:
        mi += i
        mj += j
        if onrange(mi, mj) and board[mi][mj] == 'N':
            return True


    for x, y in [(1, 1), (-1, 1), (1, -1), (-1, -1)]:
        for d in range(1, 8):
            mi = i + d * x
            mj = j + d * y

            if onrange(mi, mj):
                if board[mi][mj] == 'Q' or board[mi][mj] == 'B' or \
                   (d == 1 and board[mi][mj] == 'K'):
                    return True

                if board[mi][mj] != '#':
                    break

    for x, y in [(0, 1), (0, 1), (0, -1), (-1, 0)]:
        for d in range(1, 8):
            mi = i + d * x
            mj = j + d * y

            if onrange(mi, mj):
                if board[mi][mj] == 'R' or board[mi][mj] == 'Q' or \
                   (d == 1 and board[mi][mj] == 'K'):
                    return True

                if board[mi][mj] != '#':
                    break

    return False


def waysToGiveACheck(board, i, j):
    answer = 0

    for col in range(8):
        if board[1][col] == 'P' and board[0][col] == '#':

            board[1][col] = '#'
            for piece in ['Q', 'R', 'B', 'N']:
                board[0][col] = piece

                if is_check(board, i, j):
                    answer += 1

            board[1][col] = 'P'
            board[0][col] = '#'

    return answer


def main():
    t = int(input().strip())
    for a0 in range(t):
        board = []

        for i in range(8):
            line = []
            for c in input().strip():
                line.append(c)
            board.append(line)

        for i in range(8):
            for j in range(8):
                if board[i][j] == 'k':
                    print(waysToGiveACheck(board, i, j))
                    break


if __name__ == "__main__":
    main()
