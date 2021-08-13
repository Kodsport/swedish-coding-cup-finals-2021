#!/usr/bin/env bash
. ../../testdata_tools/gen.sh

use_solution ../../data/cnt.cpp

compile gen_random.py
compile gen_cont.py

samplegroup
# manual .interaction samples

group group1 5
limits n=1000 k=1 cont=0
tc one-1 gen_random n=1 k=0
tc one-2 gen_random n=1 k=1
tc one-3 gen_random n=17 k=0
tc one-4 gen_random n=973 k=0
tc one-5 gen_random n=36 k=1
tc one-6 gen_random n=1000 k=1
tc_manual ../manual_tests/m1.in
tc_manual ../manual_tests/m2.in

group group2 8
limits n=200 k=200 cont=0
tc on-1 gen_random n=196 k=0
tc on-2 gen_random n=197 k=7
tc on-3 gen_random n=198 k=53
tc on-4 gen_random n=199 k=172
tc on-5 gen_random n=200 k=194
tc on-6 gen_random n=200 k=200

group group3 10
limits n=200000 k=200000 cont=1
include_group group1
tc cont-1 gen_cont n=100000 k=8
tc cont-2 gen_cont n=100000 k=972
tc cont-3 gen_cont n=100000 k=3482
tc cont-4 gen_cont n=100000 k=71234
tc cont-5 gen_cont n=200000 k=46
tc cont-6 gen_cont n=200000 k=928
tc cont-7 gen_cont n=200000 k=82343
tc cont-8 gen_cont n=200000 k=199923
tc cont-9 gen_cont n=199999 k=199999

group group4 12
limits n=4000 k=4000 cont=0
include_group group1
include_group group2
tc bad-1 gen_random n=3978 k=5
tc bad-2 gen_random n=3989 k=272
tc bad-3 gen_random n=3998 k=3452
tc bad-4 gen_random n=3999 k=2345
tc bad-5 gen_random n=4000 k=927
tc bad-6 gen_random n=4000 k=3562

group group5 35
limits n=200000 k=200000 cont=0
include_group group1
include_group group2
include_group group3
include_group group4
tc no-1 gen_random n=200000 k=123
tc no-2 gen_random n=200000 k=1523
tc no-3 gen_random n=200000 k=6523
tc no-4 gen_random n=200000 k=36324
tc no-5 gen_random n=200000 k=123422
tc no-6 gen_random n=200000 k=192342
