#!/bin/bash

for a in in/*.txt; do ./a.out < $a > $a.out; done
