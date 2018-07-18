from random import randint
from random import seed
from time import time


seed(time())
with open('in', 'w') as f:
    n = 10**5
    f.write('{}\n'.format(n))
    for i in range(n):
        x = randint(0, 10**6)
        y = randint(0, 10**6)
        f.write('{} {}\n'.format(x, y))
