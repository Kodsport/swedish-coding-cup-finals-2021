#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution js.cpp opt

samplegroup
limits maxTot=1000 maxB=100
sample 1
sample 2

group group1 10
limits maxTot=20 maxB=100
tc 1

group group2 10
limits maxTot=1000 maxB=1
tc 2

group group3 10
limits maxTot=1000 maxB=2
include_group group2
tc 2

group group4 10
limits maxTot=1000 maxB=100
include_group group1
include_group group3
