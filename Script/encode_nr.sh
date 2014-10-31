#!/bin/bash

fname=`ls *.h *.c`
for i in $fname; do
	enca -L zh_CN -x UTF-8 $i;
	dos2unix $i
done
