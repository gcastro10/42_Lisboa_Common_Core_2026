#!/bin/bash
# Valgrind leak tests across success and error paths.
# Run from the project root: bash tests/test_leaks.sh
PS=./push_swap
VG="valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=42 -q"
fail=0

run()
{
	local desc="$1"
	shift
	$VG "$PS" "$@" >/dev/null 2>/tmp/ps_leak.txt
	local code=$?
	if [[ $code -eq 42 ]]; then
		echo "LEAK : $desc"
		cat /tmp/ps_leak.txt
		fail=1
	else
		echo "CLEAN: $desc"
	fi
}

run "empty args"
run "error: duplicate" 1 1 2
run "error: non-int" 1 a 2
run "sorted input" 1 2 3 4 5
run "simple 100" --simple $(shuf -i 0-999999 -n 100 | tr '\n' ' ')
run "medium 200" --medium $(shuf -i 0-999999 -n 200 | tr '\n' ' ')
run "complex 500" --complex $(shuf -i 0-999999 -n 500 | tr '\n' ' ')
run "adaptive 500 + bench" --bench $(shuf -i 0-999999 -n 500 | tr '\n' ' ')

echo "----------------------------------------"
[[ $fail -eq 0 ]] && echo "NO LEAKS" || echo "LEAKS DETECTED"
[[ $fail -eq 0 ]]
