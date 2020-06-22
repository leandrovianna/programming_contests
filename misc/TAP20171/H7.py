expression = raw_input()

numbers = set(range(0, 10))

for i, c in enumerate(expression):
    x = ord(c) - ord('0')
    if x in numbers:
        numbers.remove(x)

index_eq = expression.find('=')
index_op = expression.find('*')
if index_op == -1:
    index_op = expression.find('+')

if index_op == -1:
    index_op = expression.find('-', 1)

res = -1

for x in numbers:
    s = expression.replace('?', str(x)) 
    n1 = int(s[:index_op])
    n2 = int(s[index_op+1:index_eq])
    n3 = int(s[index_eq+1:])

    c = s[index_op]
    if (c == '+' and (n1 + n2) == n3) \
        or (c == '-' and (n1 - n2) == n3) \
        or (c == '*' and (n1 * n2) == n3):
        res = x
        break

print res

