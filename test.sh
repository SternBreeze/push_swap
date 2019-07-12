#!/bin/sh

if [ "$1" = "-h" ]
	then
	echo "\$1 is num of tests";
	echo "\$2 is len of stack";
	echo "\$3 time per test (rand() use current time)";
	echo "\$4 is max digits in stack (5 by default)";
	exit 1;
fi

echo "Push_swap test started";
TMPTEST="tmp_test0_o"
TMPOPS="tmp_opso_0"
var1=0;

> $TMPTEST;
> $TMPOPS;	

for (( i=0; i<$1 ; i++ ))
do
	res=0;
	echo "\nTest № $i";
	./gen $2 $4 > $TMPTEST;
	var2=$(./push_swap -f$TMPOPS$ $(cat $TMPTEST) | wc -l);
	res=$(./checker -f$TMPOPS$ $(cat $TMPTEST));
	echo $res;
	if [[  $res != "OK" && $res != 0 ]]
		then
		echo "!!! TEST NOT PASSED !!!!";
		exit 1;
	fi
	> $TMPTEST;
	> $TMPOPS;
	var1=$(($var1+$var2));
	echo "Added to calculation:";
	echo $(($var2));
if [ $3 ]
	then
		sleep $3;
	else
		sleep 0.654;
fi
done;

rm $TMPTEST;
rm $TMPOPS;
echo "Average operations:";
echo $(($var1/i));
