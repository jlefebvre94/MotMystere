#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

string melangerLettres(string mot); //Declaration fonction de melange de lettre
string choixMotDico(); // recherche un mot dans le dico



int main() {
	

	
	/* ***** Demande du mot mystere *****

	1 - affichage du titre
	2 - Demande de saisie et recuperation dans la variable mot mystere

	***** ***** ***** ***** ***** ***** */
	bool continuer(true);
	string motMystere("MYSTERE");						// Variable contenant le mot mystere
	srand(time(0));										// initialisation du random
	cout << "LE MOT MYSTERE" << endl << endl;			// titre du jeu
	
	do {
		//cout << "Saisissez un mot : " << endl; 
		//cin >> motMystere;

		cout << "Choix d'un mot au hasard, veuillez patienter.." << endl;
		motMystere = choixMotDico();
	
	
	
		/* ***** Melange de lettre ****

		Le retour de la fonction melangerLettre est affecte a la variable motMelange

		***** ***** ***** ***** ***** *****  */
		string motMelange = melangerLettres(motMystere);	//fonction de melange de lettre




		/* ***** Boucle de demande de jeu ***** 

		boucle tant que le mot proposé est different du mot mystere
		affiche le nombre d'essais restant
		affiche bravo si la reponse est trouve
		ou que ce n'est pas le mot si la reponse est fausse


		***** **** ***** ***** ***** ***** */
		string motPropose;						// variable du mot que propose le joueur
		int compteur(5);									// variable pour compter les essais

		while (motPropose != motMystere)
		{
			cout << "Il te reste " << compteur << " essais." << endl;
			cout << "Quel est ce mot ? " << motMelange << endl;
			cin >> motPropose;
			//string motEntre;
			//cin >> motEntre;
			//motPropose = toupper(motEntre);
			if (motPropose == motMystere) 
			{
				cout << "Bravo ! " << endl << endl;
			}
			else
			{
				cout << "Ca n'est pas le mot ! " << endl << endl;
				compteur--;
				//cout << " test : " << compteur;
				if(compteur == 0)
				{
					cout << "Tu as perdu !" << endl;
					cout << "Le mot etait : " << motMystere << endl;
					break;
				}
			}
		}

		// proposition du continuer
		cout << "Voulez vous continuer ? (O/N)" << endl;	//question 
		char reponseContinuer('N');							// variable stocker la reponse
		cin >> reponseContinuer;
		//traitement de la reponse a continuer
		if(reponseContinuer == 'O' || reponseContinuer == 'o')
		{
			continuer = true;								// si O, on reste
		}
		else if(reponseContinuer == 'N' || reponseContinuer == 'n') {
			continuer = false;								//si N on remerci et on sort
			cout << "Merci d'avoir jouer avec nous et a bientot !" << endl;
		}
		else { 
			cout << "Nous n'avons pas compris la reponse... Nous quittons donc le programme." << endl;
			continuer = false;								// si la reponse est autre que O ou N on quitte quand meme
		}

	} while (continuer);

	system("PAUSE");								// permet de garder la console ouverte
	return 0;
}


/* 

FONCTION POUR MELANGER LES LETTRES DU MOT MYSTERE

la fonction recoit en parametre une chaine de caractère dans la variable mot

tirage d'un nombre au hazard entre 0 et la taille de la chaine de caractere mot 
puis affectation de celui ci dans la variable position

ajout de la lettre tiré au sort (situé sur l'index position) dans la variable result
puis suppression de cette meme lettre du mot en reutilisant la position.

la fonction retourne une version melangé de la chaine de caratere mot


*/
string melangerLettres(string mot)
{
	string result;								// initialisation de la variable pour contenir le mot melange

	//boucle sur le mot d'un nombre de tour egal au nombre de caractère du mot
	while (mot.size() > 0)
	{
		int position = rand() % mot.size();		//tire au sort une position dans le mot
		result += mot[position];				// ajout du caractère tire au sort a la variable de resultat
		mot.erase(position, 1);					//effacement du caractère dans le mot
	}
	return result;								//retour du mot melange
}


/*
FONCTION POUR CHOISIR UN MOT AU HASARD DANS LE FICHIER DICO.TXT




*/

string choixMotDico()
{
	ifstream monDico("dico.txt");
	string motChoisit;

	if (monDico)
	{
		vector<string> tableauDico;
		string tamponMot;
		while (getline(monDico, tamponMot))
		{
			tableauDico.push_back(tamponMot);
					
		}
		int position = rand() % tableauDico.size();		//tire au sort une position dans le mot
		motChoisit = tableauDico[position];
	}
	else {

		cout << "Probleme de chargement du fichier !! " << endl;
	}
	return motChoisit;
}


/*  RESTE A FAIRE / RESTE A FAIRE / RESTE A FAIRE / RESTE A FAIRE / RESTE A FAIRE / RESTE A FAIRE


	- score moyen du joueur 
		- enregister dans un fichier le joueur et le score moyen
		- affcihe joueur - score moyen - nbr de partie


*/