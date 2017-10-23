def fibonacci_modified(A,B,N):
	fibonacci_modified_array=dict();
	fibonacci_modified_array[0]=A;
	fibonacci_modified_array[1]=B;

	for x in range(2,N):
		fibonacci_modified_array[x]=(fibonacci_modified_array[x-1])**2+fibonacci_modified_array[x-2];

	# fibonacci_modified_array.append(A);
	# fibonacci_modified_array.append(B);
	print (fibonacci_modified_array[N-1]);



A,B,N=raw_input().split(' ');
A=int(A);
B=int(B);
N=int(N);
fibonacci_modified(A,B,N);
