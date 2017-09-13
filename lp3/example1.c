int x[4] = {10,20,30,40};

int main(void){
	int *pint = x;

	*pint = 0;
	*(pint+1) = 0;
	*(pint+2) = 0;
	*(pint+3) = 0;

	char *pbyte = (char*) x;

	*pbyte = 255;
	*(pbyte+1) = 255;
	*(pbyte+2) = 255;
	*(pbyte+3) = 255;

	return 0;
}
