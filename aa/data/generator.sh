#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution sl.cpp opt

# TODO generators:
# - fibonacci-based aaaz, aaay, aaax, ...
# - pad those at start, end with identical strings

compile gen_random.py pypy
compile gen_random_sorted.py pypy

samplegroup
limits n=100 m=1000
sample 1
sample 2
sample 3
sample 4
sample 5

group group1 7
limits n=2 m=5000000
tc 1
tc 2
tc 1-rand1 gen_random n=2 m=5000000
tc 1-rand2 gen_random n=2 m=5000000 alphabet=aaab

group group2 10
limits n=100 m=10000
tc 3
tc 4
tc 5
tc 2-garbage gen_random n=100 m=10000
tc 2-yes1 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes2 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes3 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes4 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes5 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes6 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-no1 gen_random_sorted n=100 m=5000 dens=0.8 bad=1 seed=1
tc 2-no2 gen_random_sorted n=100 m=5000 dens=0.8 bad=1 seed=2
tc 2-no3 gen_random_sorted n=100 m=5000 dens=0.8 bad=1 seed=3
tc 2-no4 gen_random_sorted n=100 m=5000 dens=0.8 bad=1 seed=4
tc 2-no5 gen_random_sorted n=100 m=5000 dens=0.8 bad=1 seed=5
tc 2-no6 gen_random_sorted n=100 m=5000 dens=0.8 bad=1 seed=6

group group3 15
limits n=100000 m=5000000
include_group group1
include_group group2
tc 3-garbage gen_random n=100000 m=5000000
tc 3-yes1 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes2 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes3 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes4 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes5 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes6 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-no1 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1 seed=1
tc 3-no2 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1 seed=2
tc 3-no3 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1 seed=3
tc 3-no4 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1 seed=4
tc 3-no5 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1 seed=5
tc 3-no6 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1 seed=6
