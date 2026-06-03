#!/bin/bash
# Argument / error-handling tests. Run from the project root: bash tests/test_args.sh
PS=./push_swap
pass=0
fail=0

check()
{
	local desc="$1"
	local expect_out="$2"
	local expect_code="$3"
	shift 3
	local out
	out=$("$PS" "$@" 2>&1)
	local code=$?
	if [[ "$out" == "$expect_out" && "$code" == "$expect_code" ]]; then
		echo "OK   : $desc"
		pass=$((pass + 1))
	else
		echo "FAIL : $desc (got out='$out' code=$code, want out='$expect_out' code=$expect_code)"
		fail=$((fail + 1))
	fi
}

check "no args -> nothing, exit 0" "" 0
check "already sorted -> nothing" "" 0 1 2 3
check "single number -> nothing" "" 0 42
check "non-integer arg -> Error" "Error" 1 1 abc 3
check "duplicate -> Error" "Error" 1 1 1 2
check "overflow high -> Error" "Error" 1 2147483648
check "overflow low -> Error" "Error" 1 -2147483649
check "unknown flag -> Error" "Error" 1 --foo 3 2 1
check "lone dash -> Error" "Error" 1 - 2 3
check "INT_MIN/INT_MAX accepted (sorted)" "" 0 -2147483648 0 2147483647

echo "----------------------------------------"
echo "args tests: $pass passed, $fail failed"
[[ $fail -eq 0 ]]
