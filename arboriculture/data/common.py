from collections import defaultdict
import random

def random_uniform(maxdeg=1000, B=500):
    x = []
    nonmaxdeg = [0]
    degs = defaultdict(int)
    for i in range(B):
        pari = random.randint(0, len(nonmaxdeg) - 1)
        par = nonmaxdeg[pari]
        x.append(par)
        ndeg = degs[par] + 1
        if ndeg == maxdeg:
            nonmaxdeg[pari] = nonmaxdeg[-1]
            nonmaxdeg.pop()
        else:
            degs[par] = ndeg
        nonmaxdeg.append(i + 1)
    return x

def complete(maxdeg=1000, B=500):
    x = []
    for i in range(B):
        x.append(i // maxdeg)
    return x
