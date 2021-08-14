#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution js.cpp opt
compile gen_random_lines.py
compile gen_empty.py
compile gen_binary_identical.py
compile gen_binary_cuts.py
compile gen_bincomplete_cuts.py

samplegroup
limits maxB=100 singleTree=0
sample 1
sample 2
sample 3

group group1 10
limits maxB=1 singleTree=0
tc 2
tc empty gen_empty
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
limits maxB=2 singleTree=1
tc empty
tc 3
tc bin-ident01 gen_binary_identical
tc bin-ident02 gen_binary_identical
tc bin-ident03 gen_binary_identical
tc bin-01 gen_binary_cuts
tc bin-02 gen_binary_cuts
tc bin-03 gen_binary_cuts
tc bin-04 gen_binary_cuts
tc bin-05 gen_binary_cuts
tc bin-06 gen_binary_cuts
tc bin-07 gen_binary_cuts
tc bincomplete-01 gen_bincomplete_cuts
tc bincomplete-02 gen_bincomplete_cuts
tc bincomplete-03 gen_bincomplete_cuts
tc bincomplete-04 gen_bincomplete_cuts
tc bincomplete-05 gen_bincomplete_cuts
tc bincomplete-06 gen_bincomplete_cuts
tc bincomplete-07 gen_bincomplete_cuts

group group3 10
limits maxB=100 singleTree=0
include_group group1
include_group group2
tc 1
