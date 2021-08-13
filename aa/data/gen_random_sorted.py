# uniformly random including Å's, then sorted, then Å's replaced by AA
# with parameters for char distribution and how much to unsort the sequence afterwards
from util import *
import random
import string

m = int(cmdlinearg('m'))
n = int(cmdlinearg('n'))
dens = float(cmdlinearg('dens'))
cdens = float(cmdlinearg('cdens', 0.2))
bad = int(cmdlinearg('bad', 0))

out = []
seen = set()
for size in random_nonempty_partition(m, n):
    s = ''.join(random.choice("az") if random.random() < dens else "c" if random.random() < cdens else "b" for _ in range(size))
    s2 = s.replace("z", "aa")
    if s2 not in seen:
        seen.add(s2)
        out.append(s)

out.sort()

n = len(out)
for i in range(bad):
    j = random.randrange(n - 1)
    out[j], out[j+1] = out[j+1], out[j]

print(n)
for s in out:
    print(s.replace("z", "aa"))
