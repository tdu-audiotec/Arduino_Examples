#!/bin/bash

CMAKELISTS=CMakeLists.txt
README=README.md

if [ $# -gt 0 ]; then
	projcet_name=${1}
fi

if [ ! -z "${projcet_name}" ]; then
	if [ -e "${projcet_name}" ]; then
	    echo "Skipping the creation of "${projcet_name}"..."
	else
		#echo "  " >> ${README}
		echo "${projcet_name} added.  " >> ${README}
	    echo "Creating "${projcet_name}"..."
	    MESSAGE="${projcet_name} added."
	    mkdir ${projcet_name}
	    mkdir ${projcet_name}/drafts
	    mkdir ${projcet_name}/examples
	    touch ${projcet_name}/examples/${projcet_name}/${projcet_name}.ino
		eqcount=`seq ${#projcet_name}`
		echo ${eqcount}
		for i in `echo ${eqcount}`
		do
			eqchain=${eqchain}"="
		done
	    echo ${projcet_name} > ${projcet_name}/${README}
		echo ${eqchain} >> ${projcet_name}/${README}
		if [ $# -gt 1 ]; then
		DESC=`echo -e This\ directory\ contains\ an\ Arduino\ Library\ for\ controlling\ ${2}`
		fi
		if [ $# -gt 2 ]; then
		DESC="${DESC}"`echo -e \ via\ ${3}`
		fi
		if [ $# -gt 3 ]; then
		DESC="${DESC}"`echo -e \ and\ ${4}`
		fi
		echo "${DESC}." >> ${projcet_name}/${README}
	fi
fi


for ignore in `cat .gitignore | egrep -v ^\#`
do
    ignore_list="${ignore_list}\\|${ignore}"
done
ignore_list=`echo ${ignore_list} | sed -e 's/^\\\|//g'`
ignore_list=\'${ignore_list}\'

ls -F1 | grep /
for project in `ls -F1 | grep /`
do
    project_list="${project_list} "`echo ${project} | grep -v ${ignore_list}`
done

project_list=`echo ${project_list} | sed -e "s|/||g"`

echo ${project_list}

echo -e cmake\_minimum\_required\(VERSION\ 2\.8\.4\) > ${CMAKELISTS}
echo -e set\(CMAKE\_TOOLCHAIN\_FILE\ \$\{CMAKE\_SOURCE\_DIR\}\/cmake\/ArduinoToolchain\.cmake\) >> ${CMAKELISTS}
echo -e project\ \(Arduino\_Examples\) >> ${CMAKELISTS}
for project in `echo ${project_list}` 
do
	if [ ! -e "${project}/drafts" ]; then
		mkdir ${project}/drafts
	fi
	if [ ! -e "${project}/${README}" ]; then
		touch ${project}/${README}
	fi
	if [ ! -e "${project}/examples/${project}/${project}.ino" ]; then
		mkdir ${project}/examples
		mkdir ${project}/examples/${project}
		touch ${project}/examples/${project}/${project}.ino
	fi
	if [ ! -e "${project}/library.properties" ]; then
		touch ${project}/library.properties
	fi
	if [ ! -e "${project}/LICENSE" ]; then
		touch ${project}/LICENSE
		cat .devhelper/templates/LICENSE > ${project}/LICENSE
	fi
	echo -e set\(PROJECT\_NAME\ ${project}\) >> ${CMAKELISTS}
	echo -e project\(${project}\) >> ${CMAKELISTS}
	echo -e set\($\{CMAKE\_PROJECT\_NAME\}\_SKETCH\ ${project}\/${project}\.ino\) >> ${CMAKELISTS}
	echo -e generate\_arduino\_firmware\($\{CMAKE\_PROJECT\_NAME\}\) >> ${CMAKELISTS}
done

if [ -v "${MESSAGE}" ]; then
	MESSAGE=${MESSAGE}
else
	MESSAGE="Progress"
fi

git add --all .
git commit -m ${MESSAGE}
