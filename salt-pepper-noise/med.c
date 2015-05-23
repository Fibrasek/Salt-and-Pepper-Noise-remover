int mediana_quick(int org[9]) {

    quicksort(org, org[0], 9);

    if(org[4] == 0){
        return org[3];
    } else if(org[4] == 255){
	return org[5];
    }

    return org[4];
}
