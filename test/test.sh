#!/bin/bash
cd `dirname $0`

assert() {
  expected="$1"
  input="$2"

  ../dicc "$input" > test.s
  make clean
  make
  ./test
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 0 0
assert 42 42
assert $((11 + 27 - 5))  "11 + 27 - 5"

echo OK