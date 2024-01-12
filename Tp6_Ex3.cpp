#include<stdio.h>
#include<string.h>
int main (){
	int t1[10],t2[10], t3[20]; //3 tableaux d'entiers
	int n1,n2,n3; //tailles des tableaux t1 et t2 et t3
	int* p1;
	int* p2;
	int* p3;
	 
	//Charger deux tableaux t1 et t2 de dimensions respectives 5=n1=10 et 5=n2=10 par des
	//entiers introduits dans un ordre croissant,
	
	//saisie de n1 par adressage indirect
	p1=&n1;
	do{
		printf("donner n1= ");
		scanf("%d",p1);
	}while((*p1<5) || (*p1>10));
	
	//charger t1 par des entiers introduits dans un ordre croissant
	p1=t1; // initialise un pointeur p1 sur le premier élément du tableau t1
	printf("donner t1[%]= ",p1-t1);
	scanf("%d",p1);
	for (p1=t1+1;p1<t1+n1;p1++){
		do{
			printf("donner t1[%d]= ",p1-t1);
			scanf("%d",p1);
		}while (*p1<*(p1-1));
		
	}
	
	//saisie de n2 par adressage indirect
	p2=&n2;
	do{
		printf("donner n2= ");
		scanf("%d",p2);
	}while((*p2<5) || (*p2>10));
	
	//charger t2 par des entiers introduits dans un ordre croissant
	p2=t2; // initialise un pointeur p2 sur le premier élément du tableau t2
	printf("donner t2[%d]= ",p2-t2);
	scanf("%d",p2);
	for (p2=t2+1;p2<t2+n2;p2++){
		do{
			printf("donner t2[%d]= ",p2-t2);
			scanf("%d",p2);
		}while (*p2<*(p2-1));	
	}
	
	//Fusionner t1 et t2 dans un troisième tableau t3 (utiliser la technique du tri-fusion)
	p1=t1;
	p2=t2;
	p3=t3;

	while ((p1<t1+n1)&&(p2<t2+n2)){
		if (*p1<*p2){
			*p3=*p1;
			p1++;
		}
		else{
			*p3=*p2;
			p2++;
		}
		p3++;
	}
	
	while(p1<t1+n1){ //si il n'y a plus des elements en t2
		*p3=*p1;
		p1++;
		p3++;
	}
	
	while(p2<t2+n2){ //si il n'y a plus des elements en t1
		*p3=*p2;
		p2++;
		p3++;
	}
	
	//Afficher les éléments de t3 dans un ordre décroissant.
	n3=n1+n2;
	for (p3=t3+n3-1;p3>=t3;p3--){
		printf("%d\n",*p3);
	}
	
	
	return 0;
}
