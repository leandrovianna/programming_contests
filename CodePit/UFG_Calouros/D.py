#!/bin/python3
#TLE

def substr(s1, s2, i, j):
    x = 1
    while i+x < len(s1) and j+x < len(s2):
        if s1[i+x] == s2[j+x]:
            x += 1
        else:
            break
    return x

if __name__ == "__main__":
    while True:
        try:
            s1 = input()
            s2 = input()
        except EOFError:
            break

        qtd = 0
        for i in range(len(s1)):
            for j in range(len(s2)):
                if s1[i] == s2[j]:
                    qtd = max(qtd, substr(s1, s2, i, j))

        print (qtd)
