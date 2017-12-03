def main():
    """
    :returns: TODO

    """
    n = int(input())
    
    h = n // (60 * 60)
    n = n % (60 * 60)

    m = n // 60
    n = n % 60

    s = n

    print('{}:{}:{}'.format(h, m, s))


if __name__ == "__main__":
    main()
