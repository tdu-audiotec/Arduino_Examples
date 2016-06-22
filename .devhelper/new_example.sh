#!/bin/bash

CMAKELISTS=CMakeLists.txt

if [ $# -gt 0 ]; then
	projcet_name=${1}
fi
if [ $# -gt 1 ]; then
	projcet_name=${projcet_name}_${2}
fi
if [ $# -gt 2 ]; then
	projcet_name=${projcet_name}_${3}
fi

if [ ! -z "${projcet_name}" ]; then
	if [ -e "${projcet_name}" ]; then
	    echo "Skipping the creation of "${projcet_name}"..."
	else
		#echo "  " >> README.md
		echo "${projcet_name} added.  " >> README.md
	    echo "Creating "${projcet_name}"..."
	    MESSAGE="${projcet_name} added."
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
		if [ $# -gt 0 ]; then
		DESC=`echo -e This\ directory\ contains\ an\ Arduino\ sample\ code\ for\ controlling\ ${1}`
		fi
		if [ $# -gt 1 ]; then
		DESC="${DESC}"`echo -e \ via\ ${2}`
		fi
		if [ $# -gt 2 ]; then
		DESC="${DESC}"`echo -e \ and\ ${3}`
		fi
		echo "${DESC}." >> ${projcet_name}/README.md
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
