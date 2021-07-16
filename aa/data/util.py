import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

def random_partition(n, k):
    if k == 0:
        assert n == 0
        return []
    assert n >= 0
    assert k >= 1
    boundaries = sorted(random.sample(range(n + k - 1), k - 1))
    ret = []
    for a, b in zip([-1] + boundaries, boundaries + [n + k - 1]):
        ret.append(b - a - 1)
    assert sum(ret) == n
    return ret

def random_nonempty_partition(n, k):
    return [x + 1 for x in random_partition(n - k, k)]
