#include "KeySignature.h"

const string KeySignature::PITCH_NAMES_ASCENDING[] = {"C", "C#", "D", "D#", "E", "E#", "F#", "G", "G#", "A", "A#", "B"};
const string KeySignature::PITCH_NAMES_DESCENDING[] = {"C", "Cb", "Bb", "A", "Ab", "G", "Gb", "F", "Fb", "Eb", "D", "Db"};

KeySignature::KeySignature(SymbolType symbolType, int numberOfSymbols, Tonality tonality) 
	: TheSymbolType(symbolType)
	, NumberOfSymbols(numberOfSymbols)
	, TheTonality(tonality)
{
}

KeySignature::~KeySignature() 
{
}

SymbolType KeySignature::GetSymbolType()
{
	return TheSymbolType;
}

int KeySignature::GetNumberOfSymbols()
{
	return NumberOfSymbols;
}

Tonality KeySignature::GetTonality()
{
	return TheTonality;
}

string KeySignature::GetTonic()
{
	string tonic;
	if (TheSymbolType == Sharp)
	{
		tonic = PITCH_NAMES_ASCENDING[CalculateTonicIndex()];
	} 
	else
	{
		tonic = PITCH_NAMES_DESCENDING[CalculateTonicIndex()];
	}
	
	return tonic;
}

int KeySignature::CalculateTonicIndex() 
{
	int i = FIFTH_INTERVAL * NumberOfSymbols;
	if (Minor == TheTonality)
	{
		i += (TheSymbolType == Sharp) ? RELATIVE_MINOR_ASCENDING_INTERVAL : RELATIVE_MINOR_DESCENDING_INTERVAL;
	}
	
	return i % OCTAVE_INTERVAL;
}