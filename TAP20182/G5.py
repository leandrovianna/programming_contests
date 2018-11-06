#!/usr/bin/python3

def main():
    s = input()

    for i in range(len(s)-1):
        if s[i] == s[i+1]:
            print('S')
            return

    for i in range(len(s)-2):
        if s[i] == s[i+2]:
            print('S')
            return

    print('N')


if __name__ == "__main__":
    main()
