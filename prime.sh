#Prime Numbers 
echo Enter number
read n
m=`expr $n / 2`
#echo $m
if [ $n -eq 1 ]
then
  echo $n is not a prime number.
fi
i=2
#t=1
while [ $i -le $m ]
do
rem=`expr $n % $i`
  if [ $rem -eq 0 ]
  then
    echo $n is not a prime number.
    #t=0
    break
  fi
i=`expr $i + 1`
done
a=`expr $m + 1`
if [ $i -eq $a ]
then 
  echo $n is a prime number.
fi
