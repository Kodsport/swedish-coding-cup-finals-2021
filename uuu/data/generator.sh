#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution nils.py

compile gen_fixed.py

samplegroup
sample_manual 1

group group1 10
tc tc1 gen_fixed 100 500
