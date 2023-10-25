#include <iostream>
#include <cstring>
#include"bank_head.hpp"
 
/*Je ne peux pas faire un return d'un tableau en C++ donc je dois 
afficher le contenu du tableau dans une fonction .*/	
	
int main(){
	bool boucle = true ;
	while(boucle){
		char option ;
		cout<<"Veuiller selection une option: \n 1- CreerCompte (1)\n 2- Depot (2)\n 3- retrait (3) \n 4- consulterCompte (4)\n 5- Exist (5) \n \n";
		cout <<"==> :";
		cin >> option;
		switch (option){
		case '1':
			creerCompte();
			break;
		case '2':
		    verificationCompte();
			depot();
			break;
		case '3' :
		    verificationCompte();
			retrait();
			break ;
		case '4':
		    verificationCompte();
			solde();
			break;
		case '5' :
			boucle = false ;
			break ;
			default:
			cout<<"Veuillez chosir une option valide. \n"<<endl ;
			break;
		}
	}
 /*
    creerCompte();
	verificationCompte();
	depot();
	retrait();
	
*/
    

    return 0;	
}
