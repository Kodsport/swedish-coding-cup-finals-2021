#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution js.cpp opt
compile gen_random_lines.py

samplegroup
limits maxB=100
sample 1
sample 2

group group1 10
limits maxB=1
tc 2
tc line01 gen_random_lines N=100 M=100
tc line02 gen_random_lines N=100 M=100
tc line03 gen_random_lines N=100 M=100
tc line04 gen_random_lines N=100 M=100
tc line05 gen_random_lines N=50 M=100
tc line06 gen_random_lines N=50 M=100
tc line07 gen_random_lines N=50 M=100
tc line08 gen_random_lines N=50 M=100
tc line09 gen_random_lines N=10 M=100
tc line10 gen_random_lines N=10 M=100
tc line11 gen_random_lines N=10 M=100
tc line12 gen_random_lines N=10 M=100
tc line13 gen_random_lines N=10 M=30
tc line14 gen_random_lines N=10 M=30
tc line15 gen_random_lines N=10 M=30
tc line16 gen_random_lines N=10 M=30

group group2 10
limits maxB=2
include_group group1

group group3 10
limits maxB=100
include_group group2
tc 1
