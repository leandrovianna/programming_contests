"""
 CodeJam 2018 Practice - Number Guessing
"""


def main():
    t = int(input())

    for _ in range(t):
        lo, hi = map(int, input().split())
        n = int(input())

        lo += 1

        for __ in range(n):
            mid = (lo + hi) // 2
            print(mid, flush=True)

            response = input().strip()

            if response == 'CORRECT':
                break
            elif response == 'TOO_SMALL':
                lo = mid+1
            elif response == 'TOO_BIG':
                hi = mid-1
            elif response == 'WRONG_ANSWER':
                return
            else:
                print('SOMETHING WRONG')
                exit(1)
        else:
            response = input().strip()
            if response == 'WRONG_ANSWER':
                return


if __name__ == "__main__":
    main()
