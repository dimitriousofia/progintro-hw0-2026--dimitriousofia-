#include <stdio.h>

int is_prime(unsigned long long n){ //Συναρτηση ελεγχου πρωτου αριθμου
	if (n<2 || n%2==0){
		return 0;
	}else if (n==2){
		return 1;
	}
	for (unsigned long long i=3; i*i<=n; i+=2){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(void){//void διοτι δεν πρεπει να δεχεται κανενα ορισμα
	unsigned long long n;//μεταβλητη αριθμου μεσω χρησης unsigned long long για να δεχεται μεγαλο πληθος θετικων αριθμων
	unsigned long long p;//μεταβλητη πρωτου αριθμου
	char epilogi;//μεταβλητη για επιλογη χαρακτηρα p ή g
	int apotelesma;//μεταβλητη για ελεγχους
	int apotelesma2;	
	int flag=1;//μεταβλητη για τερματισμου της επαναληψης while
	while (flag==1){//δηλαδη να συνεχιζεται το προγραμμα οσο το flag ειναι αληθες
		printf("Give me a number:");
		apotelesma=scanf("%llu", &n); //αναθετω στην μεταβλητη n τον αριθμο που εδωσε ο χρηστης
		if (apotelesma==EOF){
			printf("EOF detected, exiting\n");
			int flag=0;//εαν εντοπιστει EOF, να τερματιστει το προγραμμα
		}else if (apotelesma!=1){
			fprintf(stderr, "Invalid input: expected an integer\n");//εαν δωθει οτιδηποτε input εκτος απο ακεραιο,να μπει στο φακελο stderr
			return 1;
		}else if(n>10000000000){
			fprintf(stderr,"Number should be in the range [0,10000000000]\n");
			return 1;
		}
		printf("Choose how to test %llu - ('p' for prime, 'g' for goldbach)",n);
		apotelesma2=scanf(" %c",&epilogi);//αναθετω στην μεταβλητη epilogi τον χαρακτηρα που εδωσε ο χρηστης
		if (apotelesma2==EOF){
			printf("EOF detected,exiting\n");
			int flag=0;
			return 0;
		}
		if (epilogi!='p' && epilogi!='g'){
			fprintf(stderr,"Invalid choice: expected 'p' or 'g'\n");
			return 1;
		}
		if (epilogi=='p'){
			if (is_prime(n)==1){//εαν το return της συναρτησης που εφτιαξα παραπανω ισουται με ενα,τοτε αληθευει
				printf("%llu is prime\n",n);
			}else{
				printf("%llu is not prime\n",n);
			}
		}else{
			if (n<=2 || n%2!=0){//εαν ο αριθμος ειναι μικροτερους του δυο η περιττος
				printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
			}else{
				for (p=2; p<=n/2; p++){//ο πωρτος αριθμος ειναι δυο,ξεκιναιε απο το μισο του αριθμου n που εδωσε ο χρηστης και αυξανει το βημα ανα 1 καθε επαναληψη
					if ((is_prime(p))&&(is_prime(n-p))){//εαν αληθευει οτι ο πρωτος αριθμος ειναι πραγματι πρωτος και μπορει να αφαιρεθει απο τον n
						printf("%llu=%llu+%llu\n",n,p,n-p);
						break;
					}
				}
			}
		}

	}
return 0;
}
