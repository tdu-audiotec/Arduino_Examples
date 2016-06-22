#!/bin/bash

CMAKELISTS=CMakeLists.txt
README=README.md
temp_readme1=`mktemp`
temp_readme2=`mktemp`
temp_sketch=`mktemp`
temp_cmake=`mktemp`
DESC2=${2}
DESC3=${3}
DESC4=${4}



if [ $# -gt 0 ]; then
	projcet_name=${1}
fi

if [ ! -z "${projcet_name}" ]; then
	if [ ! -e "${projcet_name}" ]; then
	    echo "Creating "${projcet_name}"..."
	    mkdir ${projcet_name}
	    MESSAGE="${projcet_name} added."
	fi
fi


for ignore in `cat .gitignore | egrep -v ^\#`
do
    ignore_list="${ignore_list}\\|${ignore}"
done
ignore_list=`echo ${ignore_list} | sed -e 's/^\\\|//g'`
ignore_list=\'${ignore_list}\'


for project in `ls -F1 | grep /`
do
    project_list="${project_list} "`echo ${project} | grep -v ${ignore_list}`
done
project_list=`echo ${project_list} | sed -e "s|/||g"`

cat .devhelper/templates/CMakeLists_header.txt > ${temp_cmake}
cat .devhelper/templates/README_REPO.md > ${temp_readme1}

for project in `echo ${project_list}` 
do
	if [ ! -e "${project}" ]; then
		mkdir ${project} 
	fi  
	if [ ! -e "${project}/${README}" ]; then
		touch ${project}/${README} 
	fi  
	if [ ! -e "${project}/drafts" ]; then
		mkdir ${project}/drafts 
	fi  
	if [ ! -e "${project}/examples" ]; then
		mkdir ${project}/examples 
	fi  
	if [ ! -e "${project}/examples/${project}" ]; then
		mkdir ${project}/examples/${project} 
	fi  
	if [ ! -e "${project}/examples/${project}/${project}.ino" ]; then
		touch ${project}/examples/${project}/${project}.ino 
	fi  
	if [ ! -e "${project}/library.properties" ]; then
		cat .devhelper/templates/library.properties|sed -e "s|ARDUPROJECT|${project}|g" > ${project}/library.properties
	fi  
	if [ ! -e "${project}/LICENSE" ]; then
		cat .devhelper/templates/LICENSE > ${project}/LICENSE
	fi		
	cat .devhelper/templates/CMakeLists_recurse.txt|sed -e "s|ARDUPROJECT|${project}|g" >> ${temp_cmake}
		if [ -e "${project}/library.properties" ]; then
			if [ ! -e "${project}/${project}.h" ]; then
				tproject=${project}"(Work in progress)"
			fi
			eqcount=`seq ${#tproject}`
			for i in `echo ${eqcount}`
			do
				eqchain=${eqchain}"="
			done
			
			echo ${tproject} > ${temp_readme2}
			echo ${eqchain} >> ${temp_readme2}
			
				CONTENT=`cat ${project}/library.properties|grep sentence|sed -e 's|sentence=||g'`
				cat .devhelper/templates/README_PROJ.md | sed -e "s|CONTENT|${CONTENT}|g" >> ${temp_readme2}
			
			cat "${temp_readme2}" > ${project}/${README}
			#cat "${temp_readme2}"
			#echo ""
		fi	
	echo "${project} added.  " >> ${temp_readme1}
	rm ${project}/*.bak
done


cat ${temp_readme1} > ${README}
cat ${temp_cmake} > ${CMAKELISTS}

if [ -v "${MESSAGE}" ]; then
	MESSAGE=${MESSAGE}
else
	MESSAGE="Progress"
fi

git add --all .
git commit -m ${MESSAGE}
git push
