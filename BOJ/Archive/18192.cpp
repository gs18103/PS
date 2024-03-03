#include "bogoSort.h"
#include<bits/stdc++.h>

using namespace std;

vector<int> x;

void sort_array(int N)
{
	int c=0;
	int last=-1;
	int n=0;
	x = copy_array();
	while(c<x.size()){
		//for(int i=0;i<x.size();i++) printf("%d ", x[i]);
		//printf("\n");
		for(int i=last+1;i<x.size();i++){
			if(x[i]==c){
				if(i==c){
					last=i;
					c++;
				}
				else{
					shuffle_array(last+1, i);
					break;
				}
			}
		}
		x = copy_array();
	}
	return;
}
