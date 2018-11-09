#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int nIng,nCapas,nSal,*capas;

float *ing;

int *c;
float *y,*s,*g,*w;

float fun(float f){
	return 1/(1+exp(-f));
}
void main(){
	FILE *file;

	if ((file = fopen("rnW.txt","r")) == NULL)
		exit(1);
	fscanf(file,"%d %d %d",&nIng,&nCapas,&nSal);
	
	int i,j,k;
	capas = (int*)malloc(sizeof(int)*nCapas);
	for(i=0;i<nCapas;i++)
		fscanf(file,"%d",capas+i);
	
	c = (int*)malloc(sizeof(int)*(nCapas+2));
	c[0] = nIng;
	for(i = 0;i < nCapas;i++)
		c[i+1] = capas[i];
	c[nCapas+1] = nSal;
	
	int n1 = 0,n2 = 0;
	
	for (i = 1;i < nCapas+2;i++){
		n1+= c[i];
		n2+= c[i-1]*c[i];
	}
	y = (float*) malloc(sizeof(float)*n1);
	s = (float*) malloc(sizeof(float)*n1);
	g = (float*) malloc(sizeof(float)*n1);
	w = (float*) malloc(sizeof(float)*n2);
	
	for(i = 0;i < n1;i++){
		y[i] = 0;
		s[i] = 0;
		g[i] = 0;
	}
	for(i = 0;i < n2;i++)
		fscanf(file,"%f",w+i);
	
	fclose(file);
	
	ing = (float*)malloc(sizeof(float)*nIng);
	
	for(i=0;i<nIng;i++)
		scanf("%f",ing+i);
	
	int ii=0,n;
	float pls=0;
	
	for(i=0;i<c[1];i++){
		for(j = 0;j<c[0];j++){
			pls+=w[ii]*ing[j];
			ii++;
		}
		s[i] = pls;
		y[i] = fun(pls);
		pls = 0;
	}
	for(i=2;i<=nCapas+1;i++){
		pls = 0;
		ii = 0;
		for(j=1;j<i;j++)
			ii+=c[j-1]*c[j];
		n = 0;
		for(k=1;k<i;k++)
				n+=c[k];
		for(j=0;j<c[i];j++){
			for(k=0;k<c[i-1];k++){
				pls+=w[ii]*y[k+n-c[i-1]];
				ii++;
			}
			s[j+n] = pls;
			y[j+n] = fun(pls);
			pls=0;
		}		
	}
	for(i = n; i < n+c[nCapas+1]; i++)
		printf("\n%f",y[i]);
	puts("\n");
}
	
















