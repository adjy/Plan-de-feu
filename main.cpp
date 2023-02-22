/*
Adjy Sedar DESIR
ULCO 2022
Tp4 - Plan de feu
*/
#include <iostream>
using namespace std;
const int NB_PROJECTEURS_MAX =50; // La valeur maximale des projecteurs
const int NB_PLAN_DE_FEU_MAX =100; // La valeur maximale du plan de feu

struct Projecteur{ 
	int puissance;
	string couleur;
};

struct ListeProjecteurs{
	Projecteur TableauProjecteur[NB_PROJECTEURS_MAX];
	int nbProj=0;
};

struct Sequence{
	int numProj, attente;
	float duree, pourcentage;

};

struct PlanDeFeu{
	Sequence tableuPlanDeFeu[NB_PLAN_DE_FEU_MAX];
	int nbSeq=0;
};

int choixMenu();
Projecteur saisirUnProjecteur(Projecteur proj);
ListeProjecteurs saisirLesProjecteurs(ListeProjecteurs lp);
void afficherProjecteurs(ListeProjecteurs lp);
Sequence saisirUneSequence(Sequence seq, int nbrProj);
PlanDeFeu saisirLesSequences(PlanDeFeu pf, int nbrProj);
float calculerConsoTotale(PlanDeFeu pf, ListeProjecteurs lp);
void afficherPlan(PlanDeFeu pf, ListeProjecteurs lp);


int main() {

	bool Partie = true;
	ListeProjecteurs ListeP;
	PlanDeFeu Plandefeu;
	int nbrProj;

	while(Partie){
		

		switch(choixMenu()){
			case 1:
				ListeP= saisirLesProjecteurs(ListeP); //saisir/completer les projecteurs
				break;

			case 2:
				afficherProjecteurs(ListeP); //afficher les projecteurs
				break;

			case 3:
				nbrProj = ListeP.nbProj;
				Plandefeu = saisirLesSequences(Plandefeu, nbrProj); //saisir/completer les sÚquences d’allumage des projecteurs
				break;
			
			case 4:	
				afficherPlan(Plandefeu, ListeP); //afficher le plan de feu
				break;

			case 5:
				ListeP.nbProj=0;
				Plandefeu.nbSeq=0; //effacer les projecteurs et les sequences
				break;
			
			default:
				cout<<"Au revoir!";
				Partie = false; //quitter
				break;
		}

	} 
	
}
/*------------------------------------------------ Mes Fonctios ------------------------------------------------*/

int choixMenu(){
	/*Fonction qui permettra l’affichage d’un menu à plusieurs options 
	et la saisie du numéro de l’option choisie dans le paramètre choix
	Parametre attendu: Pas de Parametre
	Valeur de retour nbr: entier*/
	int nbr;
	cout<<"Menu: \n";
	cout<<"=======\n";
	cout<<"\tchoix 1 : saisir/completer les projecteurs\n";
	cout<<"\tchoix 2 : afficher les projecteurs\n";
	cout<<"\tchoix 3 : saisir/completer les sequences d’allumage des projecteurs\n";
	cout<<"\tchoix 4 : afficher le plan de feu\n";
	cout<<"\tchoix 5 : effacer les projecteurs et les sequences\n";
	cout<<"\tchoix 0 : quitter\n\n";
	
	cout<<"\tEntrer votre choix : ";
	cin>>nbr;

	while((nbr<0) || (nbr>5)){  //Verifie si la saisie entrer est entre 0 et 5 
		cout<<"\tErreur: "<<endl;
		cout<<"\tEntrer votre choix : ";
		cin>>nbr;
	}
	cout<<endl;
	return nbr;
}


Projecteur saisirUnProjecteur(Projecteur proj){
	/*Fonction qui permet la saisie des caractéristiques d’un projecteur
	Parametre attendu: proj: Projecteur
	Valeur de retour: proj: Projecteur*/
	cout<<"Couleur ? ";
	cin>>proj.couleur;

	cout<<"Puissance ? ";
	cin>>proj.puissance;

	return proj;
}
 

ListeProjecteurs saisirLesProjecteurs(ListeProjecteurs lp){
	/*Fonction  qui permet la saisie des caractéristiques d’un certain nombre de projecteurs
	Parametre attendu: lp: ListeProjecteurs
	Valeur de retour lp: ListeProjecteurs*/
	int nbrProj;
	Projecteur Proj;

	cout<<"Nombre de projecteurs? ";
	cin>>nbrProj;

	while( (nbrProj<0) || ( (nbrProj+lp.nbProj) > NB_PROJECTEURS_MAX) ){ //Verifie que le nombre de projecteurs est entre 0 et la valeur maximale
	cout<<"Nombre de projecteurs? ";
	cin>>nbrProj;
	}
	cout<<endl;

	for(int i=lp.nbProj;i< nbrProj +lp.nbProj  ;i++){		
		cout<<"Projecteur "<<i+1 <<endl; 
		lp.TableauProjecteur[i]=saisirUnProjecteur(Proj); // Permet de completer les projecteurs a partir du tableau des anciens 
		cout<<endl;
	}
	lp.nbProj+=nbrProj; //Modifier le nbres de Projecteurs 
	return lp;
}

void afficherProjecteurs(ListeProjecteurs lp){
	/*Fonction qui liste les projecteurs.
	  Parametre attendu: lp: ListeProjecteurs
		Valeur de retour: pas de valeur 
	*/

	cout<<"Projecteurs "<<endl;

	if (lp.nbProj!=0){ //Verifie si le nbres de projecteurs est different de 0
		for(int i=0; i<lp.nbProj;i++){
			cout<<"Proj "<<i+1<<": "<<lp.TableauProjecteur[i].puissance<<" Wh "<<lp.TableauProjecteur[i].couleur<<endl;		
		}
	}
	
	cout<<"Total: "<<lp.nbProj<<" projecteurs"<<endl;
	cout<<endl;
}


Sequence saisirUneSequence(Sequence seq, int nbrProj){
	/*Fonction permet la saisie des caractéristiques d’une séquence 
	Parametre attendu: seq :Sequence, nbrProj: int
	Valeur retour: seq :Sequence */ 
	cout<<"projecteur ?";
	cin>>seq.numProj;
		
	while( (seq.numProj<0) || (seq.numProj>=nbrProj) ){ //Verifie que le numero de projecteur existe, si le numero entre est inferieur au nbr de projecteur
		cout<<"projecteur ?";
		cin>>seq.numProj;
	}

		cout<<"duree ? ";
		cin>>seq.duree;

		cout<<"pourcentage puissance ?";
		cin>>seq.pourcentage;
		
		cout<<"attente? ";
		cin>>seq.attente;
	
	return seq;
}

PlanDeFeu saisirLesSequences(PlanDeFeu pf, int nbrProj){
	/*Fonction  qui permet la saisie des informations relatives aux séquences du plan de feu
	Parametre attendu:  pf :PlanDeFeu, nbrProj : int
	Valeur de retour pf : PlanDeFeu */

	int nbrSeq;
	Sequence seq;

	cout<<"Entrer le nombre de sequences? ";
	cin>>nbrSeq;

	while( (nbrSeq<0) || ( (nbrSeq+pf.nbSeq) > NB_PLAN_DE_FEU_MAX) ){ // Verifie si le nbre de sequence est inferieur a la valeur maximal
		cout<<"Entrer le nombre de sequences? ";
		cin>>nbrSeq;
	}

	for(int i = pf.nbSeq; i< pf.nbSeq + nbrSeq; i++){
		cout<<"Sequence "<<i+1<<endl;
		pf.tableuPlanDeFeu[i]=saisirUneSequence(seq,nbrProj); // Permet de completer la sequence a partir du tableau des anciens
		cout<<endl;
	}
	pf.nbSeq+=nbrSeq; //modifie le nombre de sequences
	return pf;
}

float calculerConsoTotale(PlanDeFeu pf, ListeProjecteurs lp){
	/*Fonction  qui permettra le calcul de la consommation totale du plan de feu 
	Parametre attendu: pf :PlanDuFeu, lp : ListeProjecteurs
	Valeur de retour somme: float */
	float somme=0;
	for(int i=0; i<pf.nbSeq;i++){

		float di = pf.tableuPlanDeFeu[i].duree; //durée d’allumage d’un projecteur dans la séquence
		int numeroProjecteur = pf.tableuPlanDeFeu[i].numProj; // numero du projecteur dans la sequence
		float pi = lp.TableauProjecteur[numeroProjecteur].puissance; //puissance du projecteur (numero du projecteur) utilisé dans la séquence
		float ti =pf.tableuPlanDeFeu[i].pourcentage; // pourcentage de puissance du projecteur utilisé dans la séquence

		somme+= ( di * pi *ti )/3600.0;
	}
	return somme;
}

void afficherPlan(PlanDeFeu pf, ListeProjecteurs lp){
	/*Fonction qui affiche le détail du plan de feu et sa consommation totale.
	Parametre attendu: pf: PlanDeFeu, lp: ListeProjecteurs
	Valeur de retour : Pas de valeur*/
	cout<<"Plan de feu\n";

	if(pf.nbSeq!=0){ // Verifie si le nombre se sequence est different de 0
		for(int i=0; i<pf.nbSeq;i++){
			
			int numeroProjecteur = pf.tableuPlanDeFeu[i].numProj; // Numero du projecteuer
			string couleurProjecteur = lp.TableauProjecteur[numeroProjecteur].couleur; //Couleur du projecteur
			float puissanceProjecteur = lp.TableauProjecteur[numeroProjecteur].puissance; //Puissance du projecteur
			float pourcentageSequence= pf.tableuPlanDeFeu[i].pourcentage; //Pourcentage de la sequence
			float dureeSequence =pf.tableuPlanDeFeu[i].duree; // Duree de la sequence
			float attenteSequence = pf.tableuPlanDeFeu[i].attente; // Attente de la sequence
			
			cout<<"seq."<<i;
			cout<<" proj."<<numeroProjecteur<<" ";
			cout<< couleurProjecteur<<", "<<puissanceProjecteur<<"Wh x ";
			cout<<pourcentageSequence<<", "<< dureeSequence<<" sec.";
			cout<<" attente "<<attenteSequence<<" sec"<<endl;
		}
		
	}
	
	cout<<"Total "<<calculerConsoTotale( pf,  lp)<<" Wh"<<endl;
}
