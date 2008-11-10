#! /bin/sh

TEST_SUITE="test_all test_all2 test_all3
test_any test_any2 test_any3
test_none test_none2 test_none3
test_one test_one2 test_one3"
EXIT=0

for tst in $TEST_SUITE; do
    if [ x"$(./"${tst}" | grep FAIL)" != x ]; then
	echo "Test $tst fails"
	EXIT=1
    fi
done

exit $EXIT
