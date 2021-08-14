from util import *
import random
import string

n = int(cmdlinearg('n', 10**6 - random.randrange(50)))
q = int(cmdlinearg('q', 10**5 - random.randrange(50)))
k = int(cmdlinearg('k'))
a = cmdlinearg('a', "26")
b = cmdlinearg('b', "26")
uncor = int(cmdlinearg('uncor', 0))
attempts = int(cmdlinearg('attempts', 5))
reuse = float(cmdlinearg('reuse', 0.2))
graphs = cmdlinearg('graph', '')
bfroma = int(cmdlinearg('bfroma', 0))

alphabet = list(string.ascii_lowercase)
random.shuffle(alphabet)

def alpha(k):
    if k == 'inv':
        return [alphabet[i] * (100 // (i + 1)) for i in range(26)]
    if k == 'inv2':
        return [alphabet[i] * (100 // (i + 5)) for i in range(26)]
    if k == 'inv3':
        return [alphabet[i] * int(200 / (i**1.5 + 1)) for i in range(26)]
    if k == 'b':
        return [alphabet[1]]
    n = int(k)
    return alphabet[:n]

alphabetsa = [''.join(alpha(x)) for x in a.split(',')]
if uncor:
    random.shuffle(alphabet)
alphabetb = ''.join(alpha(b))

print(n, q, k)
s = []
for i in range(n):
    if random.random() < reuse and i >= 3:
        c = s[~random.randrange(3)]
    else:
        c = random.choice(alphabetsa[i % len(alphabetsa)])
    s.append(c)
s = ''.join(s)
print(s)

edges = None
if graphs:
    nodes = 0
    edges = []
    for i in range(0, len(graphs), 2):
        a = ord(graphs[i]) - 97
        b = ord(graphs[i+1]) - 97
        nodes = max(nodes, a + 1, b + 1)
        edges.append((a, b))

def gen():
    seen = set()
    if edges:
        vals = [random.choice(alphabetb) for i in range(nodes)]
        for (a, b) in edges:
            seen.add(vals[a] + vals[b])
    if bfroma:
        base = random.randrange(n - k - 1)
        for i in range(random.randint(2, k)):
            seen.add(s[base + i : base + i + 2])
    while len(seen) < k:
        seen.add(random.choice(alphabetb) + random.choice(alphabetb))
    return seen

uniqueq = set()
for _ in range(q):
    for _2 in range(attempts):
        seen = gen()
        sorteds = ''.join(sorted(seen))
        if sorteds not in uniqueq:
            uniqueq.add(sorteds)
            break
    s2 = list(seen)
    random.shuffle(s2)
    print(''.join(s2))
