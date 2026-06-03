#!/bin/bash
# Performance + correctness benchmark. Run from project root: bash tests/test_perf.sh
PS=./push_swap
CHK="python3 tests/checker.py"

bench()
{
	local n="$1"
	local budget="$2"
	local trials="$3"
	local worst=0
	local i ARG ops res
	i=0
	while [ $i -lt "$trials" ]; do
		ARG=$(shuf -i 0-999999 -n "$n" | tr '\n' ' ')
		ops=$("$PS" $ARG | tee /tmp/ps_ops.txt | wc -l)
		res=$($CHK $ARG < /tmp/ps_ops.txt)
		if [[ "$res" != OK* ]]; then
			echo "  !! CORRECTNESS FAIL n=$n: $res"
		fi
		[ "$ops" -gt "$worst" ] && worst=$ops
		i=$((i + 1))
	done
	if [ "$worst" -lt "$budget" ]; then
		echo "OK   : n=$n worst=$worst ops (budget < $budget)"
	else
		echo "OVER : n=$n worst=$worst ops (budget < $budget)"
	fi
}

echo "Adaptive (default) benchmarks:"
bench 100 2000 10
bench 500 12000 10
