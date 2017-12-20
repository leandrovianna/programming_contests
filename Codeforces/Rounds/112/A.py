def lower(ch):
    return chr(ord(ch) | 32)

def main():
    s1 = ''.join(map(lower, input()))
    s2 = ''.join(map(lower, input()))

    for i in range(len(s1)):
        if s1[i] < s2[i]:
            print(-1)
            break
        elif s1[i] > s2[i]:
            print(1)
            break
    else:
        print(0)

if __name__ == "__main__":
    main()
