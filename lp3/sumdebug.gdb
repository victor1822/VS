set width 0
set height 0
set verbose off 

b 7

commands 1
	silent
	printf "acc = %i\n",acc
	continue
end

b 9

commands 2
	silent 
	printf "acc = %i\n",acc
	continue
end

run
