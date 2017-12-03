n = int(input())
laps = {}
ans = '-1'
minprice = 999999999999
for i in range(n):
    inp = input()
    name = inp.split()[0]
    price = inp.split()[1]
    
    qtd7 = 0
    qtd4 = 0
    for ch in price:
        if ch != '7' and ch != '4':
            break
        if ch == '7':
            qtd7 += 1
        elif ch == '4':
            qtd4 += 1
    else:
        price = int(price)
        if qtd4 == qtd7 and minprice >= price:
            minprice = price
            ans = name
            
print(ans)
