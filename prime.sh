echo Enter the input Number
read n
flag=1
i=2
while [ $i -lt $n ]
do
        remainder=`expr $n % $i`
        echo divisor=$i remainder=$remainder
        if [ $remainder -eq 0 ]
        then
                flag=0
                break
        fi
        i=`expr $i + 1`
done
#lol
if [ $flag -eq 0 -o $n -eq 1 ]
then
        echo composite
else
        echo prime
fi
