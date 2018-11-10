#! /bin/bash
#numbers.sh
#Haifan Chen
echo "Enter a number: "
read numbers

times=1
a=" even"
b=" odd"


while [ $times -le $numbers ]
do
	if [ $((times%2)) -eq 0 ] ; then
		echo "$times$a"
	else
		echo "$times$b"
	fi
	times=$((times+1))
done
echo "Thank you"
