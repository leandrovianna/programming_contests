# coding=utf-8


def main():
    """
    Main function
    """
    distance = int(input())
    spent_full = float(input())
    ans = distance / spent_full
    print('{:.3f} km/l'.format(ans))


if __name__ == "__main__":
    main()
