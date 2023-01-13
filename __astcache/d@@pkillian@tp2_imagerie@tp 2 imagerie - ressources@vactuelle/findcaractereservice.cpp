﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "FindCaractereService.h"
#include "C_ImageCouleur.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


extern C_ImageCouleur MonImage;

//Permet de trouver les pixels de début et de fin de caractere
string FindCaractereService::EncadrerCaractere()
{
	string limitationVitesse = "";
	//---------------------------------Premier Caractere---------------------------------
	int debutXPremierCaractere = 0, finXPremierCaractere = 0, debutYPremierCaractere = 0, finYPremierCaractere = 0;
	bool pixelNoirTrouve = false, premierPixelNoirTrouve = false;
	//Recherche segment de haut en bas du caractere (Y)
	for (int largeur = 0; largeur < MonImage.GetLargeur(); largeur++)
	{
	   if((!pixelNoirTrouve) && (premierPixelNoirTrouve))//Si le premier pixel noir a été trouve et qu'aucun pixel noir a ete trouve dans la derniere colonne
	   {
		   finXPremierCaractere = largeur - 1;
		   break;
	   }

	   pixelNoirTrouve = false;
	   for (int hauteur = 0; hauteur < MonImage.GetHauteur(); hauteur++)//On commence en haut a gauche de l'image
		{
			if((MonImage.GetPixelRVB(largeur, hauteur) <= 10) && (!premierPixelNoirTrouve))//Si le pixel est noir et que le premier pixel noir n'a pas été trouvé
			{

				debutXPremierCaractere = largeur;
				premierPixelNoirTrouve = true;
				pixelNoirTrouve = true;

			}
			else
			{
				if(MonImage.GetPixelRVB(largeur, hauteur) <= 10)//Si le pixel est noir
				{
				   pixelNoirTrouve = true;
				}
			}
		}
	}

	pixelNoirTrouve = false;
	premierPixelNoirTrouve = false;

	for (int hauteur = 0; hauteur < MonImage.GetHauteur(); hauteur++)
	{
		if((!pixelNoirTrouve) && (premierPixelNoirTrouve))//Si le premier pixel noir a été trouve et qu'aucun pixel noir a ete trouve dans la derniere colonne
		{
		   finYPremierCaractere = hauteur - 1;
		   break;
		}

       pixelNoirTrouve = false;
	   for (int largeur = 0; largeur < finXPremierCaractere; largeur++)
		{
			if((MonImage.GetPixelRVB(largeur, hauteur) <= 10) && (!premierPixelNoirTrouve))//Si le pixel est noir et que le premier pixel noir n'a pas été trouvé
			{

				debutYPremierCaractere = hauteur;
				premierPixelNoirTrouve = true;
				pixelNoirTrouve = true;

			}
			else
			{
				if(MonImage.GetPixelRVB(largeur, hauteur) <= 10)//Si le pixel est noir
				{
				   pixelNoirTrouve = true;
				}
			}
		}
	}

	if((debutYPremierCaractere != finYPremierCaractere)&&(finYPremierCaractere != debutYPremierCaractere + 1))
	{
		limitationVitesse = limitationVitesse + FindCaractere(debutXPremierCaractere, finXPremierCaractere, debutYPremierCaractere, finYPremierCaractere);
	}

	//---------------------------------Second Caractere---------------------------------
	int debutXSecondCaractere = 0, finXSecondCaractere = 0, debutYSecondCaractere = 0, finYSecondCaractere = 0;
	pixelNoirTrouve = false, premierPixelNoirTrouve = false;
	//Recherche segment de haut en bas du caractere (Y)
	for (int largeur = finXPremierCaractere; largeur < MonImage.GetLargeur(); largeur++)
	{
	   if((!pixelNoirTrouve) && (premierPixelNoirTrouve))//Si le premier pixel noir a été trouve et qu'aucun pixel noir a ete trouve dans la derniere colonne
	   {
		   finXSecondCaractere = largeur - 1;
		   break;
	   }

	   pixelNoirTrouve = false;
	   for (int hauteur = 0; hauteur < MonImage.GetHauteur(); hauteur++)//On commence en haut a gauche de l'image
		{
			if((MonImage.GetPixelRVB(largeur, hauteur) <= 10) && (!premierPixelNoirTrouve))//Si le pixel est noir et que le premier pixel noir n'a pas été trouvé
			{
				debutXSecondCaractere = largeur;
				premierPixelNoirTrouve = true;
				pixelNoirTrouve = true;
			}
			else
			{
				if(MonImage.GetPixelRVB(largeur, hauteur) <= 10)//Si le pixel est noir
				{
				   pixelNoirTrouve = true;
				}
			}
		}
	}

	pixelNoirTrouve = false;
	premierPixelNoirTrouve = false;

	for (int hauteur = 0; hauteur < MonImage.GetHauteur(); hauteur++)
	{
		if((!pixelNoirTrouve) && (premierPixelNoirTrouve))//Si le premier pixel noir a été trouve et qu'aucun pixel noir a ete trouve dans la derniere colonne
		{
		   finYSecondCaractere = hauteur - 1;
		   break;
		}

	   pixelNoirTrouve = false;
	   for (int largeur = finXPremierCaractere; largeur < finXSecondCaractere; largeur++)
		{
			if((MonImage.GetPixelRVB(largeur, hauteur) <= 10) && (!premierPixelNoirTrouve))//Si le pixel est noir et que le premier pixel noir n'a pas été trouvé
			{

				debutYSecondCaractere = hauteur;
				premierPixelNoirTrouve = true;
				pixelNoirTrouve = true;

			}
			else
			{
				if(MonImage.GetPixelRVB(largeur, hauteur) <= 10)//Si le pixel est noir
				{
				   pixelNoirTrouve = true;
				}
			}
		}
	}

	if(debutYSecondCaractere != finYSecondCaractere)
	{
		limitationVitesse = limitationVitesse + FindCaractere(debutXSecondCaractere, finXSecondCaractere, debutYSecondCaractere, finYSecondCaractere);
		//---------------------------------Troisieme Caractere---------------------------------
		int debutXTroisiemeCaractere = 0, finXTroisiemeCaractere = 0, debutYTroisiemeCaractere = 0, finYTroisiemeCaractere = 0;
		pixelNoirTrouve = false, premierPixelNoirTrouve = false;
		//Recherche segment de haut en bas du caractere (Y)
		for (int largeur = finXSecondCaractere; largeur < MonImage.GetLargeur(); largeur++)
		{
		   if((!pixelNoirTrouve) && (premierPixelNoirTrouve))//Si le premier pixel noir a été trouve et qu'aucun pixel noir a ete trouve dans la derniere colonne
		   {
			   finXTroisiemeCaractere = largeur - 1;
			   break;
		   }

		   pixelNoirTrouve = false;
		   for (int hauteur = 0; hauteur < MonImage.GetHauteur(); hauteur++)//On commence en haut a gauche de l'image
			{
				if((MonImage.GetPixelRVB(largeur, hauteur) <= 10) && (!premierPixelNoirTrouve))//Si le pixel est noir et que le premier pixel noir n'a pas été trouvé
				{

					debutXTroisiemeCaractere = largeur;
					premierPixelNoirTrouve = true;
					pixelNoirTrouve = true;

				}
				else
				{
					if(MonImage.GetPixelRVB(largeur, hauteur) <= 10)//Si le pixel est noir
					{
					   pixelNoirTrouve = true;
					}
				}
			}
		}

		pixelNoirTrouve = false;
		premierPixelNoirTrouve = false;

		for (int hauteur = 0; hauteur < MonImage.GetHauteur(); hauteur++)
		{
			if((!pixelNoirTrouve) && (premierPixelNoirTrouve))//Si le premier pixel noir a été trouve et qu'aucun pixel noir a ete trouve dans la derniere colonne
			{
			   finYTroisiemeCaractere = hauteur - 1;
			   break;
			}

		   pixelNoirTrouve = false;
		   for (int largeur = finXSecondCaractere; largeur < finXTroisiemeCaractere; largeur++)
			{
				if((MonImage.GetPixelRVB(largeur, hauteur) <= 10) && (!premierPixelNoirTrouve))//Si le pixel est noir et que le premier pixel noir n'a pas été trouvé
				{

					debutYTroisiemeCaractere = hauteur;
					premierPixelNoirTrouve = true;
					pixelNoirTrouve = true;

				}
				else
				{
					if(MonImage.GetPixelRVB(largeur, hauteur) <= 10)//Si le pixel est noir
					{
					   pixelNoirTrouve = true;
					}
				}
			}
		}

		if((debutYTroisiemeCaractere != finYTroisiemeCaractere)&&(finYTroisiemeCaractere != debutYTroisiemeCaractere + 1))
		{
			limitationVitesse = limitationVitesse + FindCaractere(debutXTroisiemeCaractere, finXTroisiemeCaractere, debutYTroisiemeCaractere, finYTroisiemeCaractere);
		}
	}

	/*int sizeTabLimitationVitesse = sizeof(limitationVitesse) / sizeof(char);
	std::string limitationVitesseResult = "";

	for(int x = 0; x < sizeTabLimitationVitesse; x++)
	{
		limitationVitesseResult = limitationVitesseResult + limitationVitesse[x];
	}*/

	//string limitationVitesseResult = ConvertToString(limitationVitesse);
	return limitationVitesse;
}

string FindCaractereService::ConvertToString(char* a)
{
	string s(a);
	return s;
}

//---------------------------------------------------------------------------------------------
string FindCaractereService::FindCaractere(int debutXCaractere, int finXCaractere, int debutYCaractere, int finYCaractere)
{
	int positionX75 = ((finXCaractere - debutXCaractere)*0.75)+debutXCaractere;//Position en X a 75% du caractere
	int positionX50 = (debutXCaractere + finXCaractere)/2;//Position en X a 50% du caractere
	int positionX25 = ((finXCaractere - debutXCaractere)*0.25)+debutXCaractere;//Position en X a 25% du caractere

	int positionY75 = ((finYCaractere - debutYCaractere)*0.75)+debutYCaractere;//Position en Y a 75% du caractere
	int positionY50 = (debutYCaractere + finYCaractere)/2;//Position en Y a 50% du caractere
	int positionY25 = ((finYCaractere - debutYCaractere)*0.25)+debutYCaractere;//Position en Y a 25% du caractere

	int nombreSegmentNoirX25 = 0, nombreSegmentNoirY25 = 0;
	int nombreSegmentNoirX50 = 0, nombreSegmentNoirY50 = 0;
	int nombreSegmentNoirX75 = 0, nombreSegmentNoirY75 = 0;

	string result = "";
	//----------------------------------------------------------
	//Recherche segment de haut en bas du caractere (Y) 25%
	for (int hauteur = debutYCaractere; hauteur < finYCaractere; hauteur++)
	{
		if(MonImage.GetPixelRVB(positionX25, hauteur) <= 10)//Si le pixel est noir
		{
			while(MonImage.GetPixelRVB(positionX25, hauteur) <= 10)//Tant que le pixel est noir
			{
				hauteur++;
			}

			nombreSegmentNoirY25++;
		}
	}

	//Recherche segment de gauche à droite du caractere (X) 25%
	for (int largeur = debutXCaractere; largeur < finXCaractere; largeur++)
	{
		if(MonImage.GetPixelRVB(largeur, positionY25) <= 10)//Si le pixel est noir
		{
			while(MonImage.GetPixelRVB(largeur, positionY25) <= 10)//Tant que le pixel est noir
			{
				largeur++;
			}

			nombreSegmentNoirX25++;
		}
	}
	//-------------------------------------------
	//Recherche segment de haut en bas du caractere (Y) 50%
	for (int hauteur = debutYCaractere; hauteur < finYCaractere; hauteur++)
	{
		if(MonImage.GetPixelRVB(positionX50, hauteur) <= 10)//Si le pixel est noir
		{
			while(MonImage.GetPixelRVB(positionX50, hauteur) <= 10)//Tant que le pixel est noir
			{
				hauteur++;
			}

			nombreSegmentNoirY50++;
		}
	}

	//Recherche segment de gauche à droite du caractere (X) 50%
	for (int largeur = debutXCaractere; largeur < finXCaractere; largeur++)
	{
		if(MonImage.GetPixelRVB(largeur, positionY50) <= 10)//Si le pixel est noir
		{
			while(MonImage.GetPixelRVB(largeur, positionY50) <= 10)//Tant que le pixel est noir
			{
				largeur++;
			}

			nombreSegmentNoirX50++;
		}
	}
	//-------------------------------------------
	//Recherche segment de haut en bas du caractere (Y) 75%
	for (int hauteur = debutYCaractere; hauteur < finYCaractere; hauteur++)
	{
		if(MonImage.GetPixelRVB(positionX75, hauteur) <= 10)//Si le pixel est noir
		{
			while(MonImage.GetPixelRVB(positionX75, hauteur) <= 10)//Tant que le pixel est noir
			{
				hauteur++;
			}

			nombreSegmentNoirY75++;
		}
	}

	//Recherche segment de gauche à droite du caractere (X) 75%
	for (int largeur = debutXCaractere; largeur < finXCaractere; largeur++)
	{
		if(MonImage.GetPixelRVB(largeur, positionY75) <= 10)//Si le pixel est noir
		{
			while(MonImage.GetPixelRVB(largeur, positionY75) <= 10)//Tant que le pixel est noir
			{
				largeur++;
			}

			nombreSegmentNoirX75++;
		}
	}

	result = result + IdentificationCharactere(
	nombreSegmentNoirX75,
	nombreSegmentNoirX50,
	nombreSegmentNoirX25,
	nombreSegmentNoirY75,
	nombreSegmentNoirY50,
	nombreSegmentNoirY25);
	return result;
}

string FindCaractereService::IdentificationCharactere(int nombreSegmentNoirX75,
	int nombreSegmentNoirX50,
	int nombreSegmentNoirX25,
	int nombreSegmentNoirY75,
	int nombreSegmentNoirY50,
	int nombreSegmentNoirY25)
{
	string result = "";
	//Caractere 0
	if((nombreSegmentNoirX75 == 2)&&
	(nombreSegmentNoirX50 == 2)&&
	(nombreSegmentNoirX25 == 2)&&
	(nombreSegmentNoirY75 == 2)&&
	(nombreSegmentNoirY50 == 2)&&
	(nombreSegmentNoirY25 == 2))
	{
		result = "0";
	}

	//Caractere 1
	if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 1)&&
	(nombreSegmentNoirX25 == 1)&&
	(nombreSegmentNoirY75 == 1)&&
	(nombreSegmentNoirY50 == 1)&&
	(nombreSegmentNoirY25 == 1))
	{
		result = "1";
	}

	//Caractere 2
	/*if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 1)&&
	(nombreSegmentNoirX25 == 1)&&
	(nombreSegmentNoirY75 == 3)&&
	(nombreSegmentNoirY50 == 3)&&
	(nombreSegmentNoirY25 == 3))
	{
		result = 2;
	}*/

	//Caractere 3
	if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 1)&&
	(nombreSegmentNoirX25 == 1)&&
	(nombreSegmentNoirY75 == 4)&&
	(nombreSegmentNoirY50 == 3)&&
	(nombreSegmentNoirY25 == 3))
	{
		result = "3";
	}

	//Caractere 4
	if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 2)&&
	(nombreSegmentNoirX25 == 2)&&
	(nombreSegmentNoirY75 == 1)&&
	(nombreSegmentNoirY50 == 2)&&
	(nombreSegmentNoirY25 == 2))
	{
		result = "4";
	}

	//Caractere 5
	if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 1)&&
	(nombreSegmentNoirX25 == 1)&&
	(nombreSegmentNoirY75 == 3)&&
	(nombreSegmentNoirY50 == 3)&&
	(nombreSegmentNoirY25 == 3))
	{
		result = "5";
	}

	//Caractere 6
	if((nombreSegmentNoirX75 == 2)&&
	(nombreSegmentNoirX50 == 3)&&
	(nombreSegmentNoirX25 == 1)&&
	(nombreSegmentNoirY75 == 3)&&
	(nombreSegmentNoirY50 == 3)&&
	(nombreSegmentNoirY25 == 3))
	{
		result = "6";
	}

	//Caractere 7
	if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 1)&&
	(nombreSegmentNoirX25 == 1)&&
	(nombreSegmentNoirY75 == 2)&&
	(nombreSegmentNoirY50 == 2)&&
	(nombreSegmentNoirY25 == 1))
	{
		result = "7";
	}

	//Caractere 8
	if((nombreSegmentNoirX75 == 2)&&
	(nombreSegmentNoirX50 == 1)&&
	(nombreSegmentNoirX25 == 2)&&
	(nombreSegmentNoirY75 == 4)&&
	(nombreSegmentNoirY50 == 3)&&
	(nombreSegmentNoirY25 == 4))
	{
		result = "8";
	}

	//Caractere 9
	if((nombreSegmentNoirX75 == 1)&&
	(nombreSegmentNoirX50 == 3)&&
	(nombreSegmentNoirX25 == 2)&&
	(nombreSegmentNoirY75 == 3)&&
	(nombreSegmentNoirY50 == 3)&&
	(nombreSegmentNoirY25 == 3))
	{
		result = "9";
	}

	return result;
}
