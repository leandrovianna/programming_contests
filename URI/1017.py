def main():
    """TODO: Docstring for main.
    :returns: TODO
    """
    CONSUMO = 12
    tempo = int(input())
    veloc = int(input())
    dist = veloc * tempo
    ans = dist / CONSUMO
    print('{:.3f}'.format(ans))


if __name__ == "__main__":
    main()
