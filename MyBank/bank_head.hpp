#ifndef __MY_BANK_HH__
#define __MY_BANK_HH__
#include <iostream>
using namespace std ;
const int tabSize = 3 ;
int i , stockIndice = 0 ;
float montant ;
bool conditionValider = false ;
char noms[tabSize][256]; // Tableau a 2 dim pour stocker les noms de 256 cases
char passwords[tabSize][256];
float montantDepot[tabSize];

void creerCompte( ) {
	char reponse ;
	int getteur ;
	bool saisieValide = true ;
	for(i = 0 ; i < tabSize; i++){
		if (saisieValide == true){
			cout<<"Entrer votre Nom: "<<endl;
			cin >>noms[i] ;
			cout<<"Entrer votre mot de passe: "<<endl;
			cin>>passwords[i];
		}
		while (saisieValide) {
			cout<<"Voulez-vous encore creer un compte ? (o/n)"<<endl;
			cin>> reponse;	
			if (reponse == 'o' || reponse == 'O') {
				if (i < tabSize - 1) { // -1 ici car je stocke les noms dans la case suivante (i+1)
					cout << "Entrer votre Nom : " << endl;
					cin >> noms[i + 1];
					cout<<"Entrer votre mot de passe: "<<endl;
			        cin>>passwords[i + 1];
					i++; // Pour passer au prochain emplacement du tableau
				} 
				else {
					cout << "Le server est saturer, impossible de creer plus de comptes." << endl;
					saisieValide = false ;
				}
			} 
			else if (reponse == 'n' || reponse == 'N') {
				getteur = 1 ; // pour getter afin d'arreter la boucle for ou pas
				break; //arret de la boucle while 
			} 
			else if (reponse != 'o' || reponse != 'O'|| reponse != 'n' || reponse != 'N') {
				cout << "Reponse invalide." << endl;	
				saisieValide = false ;	 
			}
		}

		if (getteur == 1) {
			break;
		}
    }
}
	
// Creation de la fonction solde 
void solde(){
	cout <<"Votre solde est de: "<<montantDepot[stockIndice]<<endl ;
}
 
// Creation de la fonction de verification 
void verificationCompte (){
    char compteName[256];
	char passwordEnter[256];
	bool verification = true ;
    while(verification){
		cout<<"Veuillez entrer le nom de compte: "<<endl ;
		cin>>compteName;
		cout<<"Veuillez entrer le mot de passe du compte: "<<endl ;
		cin>> passwordEnter;
		for(i = 0 ; i < tabSize ;i++){
			/* En C++, la fonction strcmp permet de comparer deux chaine de charactères 
			si les deux sont égales, la fonction nous retourne un 0*/
			if(strcmp(compteName,noms[i]) == 0 && strcmp(passwordEnter,passwords[i])== 0){
				stockIndice = i ;
				verification = false ; 
				conditionValider = true ;
				cout<<"les informations sont valides."<<endl;
				break ;
			}
		}
		if(verification == true) {
			cout<<"Votre nom de compte ou votre de passe est erroner ."<<endl;
		}
		
    }
}
// J'utilise des variables globales pour liés mes fonctions entre elles
// Creation de la fonction depot 
void depot(){
	char reponse ;
	float montantStock = 0 ;
	bool verif = true  ;
	while(verif){
		cout<<"Veuiller le montant: ";
		cin>> montantDepot[stockIndice];
		cout<<"Votre depot a ete effectuer ."<<endl ;
		montantStock = montantDepot[stockIndice];
		montantStock += montantStock ;
		while(verif){
			cout<<"Voulez vous encore effectuer un depot ? (o/n)"<<endl ;
			cin >>reponse ;
			if(reponse == 'o' || reponse == 'O') break;
			else if(reponse == 'n' || reponse == 'N') verif = false ;
			else {
				cout<<"Veillez entrer une reponse correcte. "<<endl ;
			}
		}

	}
}

// Creation de la fonction retrait 
void retrait(){
	char reponse ;
	float montantRetrait ;
	bool verif = true , condition = true ;
	while(verif){
		cout<<"Veuiller entrer le montant de retrait: ";
		cin>> montantRetrait ;
		if(montantRetrait > montantDepot[stockIndice]){
			cout << "Retrait impossible. " <<endl ;
		}
		else {
			montantDepot[stockIndice] -= montantRetrait ;
		   cout<<"Votre retrait a ete effectuer ."<<endl ;
		   solde() ;
		   condition = true ;
		}
	    if (condition){
			while(verif){
				cout<<"Voulez vous encore effectuer un retrait  ? (o/n)"<<endl ;
				cin >>reponse ;
				if(reponse == 'o' || reponse == 'O') break;
				else if(reponse == 'n' || reponse == 'N') verif = false ;
				else {
					cout<<"Veillez entrer une reponse correcte. "<<endl ;
				}
			}
		}

	}
}


#endif // MACRO
