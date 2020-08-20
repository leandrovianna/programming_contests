# URI - Pegadinha de Evergreen - 2722
def main():
    n = int(input())
    for ni in range(n):
        s1 = input()
        s2 = input()

        out = ''
        i = 0
        while i < len(s1):
            out += s1[i]
            out += s1[i+1]
            out += s2[i]
            if i + 1 < len(s2):
                out += s2[i+1]
            i += 2
        print(out)

if __name__ == "__main__":
    main()
