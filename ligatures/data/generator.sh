#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution sl_simd.cpp opt

compile gen_random.py

samplegroup
limits k=20
sample 1
sample 2
sample 3

group group1 10
limits k=1
tc 1
tc 1-randmax gen_random k=1 n=1000000 q=100000
tc 1-rand2 gen_random k=1 a=inv b=inv2
tc 1-aaa gen_random k=1 a=1
tc 1-onlyaaquery gen_random k=1 b=1
tc 1-nooverlap gen_random k=1 a=1 b=1 uncor=1 seed=1
tc 1-n1 gen_random n=1 k=1
tc 1-q1 gen_random q=1 k=1

group group2 15
limits k=2
include_group group1
tc 2
# attempts=1 is used for most generators because alphabet^4 < q when we focus
# the alphabet around a's. That is, duplicate queries are unavoidable.
# reuse=0.7 creates some repeated patterns in the searched string, which is nice.
tc 2-rand1 gen_random k=2 reuse=0.7
tc 2-rand2 gen_random k=2 a=inv b=inv attempts=1  # slightly biased towards a's
tc 2-rand3 gen_random k=2 a=inv3 b=inv3 reuse=0.7 attempts=1  # very biased towards a's for both values and queries
tc 2-rand4 gen_random k=2 a=inv3 b=inv2 attempts=1
tc 2-rand5 gen_random k=2 a=10 b=10 attempts=1
tc 2-aaa gen_random k=2 a=1 b=inv3 attempts=1
tc 2-ab gen_random k=2 a=1,b b=inv3 attempts=1 reuse=0
tc 2-graph1 gen_random k=2 a=inv b=inv graph=abbc reuse=0.9 attempts=1

group group3 25
limits k=3
include_group group2
tc 3
tc 3-rand1 gen_random k=3 reuse=0.7
tc 3-graph1 gen_random k=3 a=inv b=inv graph=abbccd reuse=0.9
tc 3-graph2 gen_random k=3 a=inv b=inv graph=abbbbc reuse=0.9
tc 3-graph3 gen_random k=3 a=inv b=inv graph=abbabc reuse=0.9
tc 3-froma gen_random k=3 a=inv2 b=inv2 bfroma=1
tc 3-rand2 gen_random k=3 a=inv b=inv attempts=1  # slightly biased towards a's
tc 3-rand3 gen_random k=3 a=inv3 b=inv3 reuse=0.7 attempts=1  # very biased towards a's
tc 3-rand4 gen_random k=3 a=11 b=10 reuse=0.7 # q ~ 10^2k / k!
tc 3-rand5 gen_random k=3 a=inv b=inv  # slightly biased towards a's, but without so many duplicates
tc 3-rand6 gen_random k=3 a=inv2 b=inv2
tc 3-rand7 gen_random k=3 a=inv2 b=inv2 uncor=1
tc 3-rand8 gen_random k=3 a=10 b=10 uncor=1
tc 3-aaa gen_random k=3 a=1 b=inv3 attempts=1
tc 3-ab gen_random k=3 a=1,b b=inv3 attempts=1 reuse=0

group group4 15
limits k=4
include_group group3
tc 4-rand1 gen_random k=4 reuse=0.7
tc 4-graph1 gen_random k=4 a=inv b=inv graph=abbccdde reuse=0.1
tc 4-graph2 gen_random k=4 a=inv b=inv graph=abbbbccd reuse=0.3
tc 4-graph3 gen_random k=4 a=inv b=inv graph=daabbabc reuse=0.9
tc 4-froma gen_random k=4 a=inv2 b=inv2 bfroma=1
tc 4-rand2 gen_random k=4 a=inv3 b=inv3 reuse=0.7 attempts=1
tc 4-rand3 gen_random k=4 a=7 b=7 reuse=0.7 # q ~ 7^2k / k!
tc 4-rand4 gen_random k=4 a=inv b=inv
tc 4-aaa gen_random k=4 a=1 b=inv3 attempts=1
tc 4-ab gen_random k=4 a=1,b b=inv3 reuse=0

group group5 10
limits k=5
include_group group4
tc 5-rand1 gen_random k=5 reuse=0.7
tc 5-froma gen_random k=5 a=inv2 b=inv2 bfroma=1
tc 5-rand2 gen_random k=5 a=inv3 b=inv3 reuse=0.7 attempts=1
tc 5-rand3 gen_random k=5 a=7 b=6 # q ~ 6^2k / k!
tc 5-rand4 gen_random k=5 a=inv b=inv
tc 5-aaa gen_random k=5 a=1 b=inv3 attempts=1
tc 5-ab gen_random k=5 a=1,b b=inv3 reuse=0

group group6 35
limits k=20
include_group group5
tc 6-rand1 gen_random k=20 reuse=0.7
tc 6-froma gen_random k=20 a=inv bfroma=1
tc 6-rand2 gen_random k=20 a=inv3 b=inv
tc 6-rand3 gen_random k=20 a=inv3 b=inv3
tc 6-rand4 gen_random k=20 a=6 b=6 # q ~ (6^2 choose k)
tc 6-rand5 gen_random k=20 a=inv b=inv
tc 6-aaa gen_random k=20 a=1 b=inv attempts=1
