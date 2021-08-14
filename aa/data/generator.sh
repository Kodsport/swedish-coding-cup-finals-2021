#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution sl.cpp opt

compile gen_random.py pypy
compile gen_random_sorted.py pypy
compile gen_rec.py

samplegroup
limits n=100 m=1000
sample 1
sample 2
sample 3
sample 4
sample 5

group group1 5
limits n=2 m=5000000
tc 1
tc 2
tc 1-rand1 gen_random n=2 m=5000000
tc 1-rand2 gen_random n=2 m=5000000 alphabet=aaab

group group2 20
limits n=100 m=5000
tc 3
tc 4
tc 5
tc_manual ../manual-tests/manual1.in
tc_manual ../manual-tests/manual2.in
tc_manual ../manual-tests/manual3.in
tc_manual ../manual-tests/manual4.in
tc_manual ../manual-tests/manual5.in
tc_manual ../manual-tests/manual6.in
tc_manual ../manual-tests/manual7.in
tc_manual ../manual-tests/manual8.in
tc 2-garbage gen_random n=100 m=5000
tc 2-yes1 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-no1 gen_random_sorted n=100 m=5000 dens=0.8 bad=1
tc 2-yesrec1 gen_rec n=65 m=3200
tc 2-norec1 gen_rec n=65 m=3200 bad=1 seed=7
tc 2-smallno1 gen_random_sorted n=100 m=1000 dens=0.8 bad=1
tc 2-yes2 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes3 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes4 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes5 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-yes6 gen_random_sorted n=100 m=5000 dens=0.8
tc 2-smallyes1 gen_random_sorted n=100 m=1000 dens=0.8
tc 2-smallyes2 gen_random_sorted n=100 m=1000 dens=0.8
tc 2-smallyes3 gen_random_sorted n=100 m=1000 dens=0.8
tc 2-smallyes4 gen_random_sorted n=100 m=1000 dens=0.8
tc 2-smallyes5 gen_random_sorted n=100 m=1000 dens=0.8
tc 2-smallyes6 gen_random_sorted n=100 m=1000 dens=0.8
tc 2-no2 gen_random_sorted n=100 m=5000 dens=0.8 bad=1
tc 2-no3 gen_random_sorted n=100 m=5000 dens=0.8 bad=1
tc 2-no4 gen_random_sorted n=100 m=5000 dens=0.8 bad=1
tc 2-no5 gen_random_sorted n=100 m=5000 dens=0.8 bad=1
tc 2-no6 gen_random_sorted n=100 m=5000 dens=0.8 bad=1
tc 2-smallno2 gen_random_sorted n=100 m=1000 dens=0.8 bad=1
tc 2-smallno3 gen_random_sorted n=100 m=1000 dens=0.8 bad=1
tc 2-smallno4 gen_random_sorted n=100 m=1000 dens=0.8 bad=1
tc 2-smallno5 gen_random_sorted n=100 m=1000 dens=0.8 bad=1
tc 2-smallno6 gen_random_sorted n=100 m=1000 dens=0.8 bad=1
tc 2-norec2 gen_rec n=70 m=3700 i=1 bad=1 seed=5
tc 2-yesrec2 gen_rec n=70 m=3700 i=1
tc 2-norec3 gen_rec n=65 m=3200 bad=1 seed=6
tc 2-yesrec3 gen_rec n=65 m=3200 seed=6

group group3 35
limits n=100000 m=5000000
include_group group1
include_group group2
tc 3-garbage gen_random n=100000 m=5000000
tc 3-yes1 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-no1 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1
tc 3-yesrec1 gen_rec n=65000 m=3200000
tc 3-norec1 gen_rec n=65000 m=3200000 bad=1
tc 3-yes2 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes3 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes4 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes5 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-yes6 gen_random_sorted n=100000 m=5000000 dens=0.8
tc 3-no2 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1
tc 3-no3 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1
tc 3-no4 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1
tc 3-no5 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1
tc 3-no6 gen_random_sorted n=100000 m=5000000 dens=0.8 bad=1
tc 3-smallno1 gen_random_sorted n=100000 padm=500000 m=1000000 dens=0.8 bad=1
tc 3-smallno2 gen_random_sorted n=100000 m=2000000 dens=0.8 bad=1
tc 3-smallno3 gen_random_sorted n=100000 m=3000000 dens=0.8 bad=1
tc 3-smallno4 gen_random_sorted n=100000 m=500000 dens=0.8 bad=1
tc 3-smallno5 gen_random_sorted n=100000 m=1500000 dens=0.8 bad=1
tc 3-smallno6 gen_random_sorted n=100000 m=2000000 dens=0.8 bad=1
tc 3-yesrec2 gen_rec n=75000 m=3800000 i=1
tc 3-yesrec3 gen_rec n=65000 m=3200000
tc 3-yesrec4 gen_rec n=65000 m=3200000
tc 3-norec2 gen_rec n=75000 m=3800000 i=1 bad=1 seed=4
tc 3-norec3 gen_rec n=85000 m=4500000 i=5 bad=400 seed=5
tc 3-norec4 gen_rec n=65000 m=3200000 bad=1
