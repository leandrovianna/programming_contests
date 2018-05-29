"""
Hackerrank - World CodeSprint 13 - Find the Absent Students
"""


def main():
    n = int(input())
    a = map(int, input().strip().split())
    st = set(a)

    out = [x for x in range(1, n+1) if x not in st]
    print(' '.join(map(str, out)))


if __name__ == "__main__":
    main()
