# Data-Structure-HW1
read a natual number n, create two arrays of n real numbers, say, A & B
ask the user to input n real numbers, store these numbers into A
printout the entire mxn array A by a function printout_array(A,m,n)
(obviuosly, m=1 in this assignment. However, since this function will be used again for some future assignments, I suggest you to implement an mxn version rather than a 1xn version.)
copy the entire mxn array A to another mxn array B by a function duplicate_array(A,B,m,n)
(obviously, m=1 in this assignment. However, since this function will be used again for some future assignments, I suggest you to implement an mxn version rather than a 1xn version.)
write a function ins_sort(A,...) which sorts those n integers in A by insertion sort
(here I use (A,...) to denote the arguments of the function. you may use whatever arguments you like for this function)
printout the sorted array A by printout_array(A,1,n). (!Note!, DO NOT use printout_array(A,1,n) inside the function ins_sort(...). You HAVE TO use printout_array(A,1,n) in the main function)
check your results by a function is_ascending(A,n) which printouts "Great!! It is in ascending order!!" if A[i]<=A[j] for any i<=j, or otherwise printouts "Warning!! the order is NOT ascending!!"
write a function mg_sort(B,...) which sorts the duplicated n integers in B by merge sort
(here I use (B,...) to denote the arguments of the function. you may use whatever arguments you like for this function)
printout the sorted array B by printout_array(B,1,n). (!Note!, DO NOT use printout_array(B,1,n) inside the function mg_sort(...). You HAVE TO use printout_array(B,1,n) in the main function)
check your resulty using the function is_ascending(B,n) as defined above.
Example: suppose your code is named as insmg1, then when you execute insmg1, you should see:

Please input n: (then you input, say, 5, press enter)

then the program should printout:

Please input 5 real numbers: (then you input, say, -2.1 4.2 5 3 -10 press enter)

then you should see these 5 numbers appear on the screen like

-2.1, 4.2, 5, 3, -10

then you should see the sorted results which look like

By insertion sort:
-10, -2.1, 3, 4.2, 5
Great!! It is in ascending order!!
By merge sort:
-10, -2.1, 3, 4.2, 5
Great!! It is in ascending order!!
