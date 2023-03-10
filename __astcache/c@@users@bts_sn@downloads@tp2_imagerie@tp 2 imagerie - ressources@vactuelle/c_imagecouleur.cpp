/*----------------------------------------------------
C_ImageCouleur.cpp       Classe C_ImageCouleur
RB novembre 2016
V1.4
----------------------------------------------------*/
//---------------------------------------------------------------------------

#pragma hdrstop
#pragma package(smart_init)

#include <stdio.h>
#include "C_VideoCapture.h"
#include "C_ImageCouleur.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------- Classe C_Image --------------------------
//-----------------------------------------------------
C_ImageCouleur::C_ImageCouleur(void)
{
PositionX = 10;
PositionY = 10;
Largeur = 100;
Hauteur = 100;
PixelsR = new unsigned char [Largeur*Hauteur];
PixelsV = new unsigned char [Largeur*Hauteur];
PixelsB = new unsigned char [Largeur*Hauteur];
//MaCaptureVideo = new C_VideoCapture;
}
//-----------------------------------------------------
C_ImageCouleur::C_ImageCouleur(short larg, short haut,
    unsigned short PosX, unsigned short PosY)
{
PositionX = PosX;
PositionY = PosY;
Largeur = larg;
Hauteur = haut;
PixelsR = new unsigned char [Largeur*Hauteur];
PixelsV = new unsigned char [Largeur*Hauteur];
PixelsB = new unsigned char [Largeur*Hauteur];
//MaCaptureVideo = new C_VideoCapture;
}
//-----------------------------------------------------
short C_ImageCouleur::GetLargeur()
{ return Largeur;
}
//-----------------------------------------------------
short C_ImageCouleur::GetHauteur()
{ return Hauteur;
}

//-----------------------------------------------------
void C_ImageCouleur::LoadFromBmp(AnsiString NomFich)
{
FILE * F_Image;
short l, c;
unsigned char rouge, vert, bleu;

NomFichier = NomFich;
if ((F_Image = fopen(NomFichier.c_str(), "rb"))!= NULL)
{
  fseek(F_Image,18,SEEK_SET	);
  fread(&Largeur,sizeof(short),1,F_Image);
  fseek(F_Image,22,SEEK_SET	);
  fread(&Hauteur,sizeof(short),1,F_Image);

  // sauter l'entete
  fseek(F_Image,54,SEEK_SET	);
  for (l=Hauteur-1 ; l>=0 ; l--)
  {
    for (c=0 ; c<Largeur ; c++)
    {
      PixelsB[l*Largeur+c] = fgetc(F_Image);
      PixelsV[l*Largeur+c] = fgetc(F_Image);
      PixelsR[l*Largeur+c] = fgetc(F_Image);
    }
  }
}
fclose(F_Image);
}

//-----------------------------------------------------
void C_ImageCouleur::SaveToBmp(AnsiString NomFich)
{
FILE * F_Image;
short l, c;
unsigned char rouge, vert, bleu;

NomFichier = NomFich;
if ((F_Image = fopen(NomFichier.c_str(), "r+b"))!= NULL)
{
  fseek(F_Image,18,SEEK_SET	);
  fwrite(&Largeur,sizeof(short),1,F_Image);
  fseek(F_Image,22,SEEK_SET	);
  fwrite(&Hauteur,sizeof(short),1,F_Image);

  // sauter l'entete
  fseek(F_Image,54,SEEK_SET	);
  for (l=Hauteur-1 ; l>=0 ; l--)
  {
    for (c=0 ; c<Largeur ; c++)
    {
      fputc (PixelsB[l*Largeur+c] , F_Image);
      fputc (PixelsV[l*Largeur+c] , F_Image);
      fputc (PixelsR[l*Largeur+c] , F_Image);

    }
  }
}
fclose(F_Image);
}
//-----------------------------------------------------
void C_ImageCouleur::Afficher(TCanvas * leCanvas)
{

/*
short Ligne, Colonne;
unsigned char niveauDeRouge, niveauDeVert, niveauDeBleu;
long int color;

//leCanvas->Pen->Color = clBlack;
//leCanvas->Rectangle(PositionX,PositionY,PositionX+Largeur+1+1,
//							PositionY+Hauteur+1+1);
for (Ligne=0;Ligne<Hauteur;Ligne++)
	for (Colonne=0;Colonne<Largeur;Colonne++)
	{
	  niveauDeBleu = PixelsB[Largeur*Ligne+Colonne];
	  niveauDeVert = PixelsV[Largeur*Ligne+Colonne];
	  niveauDeRouge = PixelsR[Largeur*Ligne+Colonne];
	  color = niveauDeRouge + (niveauDeVert<<8) + (niveauDeBleu<<16);
	  leCanvas->Pen->Color = color;
	  leCanvas->MoveTo(PositionX+1+Colonne,PositionY+1+Ligne);
		leCanvas->LineTo(PositionX+1+Colonne+1,PositionY+1+Ligne+1);
	}
*/
}
//-----------------------------------------------------
void C_ImageCouleur::Afficher2(TCanvas * leCanvas)
{
/*
short Ligne, Colonne;
unsigned char niveauDeRouge, niveauDeVert, niveauDeBleu;
long int color;

//leCanvas->Pen->Color = clBlack;
//leCanvas->Rectangle(PositionX,PositionY,PositionX+Largeur+1+1,
//							PositionY+Hauteur+1+1);
for (Ligne=0;Ligne<Hauteur;Ligne++)
	for (Colonne=0;Colonne<Largeur;Colonne++)
	{
	  niveauDeBleu = PixelsB[Largeur*Ligne+Colonne];
	  niveauDeVert = PixelsV[Largeur*Ligne+Colonne];
	  niveauDeRouge = PixelsR[Largeur*Ligne+Colonne];
	  color = niveauDeRouge + (niveauDeVert<<8) + (niveauDeBleu<<16);
	  leCanvas->Pen->Color = color;
	  leCanvas->Rectangle(PositionX+1+Colonne*2,PositionY+1+Ligne*2 ,
						PositionX+1+(Colonne+1)*2,PositionY+1+(Ligne+1)*2 );
	  /*
	  leCanvas->MoveTo(PositionX+1+Colonne*2,PositionY+1+Ligne*2);
	  leCanvas->LineTo(PositionX+1+(Colonne)*2,PositionY+1+(Ligne+1)*2);
	  leCanvas->MoveTo(PositionX+1+(Colonne+1)*2,PositionY+1+Ligne*2);
	  leCanvas->LineTo(PositionX+1+(Colonne+1)*2,PositionY+1+(Ligne+1)*2);

	}
*/
}
//-----------------------------------------------------
void C_ImageCouleur::AfficherMini(TCanvas * leCanvas)
{
/*
short Ligne, Colonne;
unsigned char niveauDeRouge, niveauDeVert, niveauDeBleu;
long int color;

leCanvas->Pen->Color = clBlack;
//leCanvas->Rectangle(PositionX,PositionY,PositionX+Largeur/2+1+1,
	//						PositionY+Hauteur/2+1+1);
for (Ligne=0;Ligne<Hauteur;Ligne+=2)
	for (Colonne=0;Colonne<Largeur;Colonne+=2)
	{
	  niveauDeBleu = PixelsB[Largeur*Ligne+Colonne];
	  niveauDeVert = PixelsV[Largeur*Ligne+Colonne];
	  niveauDeRouge = PixelsR[Largeur*Ligne+Colonne];
	  color = niveauDeRouge + (niveauDeVert<<8) + (niveauDeBleu<<16);
	  leCanvas->Pen->Color = color;
	  leCanvas->MoveTo(PositionX+1+Colonne/2,PositionY+1+Ligne/2);
		leCanvas->LineTo(PositionX+1+Colonne/2+1,PositionY+1+Ligne/2+1);
	}
*/
}
//-----------------------------------------------------
void C_ImageCouleur::AfficherXY(short x, short y,TCanvas * leCanvas)
{
PositionX = x;
PositionY = y;
Afficher (leCanvas);
}



//---------------------------------------------------------------------------
void C_ImageCouleur::MarquerLigne(short numLigne, TCanvas * leCanvas,
  TColor color)
{
  leCanvas->Pen->Color = color;
  // point de gauche
  leCanvas->MoveTo(PositionX-2,PositionY+numLigne);
  // point de droite
  leCanvas->LineTo(PositionX+2+Largeur,PositionY+numLigne);
}
//---------------------------------------------------------------------------
void C_ImageCouleur::MarquerColonne(short numColonne, TCanvas * leCanvas,
  TColor color)
{
  leCanvas->Pen->Color = color;
  // point du haut
  leCanvas->MoveTo(PositionX+numColonne,PositionY-2);
  // point du bas
  leCanvas->LineTo(PositionX+numColonne,PositionY+2+Hauteur);
}
//---------------------------------------------------------------------------
void C_ImageCouleur::MarquerPoint(short col, short lig,
  TCanvas * leCanvas, TColor color)
{
  leCanvas->Pen->Color = color;
  leCanvas->MoveTo(PositionX+1+col,PositionY+1+lig);
  leCanvas->LineTo(PositionX+1+col+1,PositionY+1+lig);
}




//---------------------------------------------------------------
unsigned long int C_ImageCouleur::GetPixel(short Colonne,short Ligne)
{
unsigned char niveauDeRouge, niveauDeVert, niveauDeBleu;
unsigned long int color;
      niveauDeRouge = PixelsR[Largeur*Ligne+Colonne];
      niveauDeVert = PixelsV[Largeur*Ligne+Colonne];
      niveauDeBleu = PixelsB[Largeur*Ligne+Colonne];
      color = niveauDeBleu + (niveauDeVert<<8) + (niveauDeRouge<<16);
return color;
}
//---------------------------------------------------------------
unsigned char C_ImageCouleur::GetPixelRVB(short Colonne, short Ligne)
{
unsigned char niveauDeRouge, niveauDeVert, niveauDeBleu;
unsigned long int color;
      niveauDeRouge = PixelsR[Largeur*Ligne+Colonne];
      niveauDeVert = PixelsV[Largeur*Ligne+Colonne];
      niveauDeBleu = PixelsB[Largeur*Ligne+Colonne];
      color = (niveauDeBleu + niveauDeVert + niveauDeRouge)/3;
return color;
}
//---------------------------------------------------------------
unsigned char C_ImageCouleur::GetPixelR(short c, short l)
{
return PixelsR[l*Largeur+c];
}
//---------------------------------------------------------------
unsigned char C_ImageCouleur::GetPixelV(short c, short l)
{
return PixelsV[l*Largeur+c];
}
//---------------------------------------------------------------
unsigned char C_ImageCouleur::GetPixelB(short c, short l)
{
return PixelsB[l*Largeur+c];
}




//---------------------------------------------------------------
void C_ImageCouleur::PutPixelR(short c, short l, unsigned char color)
{
PixelsR[l*Largeur+c] = color;
}
//---------------------------------------------------------------
void C_ImageCouleur::PutPixelV(short c, short l, unsigned char color)
{
PixelsV[l*Largeur+c] = color;
}
//---------------------------------------------------------------
void C_ImageCouleur::PutPixelB(short c, short l, unsigned char color)
{
PixelsB[l*Largeur+c] = color;
}

//---------------------------------------------------------------
void C_ImageCouleur::PutPixel(short c, short l, unsigned long int color)
{
PixelsR[l*Largeur+c] = (color&0x000000ff);
PixelsV[l*Largeur+c] = (color&0x0000ff00)>>8;
PixelsB[l*Largeur+c] = (color&0x00ff0000)>>16;
}




/*--------------------------------------------
Methode verifiant le cadrage de l'image sur le
trieur de monnaie
------------------------------------------------*/
bool C_ImageCouleur::CheckCadrage(short colonneAnalyse,
    unsigned char seuilEntreBlancEtMarron, short hauteurRailNormale)
{
short l=0, niveauRVB;

  // on descend sur la colonne colonneAnalyse tant qu'on est dans
  // le blanc (ou jusqu'a rencontrer le rail (marron))



  //quand on passe dans le marron (le rail), on a trouve
  // le cadrage vertical. Il faut le comparer a une valeur
  // de reference pour determiner si le cadrage est correct

  return 0;
}
/*--------------------------------------------
Methode qui recopie une image dans une autre
------------------------------------------------*/
bool C_ImageCouleur::CopyFrom(C_ImageCouleur lImageDOrigine)
{
   // si on veut recopier une image de 640*480 vers une de 320*240
   if (Largeur == 320 && Hauteur == 240 &&
         lImageDOrigine.GetLargeur() == 640 && lImageDOrigine.GetHauteur() == 480)
   {
      // pour tous les pixels de l'image
      for (short l=0 ; l<Hauteur ; l++)
         for (short c=0 ; c<Largeur ; c++)
         {
            // recopie de un pixel sur deux
            PutPixelR(c,l, lImageDOrigine.GetPixelR(l*2,c*2) );
            PutPixelV(c,l, lImageDOrigine.GetPixelV(l*2,c*2) );
            PutPixelB(c,l, lImageDOrigine.GetPixelB(l*2,c*2) );
         }
   }
   // si on veut recopier une image depuis une autre qui a le m??me format
   else if (Largeur == lImageDOrigine.GetLargeur()
         && Hauteur == lImageDOrigine.GetHauteur() )
   {
      // pour tous les pixels de l'image
      for (short l=0 ; l<Hauteur ; l++)
         for (short c=0 ; c<Largeur ; c++)
         {
            // recopie de chaque pixel
            PutPixelR(c,l, lImageDOrigine.GetPixelR(l,c) );
            PutPixelV(c,l, lImageDOrigine.GetPixelV(l,c) );
            PutPixelB(c,l, lImageDOrigine.GetPixelB(l,c) );
         }
   }
   return 1;
}
