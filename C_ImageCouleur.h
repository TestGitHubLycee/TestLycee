/*----------------------------------------------------
C_Image.h       Classe C_ImageCouleur
RB novembre 2016
V1.4
----------------------------------------------------*/

#ifndef C_ImageCouleurH
#define C_ImageCouleurH

//---------------------------------------------------------------------------

#include <vcl.h>
#include "C_VideoCapture.h"
//-----------------------------------------------------

class C_ImageCouleur
{
unsigned short PositionX, PositionY;
short Largeur, Hauteur;
AnsiString NomFichier;

public :
  // les tableaux de pixels RVB
unsigned char * PixelsR;
unsigned char * PixelsV;
unsigned char * PixelsB;

//C_VideoCapture *MaCaptureVideo;

  // constructeurs
C_ImageCouleur(void);
C_ImageCouleur(short, short, unsigned short, unsigned short);

  // accesseurs
short GetLargeur();
short GetHauteur();
unsigned long int GetPixel(short c,short l);
unsigned char GetPixelR(short c,short l);
unsigned char GetPixelV(short c,short l);
unsigned char GetPixelB(short c,short l);
unsigned char GetPixelRVB(short c,short l);

  // mutateurs
void PutPixel(short c,short l, unsigned long int color);
void PutPixelR(short c,short l, unsigned char color);
void PutPixelV(short c,short l, unsigned char color);
void PutPixelB(short c,short l, unsigned char color);

  // acquisition d'images par fichier ou depuis camera
    // acquisition par fichier bmp
void AcquireIntoBmp(AnsiString NomFich);
void LoadFromBmp(AnsiString NomFich);
void SaveToBmp(AnsiString NomFich);

    // acquisition directe en ram
bool ConnecterCaptureVideo(HWND fenetreParent,
  short posX, short posY, short largeur, short hauteur);
void LoadFromCaptureVideo(void);

  // fonctions d'affichage graphique
void Afficher(TCanvas *);       // affichage echelle 1
void AfficherMini(TCanvas *);   // affichage echelle un demi
void Afficher2(TCanvas *);   // affichage echelle 2
void AfficherXY(short, short, TCanvas *);
void MarquerLigne(short numLigne, TCanvas *, TColor);
void MarquerColonne(short numColonne, TCanvas *, TColor);
void MarquerPoint(short col, short lig, TCanvas *, TColor);

  // fonctions spécifiques à l'application trieur de monnaie
short int ComparerCouleurs(unsigned long int color1,
  unsigned long int color2, short int tolerance);
void AnalyserLeFond(unsigned char *moyRouge, unsigned char *moyVert,
  unsigned char *moyBleu);
bool CheckCadrage(short colonneAnalyse, unsigned char seuilEntreBlancEtMarron,
    short hauteurRailNormale);

bool CopyFrom(C_ImageCouleur lImage);
};
//----------------------------------------------------

#define DIFFERENT_COLORS 0
#define SAME_COLORS 1

#endif
