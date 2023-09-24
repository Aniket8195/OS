clear

while [ 1 ]
do

echo 1.create 2.Display 3.Insert 4.Search 5.Modify 6.Delete 7.Exit
echo "enter choice \c" #\c to get input on same line
read ch

case $ch in
1)
	echo -n " Enter file name:"
	read fname
	if [ -e $fname ]
	then
		echo"file Already exist"
	else
		>>$fname
		echo " file created successfully"
	fi
	;;
2)
	echo -n " enter file name"
	read fname
	if [ -e $fname ]
	then
		echo " the content of file:"
		sort -n $fname
	else
		echo"file not exist"
	fi
	;;
3)
	echo -n"enter the file name:"
	read fname
	if [ -e $fname ]
	then
		echo -n"enter the roll number:"
		read roll
		grep -w "$roll" $fname
		ans=$?
		if [ $ans -eq 0 ]
		then
			echo"record alreday exist"
		else
			echo "enter name"
			read name
			echo $roll $name >> $fname
			echo "record inserted successfully"
		fi
	else
		echo"file not exist"
	fi
	;;
4)
	echo -n "enter the file name:"
	read fname
	if [ -e $fname ]
	then
		echo -n "Enter The Roll NUmber:"
		read roll
		grep -w "$roll" $fname 
		ans=$?
		if [ $ans -eq 0 ]
		then
			echo "Record Found"
		else
			echo "Record Not Found"
		fi
	else
		echo "file not exists"
	fi
	;;
5)
	echo -n "enter file name:"
	read fname
	if [ -e $fname ]
	then
		echo -n "enter roll number "
		read roll
		grep -w "$roll" $fname
		ans=$?
		if [ $ans -eq 0 ]
		then
			echo -n "Enter Newroll and Newname:"
			read nroll nname
			grep -w "$nroll" $fname
			ans=$?
			if [ $ans -eq 0 ]
			then 
				echo Record already present please try another roll no
			else
				grep -v "$roll" $fname >> temp
				echo "$nroll $nname" >> temp
			       rm $fname
		       cp temp $fname
	               rm temp
	                        echo "record successfully madified"
		       fi
	       else
		       echo "record not present"
		fi
	else
		echo"file not exists"
	fi
	;;
6)
	echo "enter the file name"
        read fname
        if [ -e $fname ]
	then
		echo -n "enter roll number"
		read roll
		grep -w "$roll" $fname
		ans=$?
		if [ $ans -eq 0 ]
		then
			grep -v "$roll" $fname >> temp
			rm $fname
		cp temp $fname
		rm temp
			echo "record successfully deleted"
		fi
	else
		echo"record not found"
	fi
	;;


7)
	exit
	;;


*)
    echo"invalid input"
    ;;
esac
done 

