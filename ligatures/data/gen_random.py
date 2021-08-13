from util import *
import random
import string

n = int(cmdlinearg('n', 10**6 - random.randint(50)))
q = int(cmdlinearg('q', 10**5 - random.randint(50)))
k = int(cmdlinearg('k'))
a = cmdlinearg('a', 26)
b = cmdlinearg('b', 26)
uncor = int(cmdlinearg('uncor', 0))
attempts = cmdlinearg('attempts', 5)

alphabet = list(string.ascii_lowercase)
random.shuffle(alphabet)

def alpha(k):
    if k == 'inv':
        return [[alphabet[i]] * (100 // (i + 1)) for i in range(26)]
    if k == 'inv2':
        return [[alphabet[i]] * (100 // (i + 5)) for i in range(26)]
    if k == 'inv3':
        return [[alphabet[i]] * int(200 / (i**1.5 + 1)) for i in range(26)]
    if k == 'b':
        return [alphabet[1]]
    n = int(k)
    return alphabet[:n]

alphabetsa = [alpha(x) for x in a.split(',')]
if uncor:
    random.shuffle(alphabet)
alphabetb = alpha(b)

print(n, q, k)
print(''.join(random.choice(alphabetsa[i % len(alphabetsa)]) for i in range(n)))
uniqueq = set()
for _ in range(q):
    for _2 in range(attempts):
        seen = set()
        s = ''
        while len(seen) < k:
            pair = random.choice(alphabetb) + random.choice(alphabetb)
            if pair not in seen:
                seen.add(pair)
                s += pair
        sorteds = ''.join(sorted(seen))
        if sorteds not in uniqueq:
            uniqueq.add(sorteds)
            break
    print(s)
