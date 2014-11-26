#include <string>

#ifndef KEY_SIGNATURE_H
#define	KEY_SIGNATURE_H

using namespace std;

enum Tonality 
{
	Major, Minor
};

enum SymbolType
{
	Sharp, Flat
};

class KeySignature 
{
public:
	KeySignature(SymbolType, int, Tonality);
	virtual ~KeySignature();
	
	SymbolType GetSymbolType();
	int GetNumberOfSymbols();
	Tonality GetTonality();
	string GetTonic();

private:
	static const int FIFTH_INTERVAL = 7;
	static const int OCTAVE_INTERVAL = 12;
	static const int RELATIVE_MINOR_ASCENDING_INTERVAL = 9;
	static const int RELATIVE_MINOR_DESCENDING_INTERVAL = 3;
	static const string PITCH_NAMES_ASCENDING[];
	static const string PITCH_NAMES_DESCENDING[];
	
	int CalculateTonicIndex();
	
	SymbolType TheSymbolType;
	int NumberOfSymbols;
	Tonality TheTonality;
};

#endif	/* KEY_SIGNATURE_H */
