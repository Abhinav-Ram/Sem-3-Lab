#define Max_Size 100

int Size(int array[]){
	int i = 0;
	while(array[i] != -100){
		i++;
	}
	return i;
}

int InsertAt(int array[], int size, int pos, int data){
	int i;
	if(pos<0 || pos > size)
		return -1;
	/*
	if(pos == size){
		array[pos]=data;
    	//array[pos+1]=-100;
	}
	else{*/
		for(i=size-1;i>=pos;i--)
			array[i+1] = array[i];
		/*array[pos] = data;	
	}
	*/
	array[pos] = data;
	size++;
	array[size] = -100;
	return size;
}

int Search(int array[], int pos, int key){
	int i,size=Size(array);
	if (pos < 0) 
		return -2;
	
	if (pos >= size) 
		return -3;
	
	for(i=pos;i<size;i++)
		if(array[i] == key)
			return i;
	return -1;
}

