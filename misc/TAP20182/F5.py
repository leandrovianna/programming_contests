# TAP 2018/2 - Sinuca - F5
print("S" if sum([0 for x in input()]) + sum([x for x in map(int, input().split()) if x % 2 == 1]) % 2 == 1 else "N")
