def solve(linha, perolas):
    if perolas == 0:
        return True
    else:
        return linha % perolas == 0


def main():
    s = input()
    x, y = 0, 0
    for c in s:
        if c == '-':
            x += 1
        else:
            y += 1

    if solve(x, y):
        print('YES')
    else:
        print('NO')


if __name__ == "__main__":
    main()
