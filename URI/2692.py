def main():
    n, m = map(int, input().split())
    trans = {}
    for i in range(n):
        a, b = input().split()
        trans[b] = a
        trans[a] = b

    for j in range(m):
        frase = input()
        novafrase = ''
        for c in frase:
            if c in trans:
                novafrase += trans[c]
            else:
                novafrase += c
        print(novafrase)

if __name__ == "__main__":
    main()
