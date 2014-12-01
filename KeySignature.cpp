#include "KeySignature.h"

using namespace KeySignatureKata;

const int KeySignature::FIFTH_INTERVAL = 7;
const int KeySignature::OCTAVE_INTERVAL = 12;
const int KeySignature::RELATIVE_MINOR_ASCENDING_INTERVAL = 9;
const int KeySignature::RELATIVE_MINOR_DESCENDING_INTERVAL = 3;
const std::string KeySignature::PITCH_NAMES_ASCENDING[] = {"C", "C#", "D", "D#", "E", "E#", "F#", "G", "G#", "A", "A#", "B"};
const std::string KeySignature::PITCH_NAMES_DESCENDING[] = {"C", "Cb", "Bb", "A", "Ab", "G", "Gb", "F", "Fb", "Eb", "D", "Db"};

KeySignature::KeySignature(const SymbolType& symbolType, const int numberOfSymbols, const Tonality& tonality) 
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

std::string KeySignature::GetTonic()
{
	std::string tonic;
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
	int index = FIFTH_INTERVAL * NumberOfSymbols;
	if (Minor == TheTonality)
	{
		index += (TheSymbolType == Sharp) ? RELATIVE_MINOR_ASCENDING_INTERVAL : RELATIVE_MINOR_DESCENDING_INTERVAL;
	}
	
	return index % OCTAVE_INTERVAL;
}