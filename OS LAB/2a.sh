#! /bin/bash
# Program to demostrate the arithmethic operation using case
choice=0
until [$choice==6]
do
        echo "Enter the two numbers onwhich the arithmetic operations are to be done: "
        read num1
        read num2
        echo "Enter the operation to be performed: "
        echo "1) Addition"
        echo "2) Substraction"
        echo "3) Multiplication"
        echo "4) Division"
        echo "5) Modulo(Remainder)"
        echo "6) Exit"
        read choice
        flag=0
        case "${choice}" in
                1)
                        res=$(( num1+num2 ))
                        operation=Addition
                        ;;
                2)
                        res=$(( num1-num2 ))
                        operation=Subtration
                        ;;
                3)
                        res=$(( num1*num2 ))
                        operation=Multiplication
                        ;;
                4)      if [ $num2 == 0 ]
                        then
                                echo "Cannot divide by zero"
                                flag=1
                        else
                                res=$(( num1/num2 ))
                                operation=Division
                        fi
                        ;;
                5)
                        res=$(( num1%num2 ))
                        operation=modulo
                        ;;
                6)
                        echo "Thank You"
                        break
                        ;;

                *)
                        echo "Wrong operation chosen. Enter again"
                        ;;
        esac
                if [ $flag == 1 ]
                then
                        flag=0
                        continue
                fi
                echo "The result of the $operation operation is $res"
done