/*--------------------------------------------------------
  TP Imagerie       BTS Info et Réseaux Lorgues
Septembre 2016 - Septembre 2021
Classe permettant d'acquerir une image depuis un peripherique
video (camera USB, appareil photo, scanner, camera video avec
carte d'acquisition video, ...)
C_VideoCapture.cpp    Environnement : Windows, C++ Builder 10.3
Auteur : Philippe Dupuy, Rémi Breysse
---------------------------------------------------------*/

#include <vcl.h>
#pragma hdrstop
#pragma package(smart_init)

#define __C_VIDEOCAPTURE_CPP__
#include "C_VideoCapture.h"
//---------------------------------------------------------------------------
C_VideoCapture::C_VideoCapture()
{
	InitDLL();
	FileNameFrame="./frame.bmp";
	FileNameVideo="video.avi";
}
//---------------------------------------------------------------------------
C_VideoCapture::~C_VideoCapture()
{
	//Close();
}
//---------------------------------------------------------------------------
void C_VideoCapture::Close()
{
	capDriverDisconnect(hFenCapt);
	FreeLibrary(handleAvicap32Dll);
}
//---------------------------------------------------------------------------
void C_VideoCapture::InitDLL()
{
	handleAvicap32Dll = LoadLibraryW(__T("avicap32.dll"));
	MaFonctionCapGetDriverDescription = (BOOL WINAPI (*)(WORD, LPTSTR, INT, LPTSTR, INT) )
					GetProcAddress(handleAvicap32Dll, "capGetDriverDescriptionA");
	MaFonctionCapCreateCaptureWindow = (HWND WINAPI (*)(LPCSTR , DWORD, int , int , int , int ,
				HWND , int ) ) GetProcAddress(handleAvicap32Dll, "capCreateCaptureWindowA");

}
//---------------------------------------------------------------------------
void C_VideoCapture::RechercherPeripherique()
{

	//Recherche des périphériques
	for (short DevIndex = 0; DevIndex < 10; DevIndex++)
	{
		if (MaFonctionCapGetDriverDescription (DevIndex, LPTSTR(DeviceName), 80, LPTSTR(DeviceVersion), 80) == true)
		//szDeviceName,	sizeof (szDeviceName), szDeviceVersion, sizeof (szDeviceVersion)))
		{
			//incription des noms de périphériques
			NomsDesPerif[DevIndex] = AnsiString(DeviceName);
		}
		else NomsDesPerif[DevIndex]="";
	}

}
//---------------------------------------------------------------------------
void C_VideoCapture::CreerFenetre(HWND fenetreParent)
{
		hFenCapt = MaFonctionCapCreateCaptureWindow (
			"My Capture Window",    // nom de la fenêtre
			WS_CHILD | WS_VISIBLE,  // style de la fenêtre (winuser.h - L:2291)
			150, 24, 640, 480,         // position et dimensions de la fenêtre
			fenetreParent,          // handle sur la fenêtre parente
			nID );                  // identificateur de la fenêtre

}
//---------------------------------------------------------------------------
void C_VideoCapture::CreerFenetre(HWND fenetreParent,short posX, short posY,
    short largeur, short hauteur)
{
	hFenCapt = MaFonctionCapCreateCaptureWindow (
			"My Capture Window",    // nom de la fenêtre
			WS_CHILD | WS_VISIBLE,  // style de la fenêtre (winuser.h - L:2291)
			posX, posY, largeur, hauteur,  // position et dimensions de la fenêtre
			fenetreParent,          // handle sur la fenêtre parente
			nID );                  // identificateur de la fenêtre
}
//---------------------------------------------------------------------------
bool C_VideoCapture::ConnecterPeripherique(short NumeroDuPeripherique)
{
		bool test = false ;
		test = capDriverConnect(hFenCapt,NumeroDuPeripherique);

		//configuration de la vitesse de visualisation
		capPreviewRate(hFenCapt,10);

		//demarrage de la prévisualisation
		capPreview(hFenCapt,true);

		return test;
}
//---------------------------------------------------------------------------
void C_VideoCapture::CapturerVideo()
{
        capCaptureSequence(hFenCapt);
		capFileSaveAs(hFenCapt, FileNameVideo.c_str());
}
//---------------------------------------------------------------------------
bool C_VideoCapture::CapturerFrame()
{
    //allocating memory for wchar:
	LPWSTR output = new WCHAR[50];

	// from string to LPWSTR:
	MultiByteToWideChar (CP_ACP, MB_PRECOMPOSED , (LPCSTR) FileNameFrame.c_str() , -1, output, 50);

	return capFileSaveDIB(hFenCapt, output);	//".\\frame.bmp");	//l );	//(LPTSTR) (FileNameFrame.c_str() ) );	//LPTSTR(n.c_str()) );	//LPTSTR("./frame.bmp"));//strFileNameFrame.c_str());
}
//---------------------------------------------------------------------------
void C_VideoCapture::HeightWidth(unsigned int *h,unsigned int *w)
{
CAPSTATUS CapStatus;
        capGetStatus(hFenCapt,&CapStatus,sizeof(CAPSTATUS));
        *h = CapStatus.uiImageHeight;
        *w = CapStatus.uiImageWidth;
}
//---------------------------------------------------------------------------
HWND C_VideoCapture::GetHandleCaptureWindow(void)
{
return hFenCapt;
}
//---------------------------------------------------------------------------
AnsiString C_VideoCapture::GetNomDuPerif(short num)
{
	if(NomsDesPerif[num]=="")
	  return "" ;
	else
	  return NomsDesPerif[num];
};
