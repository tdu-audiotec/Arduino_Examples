#!/bin/bash
tmp=`mktemp`

cat ${1}.cpp | egrep ^[A-Z,a-z]+ | sed -e "s|^\/\/||g" -e "s|${2}\:\:||g" -e 's|) {|)|g' | grep -v ${2} >> ${tmp}

cat ${tmp} > methods.txt
rm ${tmp}