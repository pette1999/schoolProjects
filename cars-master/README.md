# cars
## The goal of the program
* To help the user maintain an inventory of old cars

##Instruction from the teacher
> Login to your g thusithub account and create a new repository named “cars" in your personal account – Be sure to include a README.md file in the repository
>
> Clone your repository to your computer
>
> Change into the repository directory and
  Create a file named “My_old_cars” that contains the following lines:
         1948:Ford:sedan
         1952:Chevrolet:coupe
         1960:Ford:Mustang
         1972:Chevrolet:Corvette
         1977:Plymouth:Roadrunner
  create a new script named cars.sh
>
> The first line of the script should be "#! /bin/bash"
>
> The second line should be a comment with the name of the script
>
> The third line should be a comment with your name
>
> Use a while loop to present the choices until the user chooses to Quit

## Function
* Add a car
* List the cars in the inventory file
* Quit the program

## Code(Part)
'''

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
      ......
'''

## Contact
* My Github
[Github](https://github.com/pette1999)
* Professor
[Dr.Fahy](https://www.chapman.edu/our-faculty/michael-fahy)






#**Thank you!**
