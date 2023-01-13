//---------------------------------------------------------------------------

#ifndef FindCaractereServiceH
#define FindCaractereServiceH
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class FindCaractereService
{
    public:
	string FindCaractere(int, int, int, int);
    string IdentificationCharactere(int, int, int, int, int, int);
	string EncadrerCaractere();
	string ConvertToString(char*);
};
#endif

