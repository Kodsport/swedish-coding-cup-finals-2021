#!/usr/bin/env bash
. gen.sh

use_solution ../../data/cnt.cpp

compile gen_random.py
compile gen_cont.py

samplegroup
# no samples

group group1 5
limits n=1000 k=1 cont=0 d=1000
tc one-1 gen_random n=10 k=0 d=1000
tc one-2 gen_random n=1000 k=0 d=1000
tc one-3 gen_random n=10 k=1 d=1000
tc one-4 gen_random n=1000 k=1 d=1000

group group2 10
limits n=100000 k=100000 cont=1 d=100000
tc cont-1 gen_cont n=100000 k=10 d=100000
tc cont-2 gen_cont n=100000 k=1000 d=100000
tc cont-3 gen_cont n=100000 k=10000 d=100000
tc cont-4 gen_cont n=100000 k=50000 d=100000

group group3 10
limits n=100000 k=100000 cont=0 d=100000
tc on-1 gen_random n=100000 k=10 d=100000
tc on-2 gen_random n=100000 k=1000 d=100000
tc on-3 gen_random n=100000 k=10000 d=100000
tc on-4 gen_random n=100000 k=50000 d=100000

group group4 45
limits n=100000 k=100000 cont=0 d=500
tc no-1 gen_random n=100000 k=11 d=500
tc no-2 gen_random n=100000 k=1001 d=500
tc no-3 gen_random n=100000 k=10001 d=500
tc no-4 gen_random n=100000 k=50001 d=500
