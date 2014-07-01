
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main(){
	int i;
	int j;
	
	FILE*fp;

	fp=fopen("obj.txt","w");

	for(i=11;i<15;i++){
		for(j=1;j<26,j++){
			fprintf("%d%d,",i,j);
		}
	}
	for(i=21;i<25;i++){
		for(j=1;j<26,j++){
			fprintf("%d%d,",i,j);
		}
	}
	for(i=31;i<35;i++){
		for(j=1;j<26,j++){
			fprintf("%d%d,",i,j);
		}
	}
	for(i=41;i<45;i++){
		for(j=1;j<26,j++){
			fprintf("%d%d,",i,j);
		}
	}
	for(i=51;i<55;i++){
		for(j=1;j<26,j++){
			fprintf("%d%d,",i,j);
		}
	}



	fclose(fp);

return 0;

}