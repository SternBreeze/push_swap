# push_swap
push_swap - это программа сортировки стека с огранниченным и строго определенным числом инструкций над исходным и вспомогательным стеком.  
```
usage:          ./checker -\[i | \[s | q | b] | p | fFILE$] <numbers> <commands> . 
                ./push_swap <numbers> <commands> . 
                ARG="<numbers>"; ./push_swap $ARG | ./checker $ARG . 
                ./push_swap -fops$ $(cat <file>); ./checker -fops$ $(cat <file>) . 
flags:          -h .    print usage  
                -i .    interactive checker's mode . 
                -s	use select sort to generate sorting commands . 
                -q	use quick sort to generate sorting commands . 
                -b	use bubble sort to generate sorting commands . 
                -p	print stack state . 
                -ffile$ to print (push_swap) or read (checker) . 
                        sorting commands to / from file . 
gen:             ./gen <amount of numbers> > <file> . 

test:            ./test.sh \[-h] quick sort auto test . 
```
Реализованные сортировки: quick sort, select sort, bubble sort.   

В зависимости от входдных данных либо сразу выбирается одна сортировка, либо запускаются все и выбирается общий результат.  

Commands:  

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).  
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).  
ss : sa and sb at the same time.  
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.  
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.  
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.  
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.  
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.  
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.  
rrr : rra and rrb at the same time.  

Example:  

![Alt text](images/image.png?raw=true "Example") 
