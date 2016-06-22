#!/bin/bash
tmp=`mktemp`

echo -e \#ifndef\ \_${2}\_H\_ > ${tmp}
echo -e \#define\ \_${2}\_H\_\\n >> ${tmp}
echo -e \#if\ ARDUINO\ \>\=\ 100 >> ${tmp}
echo -e \#include\ \<Arduino\.h\> >> ${tmp}
echo -e \#else >> ${tmp}
echo -e \#include\ \<WProgram\.h\> >> ${tmp}
echo -e \#endif\\n >> ${tmp}

cat ${1}.cpp | egrep ^\/\/\}\|^\/\/[A-Z,a-z]+\|^[A-Z,a-z]+ | sed -e "s|^\/\/||g" -e "s|${2}\:\:||g" >> ${tmp}

echo -e \\n\#endif\\n >> ${tmp}

sed -i 's|) {|);|g' ${tmp}
sed -i "s|^|\ \ \ \ |g" ${tmp}
sed -i "s|^\ \ \ \ \#|\#|g" ${tmp}
sed -i "s|^\ \ \ \ class|class|g" ${tmp}
sed -i "s|^\ \ \ \ public|public|g" ${tmp}
sed -i "s|^\ \ \ \ private|private|g" ${tmp}
sed -i "s|^\ \ \ \ \}|\}|g" ${tmp}
#mv ${1}.h ${1}.h.bak
#cp ${1}.cpp ${1}.cpp.bak
cat ${tmp} > ${1}.h
rm ${tmp}