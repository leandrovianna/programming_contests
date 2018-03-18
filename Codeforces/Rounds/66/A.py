# Codeforces - Petya and Java - 66A Div2
def main():
    x = int(input())
    if -128 <= x and x <= 127:
        print('byte')
    elif -32768 <= x and x <= 32767:
        print('short')
    elif -2147483648 <= x and x <= 2147483647:
        print('int')
    elif -9223372036854775808 <= x and x <= 9223372036854775807:
        print('long')
    else:
        print('BigInteger')


if __name__ == "__main__":
    main()
