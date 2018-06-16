n = int(input())
v = []

for i in range(n):
    v.append(raw_input())

maior = 0
ind = 0
j = 0
t = []
for i in v:
    x = i.rfind('/')
    if maior < x:
        maior = x
        ind = j
    
    t.append(len(i.split('/'))-1)
    j += 1

j = 0
sum = 0;
for x in t:
    if j != ind:
        sum += x *
