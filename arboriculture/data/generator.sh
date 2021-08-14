#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution js.cpp opt

samplegroup
limits maxB=100
sample 1
sample 2

group group1 10
limits maxB=1
tc 2

group group2 10
limits maxB=2
include_group group1

group group3 10
limits maxB=100
include_group group2
tc 1
