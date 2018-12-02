#! /bin/bash
# cars.sh
#Haifan(Peter) Chen
while true; do
	echo "What would you like to do?"
	echo "1. Add a car"
	echo "2. List the cars in the inventory file"
	echo "3. Quit the program"
	read result

	case $result in
		1)
			echo "What year is the car?"
			read year
			echo "What is the make?"
			read make
			echo "What is the model?"
			read model
			a=":"
			combine="$year$a$make$a$model"
			echo $combine >> My_old_cars.txt
			;;
		2)
			echo "-----------Here is your file-----------"
			sort My_old_cars.txt
			# echo "$(<My_old_cars.txt)"
			echo "================END================"
			;;
		3)
			echo "Goodbye!"
			break
			;;
		*) echo "You do not select a number between 1 to 3"
			;;
	esac

	# if [ $result -eq 1 ] ; then
	# 	echo "What year is the car?"
	# 	read year
	# 	echo "What is the make?"
	# 	read make
	# 	echo "What is the model?"
	# 	read model
	# 	a=":"
	# 	combine="$year$a$make$a$model"
	# 	echo $combine >> My_old_cars.txt
	# elif [ $result -eq 2 ] ; then
	# 	echo "-----------Here is your file-----------"
	# 	echo "$(<My_old_cars.txt)"
	# 	echo "================END================"
	# else
	# 	echo "Goodbye!"
	# 	break
	# fi
done
