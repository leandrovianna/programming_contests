def check(a, b, c, d):
    return (a * d == b * c)

a, b, c, d = raw_input().split();
a = int(a)
b = int(b)
c = int(c)
d = int(d)

if (check(a, b, c, d)
        or check(a, d, c, b)
        or check(c, b, a, d)
        or check(b, a, c, d)
        or check(a, b, d, c)):
    print "S"
else:
    print "N"
