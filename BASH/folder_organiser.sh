#!/bin/bash

# Author: Berk Topbas

# Created Date: 27.09.2021

# Last Modified Date: 29.09.2021

# Description: Moves files with specific extensions to subfolders(if doesn't exist, first creates) with related names.

# Usage Information: ./folder_organiser.sh

read -p "Which folder do you want to orginise? :" folder

while read filename; do

	case "$filename" in
	
		*.jpg | *.jpeg | *.png) 
			subfolder="images"
			;;
		*.doc | *.docx | *.txt | *.pdf) 
			subfolder="documents"
			;;
		*.xls | *.xlsx | *.csv) 
			subfolder="spreadsheets"
			;;
		*.sh) 
			subfolder="scripts"
			;;
		*.zip | *.tar | *.tar.gz | *.tar.bz2) 
			subfolder="archives"
			;;
		*.ppt | *.pptx) 
			subfolder="presentations"
			;;
		*.mp3) 
			subfolder="audio"
			;;
		*.mp4) 
			subfolder="video"
			;; 
		*)
			subfolder="."
			;;

	esac
	
	if [ ! -d "$folder/$subfolder" ]; then
		mkdir "$folder/$subfolder"
		echo "$folder/$subfolder folder created"
	fi
	
	mv "$filename" "$folder/$subfolder"

done < <(ls "$folder")
