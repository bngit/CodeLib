#!/bin/bash

function lsdir () {
	for File in `ls $1`
	do
		if [ -d $1'/'$File ]
		then
			lsdir $1'/'$File
		else
			dos2unix $1'/'$File
			chmod -x $1'/'$File
		fi
	done
}

lsdir .
