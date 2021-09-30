#!/bin/bash

# Author: Berk Topbas

# Created Date: 27.09.2021

# Last Modified Date : 27.09.2021

# Description : Puts(with prompt) files of a given folder, that have not been modified within a given number of days, to trash.

# Usage Information : ./cruft_remover.sh


read -p "Which folder do you want to remove unmodified files from? " folder
read -p "How many days files should be unmodified for to be considered as 'cruft': " days

readarray -t files < <(find "$folder" -maxdepth 1 -type f -mtime "+$days")

for file in "${files[@]}"; 
do
	rmtrash -i "$file"
done
