# uniformly random
from util import *
import random
import string

m = int(cmdlinearg('m'))
n = int(cmdlinearg('n'))
alphabet = cmdlinearg('alphabet', string.ascii_lowercase)

out = []
seen = set()
for size in random_nonempty_partition(m, n):
    s = ''.join(random.choice(alphabet) for _ in range(size))
    if s not in seen:
        seen.add(s)
        out.append(s)

print(len(out))
for s in out:
    print(s)
