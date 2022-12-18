echo $1 $2 $3
t1=0.0
t2=0.0
p1=0
p2=0
max1=0
max2=0
min1=1000
min2=1000
for n in 1000 10000 50000 100000 150000 250000 500000 750000 1000000
do
	t1=0.0
        t2=0.0
        max1=0
        max2=0
        min1=1000
        min2=1000

	for ((i=1;i<=$3;i++))
	do
		p1=$(./$1 $n)
		p2=$(./$2 $n)
		#echo "Tiempo $1-->$p1"
		#echo "Tiempo $2-->$p2"

		t1=$(tr ',' '.' <<< "$t1 + $p1" | bc -l)
		t2=$(tr ',' '.' <<< "$t2 + $p2" | bc -l)

		if (( $(echo "$p1 > $max1" |bc -l) ));then
			max1=$(tr ',' '.' <<< "$p1" | bc -l)

		fi

		if (( $(echo "$p2 > $max2" |bc -l) )); then
                	max2=$(tr ',' '.' <<< "$p2" | bc -l)

        	fi

		if (( $(echo "$p1 < $min1" |bc -l) )); then
                	min1=$(tr ',' '.' <<< "$p1" | bc -l)

        	fi

		if (( $(echo "$p2 < $min2" |bc -l) )); then
                	min2=$(tr ',' '.' <<< "$p2" | bc -l)

        	fi
	done
	#echo ""
	#echo "==============================="
	t1=$(tr ',' '.' <<< "$t1 / $3" | bc -l)
	t2=$(tr ',' '.' <<< "$t2 / $3" | bc -l)

	#echo "Tiempo Total $1-->$t1"
	#echo "Tiempo Total $2-->$t2"

	#echo "==============================="
	#echo ""

	echo "==============================="
	echo "RESULTADOS N= $n:"
	echo "-------------------------------"
	echo "$t1"
	echo "$max1"
	echo "$min1"
	echo "$t2"
	echo "$max2"
	echo "$min2"

done
