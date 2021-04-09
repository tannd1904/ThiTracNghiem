#include<iostream>
#include<string.h>
#include "struct.h"
#include<fstream>
#include "mylib.h"
#include "function.h"
using namespace std;



int main()
{
	int arr1[4999];
	int arr2[4999];
	taoMangRd(arr1,1,4999);
	taoMangRd(arr2,5001,9999);
	dssv ds;
	dslop dsl;
	DSMH dsm;
	NODECH dsch;
	Initialize(dsch);
	
	mainProcess(dsl,ds,dsm,dsch,arr1,arr2);
	
	return 0;
}
