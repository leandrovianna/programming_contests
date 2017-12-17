# URI - Ajude Patatatitu - H
def is_upper(ch):
    return 'A' <= ch and ch <= 'Z'

def main():
    t = int(input())

    for ti in range(t):
        n = int(input())
        pgs = [input() for _ in range(n)]
        n = int(input())
        exp = [input()+'L' for _ in range(n)]

        for s in exp:
            ok = True
            for p in pgs:
                r = s.find(p)
                if r != -1 and r+len(p) < len(s) \
                        and is_upper(s[r + len(p)]):
                    ok = False
                    break

            if ok:
                print('Prossiga')
            else:
                # print(p, s)
                print('Abortar')

        if ti != t-1:
            print('')

if __name__ == "__main__":
    main()
