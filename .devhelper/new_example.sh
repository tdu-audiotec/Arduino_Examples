#!/bin/bash

CMAKELISTS=CMakeLists.txt

projcet_name=${1}_${2}

if [ -e "${projcet_name}" ]; then
    echo "Skipping the creation of "${projcet_name}"..."
else
    echo "Creating "${projcet_name}"..."
    mkdir ${projcet_name}
    touch ${projcet_name}/${projcet_name}.ino
	eqcount=`seq ${#projcet_name}`
	echo ${eqcount}
	for i in `echo ${eqcount}`
	do
		eqchain=${eqchain}"="
	done
    echo ${projcet_name} > ${projcet_name}/README.md
	echo ${eqchain} >> ${projcet_name}/README.md
	echo -e This\ directory\ contains\ an\ Arduino\ sample\ code\ for\ controlling\ ${1}\ via ${2}. >> ${projcet_name}/README.md
fi


for ignore in `cat .gitignore | egrep -v ^\#`
do
    ignore_list="${ignore_list}\\|${ignore}"
done
ignore_list=`echo ${ignore_list} | sed -e 's/^\\\|//g'`
ignore_list=\'${ignore_list}\'

for project in `ls -F1 | grep /`
do
    project_list=${project_list}" "`echo ${project} | grep -v ${ignore_list}`
done

project_list=`echo ${project_list} | sed -e "s|/||g"`

echo ${project_list}


echo -e cmake\_minimum\_required\(VERSION\ 2\.8\.4\) > ${CMAKELISTS}
echo -e set\(CMAKE\_TOOLCHAIN\_FILE\ \$\{CMAKE\_SOURCE\_DIR\}\/cmake\/ArduinoToolchain\.cmake\) >> ${CMAKELISTS}
echo -e project\ \(Arduino\_Examples\) >> ${CMAKELISTS}
for project in `echo ${project_list}` 
do
	if [ -e "${project}/cmake" ]; then
        echo "cmake already exists in ${project}"
    else
    	echo "copying cmake to ${project}"
        cp -R cmake ${project}
    fi
    echo -e cmake\_minimum\_required\(VERSION\ 3\.5\) > ${project}/${CMAKELISTS}
	echo -e set\(CMAKE\_TOOLCHAIN\_FILE\ \$\{CMAKE\_CURRENT\_SOURCE\_DIR\}\/cmake\/ArduinoToolchain\.cmake\) >> ${project}/${CMAKELISTS}
	echo -e set\(PROJECT\_NAME\ ${project}\) >> ${project}/${CMAKELISTS}
	echo -e set\(\$\{PROJECT\_NAME\}\_SKETCH\ \$\{PROJECT\_NAME\}\.ino\) >> ${project}/${CMAKELISTS}
	echo -e generate\_arduino\_firmware\(\$\{PROJECT\_NAME\}\) >> ${project}/${CMAKELISTS}
done