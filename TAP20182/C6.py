def main():
    s = input()
    for vowel in 'aeiou':
        s = s.replace(vowel, 'ab'+vowel)
    print(s)


if __name__ == "__main__":
    main()
