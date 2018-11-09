#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int nIng = 2;
#define nCapas 2
#define nSal 1
//#define nEntr 5

int vecesEntr = 1;

/*float ing[][nIng];/*={	{0,0,0},
					{0,1,1},
					{1,0,1},
					{1,1,0},
					{0,0,1}};*/
							
/*float sal[][nSal];/*={	{1},
					{1},
					{0},
					{1},
					{0}};*/

int capas[nCapas] = {5,5};

int c[nCapas+2];
float *y,*s,*g,*w;

float getRandom();
void entrenar(int,float[][nIng],float[][nSal]);
void main(int *pnIng,int *pnEntr,double *RIng,double RSal[]){
	nIng = *pnIng;
	int nEntr = *pnEntr;
	printf("%d\n",nEntr);
	if(nIng==0||nCapas==0||nSal==0||nEntr==0)
		exit(1);
	
	int v,i,j;
	float ing[nEntr][nIng];
	float sal[nEntr][nSal];
	for(i=0;i<nEntr;i++){
		for(j=0;j<nIng;j++){
			ing[i][j]=RIng[i*nIng+j];
			//printf("%f\t",(float)RIng[i][j]);
		}
		//puts("");
		sal[i][0] = RSal[i];
	}
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
	
	srand((int)time(NULL));
	for(i = 0;i < n2;i++)
		w[i] = -1+2*getRandom();
	
	for (v = 0;v < vecesEntr;v++)
		for (i = 0; i < nEntr; i++)
			entrenar(i,ing,sal);
			
	FILE *file;
	//file = fopen("/home/gabrielvicente/Documentos/C/rnW.txt","w");
	file = fopen("rnW.txt","w");

	if(file == NULL)
	  exit(1);
	  
	fprintf(file,"%d %d %d\n",nIng,nCapas,nSal);
	for(i=0;i<nCapas;i++)
		fprintf(file,"%d ",capas[i]);
		
	for(i=0;i<n2;i++)
		fprintf(file,"\n%f",w[i]);

	fclose(file);
	free(y);
	free(s);
	free(g);
	free(w);
			
}
float getRandom(){
	return ((float)rand())/RAND_MAX;
}
float fun(float f){
	return 1/(1+exp(-f));
}
void entrenar(int ci,float ing[][nIng],float sal[][nSal]){
	int ii=0,n;
	float pls=0;
	int i,j,k;
	//ida
	for(i=0;i<c[1];i++){
		for(j = 0;j<c[0];j++){
			pls+=w[ii]*ing[ci][j];
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
	//Vuelta
	n = 0;
	for(i = 1;i<=nCapas;i++)
		n+=c[i];
	for(j = 0;j<c[nCapas+1];j++){//Última capa
		g[j+n] = (sal[ci][j]-y[j+n])*y[j+n]*(1-y[j+n]);
	}
	for(i = nCapas;i>0;i--){
		pls = 0;
		ii = 0;
		n = 0;
		for(j=1;j<i;j++)
			ii+=c[j-1]*c[j];
		for(j=1;j<i;j++)
				n+=c[j];
		for(j=0;j<c[i];j++){
			for(k=0;k<c[i+1];k++)
				pls+=w[ii+k*c[i]+j]*g[n+c[i]+k];
			g[j+n]=y[j+n]*(1-y[j+n])*pls;
			pls = 0;
		}
	}
	for(i=nCapas+1;i>1;i--){
		pls = 0;
		ii = 0;
		n = 0;
		for(j=1;j<i;j++)
			ii+=c[j-1]*c[j];
		for(j=1;j<i;j++)
				n+=c[j];
		for(j=0;j<c[i];j++)
			for(k=0;k<c[i-1];k++){
				w[ii]+=g[j+n]*y[k+n-c[i-1]];
				ii++;
			}
	}
	ii=0;
	for(j=0;j<c[1];j++)
		for(k=0;k<c[0];k++){
			w[ii]+=g[j]*ing[ci][k];
			ii++;
		}
}












