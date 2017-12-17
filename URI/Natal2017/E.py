# URI - Indecisão das Renas - E
l = list(map(int, input().split()))

x = sum(l) % 9

names = {
    0: "Rudolph",
    1: "Dasher",
    2: "Dancer",
    3: "Prancer",
    4: "Vixen",
    5: "Comet",
    6: "Cupid",
    7: "Donner",
    8: "Blitzen",
}

print(names[x])
