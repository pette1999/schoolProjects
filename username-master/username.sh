#! /bin/bash
# username.sh.sh
echo "-----RULES----->>>"
echo "--The only characters that can be used are "
echo "--lower case letters,digits, and the underscore character"
echo "--It must start with a lower case letter"
echo "--It must contain at least three but no more than 12 characters"
echo "-----RULE ENDS-----"
echo "Enter a username: "
read username
while echo $username | egrep -v "^[a-z][a-z0-9_]{2,11}$" > /dev/null 2>&1
do
	echo "You must enter a valid username!"
	echo "Enter a username: "
	read username
done
echo "Thank you"

