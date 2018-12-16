
// GENERIC QUICKSORT

void quicksort( type_qs *array, int start, int end, int (*f_qs)(type_qs, type_qs) ){
 	
 	/*
	define your type data like "type_qs"
	send end = size - 1

	int FUNCTION type_qs type_qs
		return 1 | it puts in left
		rerturn -1 | it puts at right
		return 0 | if it's equal
	*/

	if ( end - start < 1 ) return;
	else{

		int middle = (start + end)/2;
		int a = start, b = end;
		type_qs pivot = array[middle];

		while(a <= b){

			while( (*f_qs)(array[a], pivot) == 1 && a < end) a++;
			while( (*f_qs)(array[b], pivot) == -1 && start < b) b--;
			if( a <= b ){
				type_qs aux = array[a];
				array[a] = array[b];
				array[b] = aux;

				a++; b--;
			}
		}

		quicksort(array, start, b, f_qs);
		quicksort(array, a, end, f_qs);

	}

}