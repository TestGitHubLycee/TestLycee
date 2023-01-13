/*--------------------------------------------------------
  TP Imagerie       BTS Info et R�seaux Lorgues      Septembre 2016
Classe permettant d'acquerir une image depuis un peripherique
video (camera USB, appareil photo, scanner, camera video avec
carte d'acquisition video, ...)
C_VideoCapture.h      Environnement : Windows, C++ Builder 6
Auteur : Philippe Dupuy, R�mi Breysse
---------------------------------------------------------*/

#ifndef C_VideoCaptureH
#define C_VideoCaptureH
//---------------------------------------------------------------------------

#include <vcl.h>
//#include <windows.h>
#include <vfw.h>

#define __T(x) L ## x

//---------------------------------------------------------------------------
class C_VideoCapture
{
    private:
        HWND hFenCapt;
        int nID;
		char DeviceName[80];
		char DeviceVersion[80];
		AnsiString NomsDesPerif[10];
		CAPDRIVERCAPS CapDrvCaps;
		CAPSTATUS *CapStatus;

	public:
        // ----- definitions pour l'acces aux fonctions systeme de capture video
		HINSTANCE handleAvicap32Dll;
		void InitDLL (void);
		void Close();//TEST

		BOOL WINAPI (*MaFonctionCapGetDriverDescription) (WORD wDriverIndex, LPTSTR lpszName, INT cbName, LPTSTR lpszVer, INT cbVer);
		HWND WINAPI (*MaFonctionCapCreateCaptureWindow) (LPCSTR lpszWindowName,   DWORD  dwStyle,
				int x, int y, int nWidth, int nHeight, HWND hwndParent, int nID);

		
        AnsiString FileNameFrame,FileNameVideo;

		C_VideoCapture();
		~C_VideoCapture();

		void RechercherPeripherique();

		void CreerFenetre(HWND arg);
		//arg: handle sur la fen�tre parente

        void CreerFenetre(HWND arg, short posX, short posY,
              short largeur, short hauteur);

		AnsiString GetNomDuPerif(short num);
        //num :num�ro du p�riph�rique(0 � 9 d�finit par rechercherPeripherique())
        //retourne le nom du p�riph�rique ou ""

        bool ConnecterPeripherique(short NumeroDuPeripherique);
        //arg:num�ro du p�riph�rique(0 � 9 d�fini par rechercherPeripherique())

        void AppelerFenetre_CameraEtResolution()
        {
                capDlgVideoFormat( hFenCapt );
                capDlgVideoSource( hFenCapt );
                capDlgVideoDisplay(hFenCapt);
        };
        void AppelerFenetre_Compression()
        {
                capDlgVideoCompression(hFenCapt);
		};
        void SetNomFichierFrame()
		{ //InputQuery("","",strFileNameFrame);
        };
        void SetNomFichierVideo()
		{ //InputQuery("","",strFileNameVideo);
        };
        void CapturerVideo();
        bool CapturerFrame();
        void HeightWidth(unsigned int *h,unsigned int *w);
        HWND GetHandleCaptureWindow(void);
};


#endif
