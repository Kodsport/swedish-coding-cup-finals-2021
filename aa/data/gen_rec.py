# generate something like:
# aaaz
# aaay
# aaax
# etc.
from util import *
import math
import string

m = int(cmdlinearg('m'))
n = int(cmdlinearg('n'))
internal = int(cmdlinearg('i', 0))
bad = int(cmdlinearg('bad', 0))
debug = int(cmdlinearg('debug', 0))

phi = (5**0.5 + 1) / 2
decrtail = 4

eachuse = math.log(n) / math.log(phi) + decrtail + 1 + internal
usepad = int(m / n - eachuse) - 2

nona = string.ascii_lowercase[2:]
pad = ''.join(random.choice(nona) for _ in range(usepad))
pad_start = pad[:len(pad)//2]
pad_end = pad[len(pad)//2:]

tailctr = 23**decrtail
def trail():
    global tailctr
    tailctr -= 1
    x = tailctr
    r = ""
    for i in range(decrtail):
        r = chr(97 + 2 + x % 23) + r # b..y
        x //= 23
    return pad_end + "b" + r

# not_after is either None, or a tuple (str (with biggest "aa" interpretation), in the middle of "å" for both strings)
def gen(n, internal, bad, not_after):
    if debug:
        print("rec", n, internal, bad, not_after)
    if internal > 0 and (n == 1 or random.random() < internal / (n / phi + internal)):
        prefix = random.choice(nona)
        if not_after is not None and not not_after[1] and (not not_after[0] or prefix >= not_after[0][0]):
            pass # bad idea
        else:
            return [prefix + x for x in gen(n, internal - 1, bad, None)]

    if n == 1:
        extra = []
        if not_after is not None and not_after[0] and not not_after[1] and not_after[0].startswith("a") and not not_after[0].startswith("aa"):
            # b is after not_after... oops!
            if debug:
                print("noo")
            extra = [not_after[0]]

        if debug:
            print("ret empty")
        return extra + [""] * (1 + bad)

    prop = random.uniform(1 / phi - 0.1, 1 / phi + 0.1)
    a = round(n * prop)
    a = min(n-1, max(a, 1))
    b = n - a
    bad1 = random.randint(0, bad)
    if not_after is None:
        part1 = ["a" + x for x in gen(a, internal, bad1, None)]
    else:
        val, midaa = not_after
        if midaa:
            part1 = ["a" + x for x in gen(a, internal, bad1, (val[1:], False))]
        else:
            if not val or val == "a":
                # oops, hard to repair this! add an extra entry (increases n)
                extra = [val + "z"]
                val += "z"
            else:
                extra = []
            if val.startswith("aa"):
                part1 = ["a" + x for x in gen(a, internal, bad1, (val[1:], True))]
            else:
                # must have padding, or else "aa" will result in something larger than not_after
                if val[0] == "a" and val[1] == "c":
                    part1 = ["ac" + x for x in gen(a, internal, bad1, (val[2:], False))]
                else:
                    if val[0] == "a":
                        pad = chr(random.randrange(ord('c'), ord(val[1])))
                    else:
                        pad = chr(random.randrange(ord('c'), ord('z') + 1))
                    part1 = ["a" + pad + x for x in gen(a, internal, bad1, None)]
            part1 = extra + part1

    if part1[-1].startswith("aa"):
        part2 = ["aa" + x for x in gen(b, internal, bad - bad1, (part1[-1][2:], False))]
    else:
        part2 = ["aa" + x for x in gen(b, internal, bad - bad1, None)]

    if debug:
        print(part1, part2)
    return part1 + part2

li = [pad_start + x for x in gen(n, internal, bad, None)]
print(len(li))
for w in li:
    print(w + trail())
