#!/bin/bash

INPUT_FILE_NAME=$PWD/input.file
EXT_NAME=file
OUT_DIR_NAME=$PWD/output

mkdir -p $OUT_DIR_NAME
cd $OUT_DIR_NAME
#split activity
awk '/>/{filename=NR".txt"}; {print >filename}' $INPUT_FILE_NAME

#rename actvity
for file in *.txt; 
do
	echo $file
	if [[ -f $file ]]; 
	then
	    # get the file name
		fileword=$(head -n1 "$file" | sed 's/>//g');
		sed -i '1d' $file
		#cat $file
		# Everything after first dot is considered as extention
		ext=$EXT_NAME
		#echo $ext
		#echo $fileword
		[ "$file" != "$fileword" ] && $(mv  "$file"  "$OUT_DIR_NAME/$fileword.$ext")
	fi;
done
echo "output dir: $OUT_DIR_NAME"
