#ifndef KEY_SIGNATURE_H
#define	KEY_SIGNATURE_H

#include <string>

namespace KeySignatureKata
{
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
		KeySignature(const SymbolType& symbolType, const int numberOfSymbols, const Tonality& tonality);
		virtual ~KeySignature();

		SymbolType GetSymbolType();
		int GetNumberOfSymbols();
		Tonality GetTonality();
		std::string GetTonic();

	private:
		static const int FIFTH_INTERVAL;
		static const int OCTAVE_INTERVAL;
		static const int RELATIVE_MINOR_ASCENDING_INTERVAL;
		static const int RELATIVE_MINOR_DESCENDING_INTERVAL;
		static const std::string PITCH_NAMES_ASCENDING[];
		static const std::string PITCH_NAMES_DESCENDING[];

		int CalculateTonicIndex();

		SymbolType TheSymbolType;
		int NumberOfSymbols;
		Tonality TheTonality;
	};
}

#endif	/* KEY_SIGNATURE_H */
