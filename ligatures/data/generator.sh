#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution sl.cpp opt

compile gen_random.py

samplegroup
limits k=20
sample 1
sample 2
sample 3

group group1 10
limits k=1
tc 1-rand1 gen_random k=1

group group2 10
limits k=2
include_group group1
tc 2-rand1 gen_random k=2

group group3 10
limits k=3
include_group group2
tc 3-rand1 gen_random k=3

group group4 10
limits k=4
include_group group3
tc 4-rand1 gen_random k=4

group group5 10
limits k=10
include_group group4
tc 5-rand1 gen_random k=10

group group6 10
limits k=20
include_group group5
tc 6-rand1 gen_random k=20
