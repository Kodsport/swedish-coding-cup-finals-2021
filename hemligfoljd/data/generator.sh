#!/usr/bin/env bash
. gen.sh

use_solution ../../data/cnt.cpp

compile gen_random.py
compile gen_cont.py

samplegroup
# no samples

group group1 5
limits n=1000 k=1 cont=0 d=200
tc one-1 gen_random n=1 k=0 d=200
tc one-2 gen_random n=1 k=1 d=200
tc one-3 gen_random n=17 k=0 d=200
tc one-4 gen_random n=973 k=0 d=200
tc one-5 gen_random n=36 k=1 d=200
tc one-6 gen_random n=1000 k=1 d=200
tc_manual ../manual_tests/m1.in
tc_manual ../manual_tests/m2.in

group group2 10
limits n=200 k=200 cont=0 d=200
tc on-1 gen_random n=196 k=0 d=200
tc on-2 gen_random n=197 k=7 d=200
tc on-3 gen_random n=198 k=53 d=200
tc on-4 gen_random n=199 k=172 d=200
tc on-5 gen_random n=200 k=194 d=200
tc on-6 gen_random n=200 k=200 d=200

group group3 10
limits n=200000 k=200000 cont=1 d=200
include_group group1
tc cont-1 gen_cont n=100000 k=8 d=200
tc cont-2 gen_cont n=100000 k=972 d=200
tc cont-3 gen_cont n=100000 k=3482 d=200
tc cont-4 gen_cont n=100000 k=71234 d=200
tc cont-5 gen_cont n=200000 k=46 d=200
tc cont-6 gen_cont n=200000 k=928 d=200
tc cont-7 gen_cont n=200000 k=82343 d=200
tc cont-8 gen_cont n=200000 k=199923 d=200
tc cont-9 gen_cont n=199999 k=199999 d=200


group group4 45
limits n=200000 k=200000 cont=0 d=200
include_group group1
include_group group2
include_group group3
tc no-1 gen_random n=200000 k=123 d=200
tc no-2 gen_random n=200000 k=1523 d=200
tc no-3 gen_random n=200000 k=6523 d=200
tc no-4 gen_random n=200000 k=36324 d=200
tc no-5 gen_random n=200000 k=123422 d=200
tc no-6 gen_random n=200000 k=192342 d=200
