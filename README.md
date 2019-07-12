# push_swap
push_swap - это программа сортировки стека с огранниченным и строго определенным числом инструкций над исходным и вспомогательным стеком.  

usage:		./checker -\[i | \[s | q | b] | p | fFILE$] <numbers> <commands>
		./push_swap <numbers> <commands>
		ARG="<numbers>"; ./push_swap $ARG | ./checker $ARG
		./push_swap -fops$ $(cat <file>); ./checker -fops$ $(cat <file>)

flags:		-h	print usage
		-i	interactive checker's mode
		-s	use select sort to generate sorting commands
		-q	use quick sort to generate sorting commands
		-b	use bubble sort to generate sorting commands
		-p	print stack state
		-ffile$ to print (push_swap) or read (checker)
			sorting commands to / from file

gen:		./gen <amount of numbers> > <file>

test:		./test.sh \[-h] quick sort auto test

Реализованные сортировки: quick sort, select sort, bubble sort.  

В зависимости от входдных данных либо сразу выбирается одна сортировка, либо запускаются все и выбирается общий результат.  

Example:  

![Alt text](images/image.png?raw=true "Example") 
