#ifndef MST_NUM
#define MST_NUM

int split_numofi(int m,int n,int i);/* devie m into n part,return num of i */

#ifdef MST_NUM_IMPLEMENTATION
int split_numofi(int m,int n,int i){
	if (m < n) return -1;
	if (i >= n) return -2;
	return (m / n) + (i < (m % n));
}
#endif//MST_NUM_IMPLEMENTATION
#endif//MST_NUM
