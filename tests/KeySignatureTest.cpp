#include <gmock/gmock.h>
#include "KeySignature.h"
#include <string>

TEST(KeySignatureTest, WhenAKeySignatureIsCreatedAllAttributesCanBeRetrieved)
{
	KeySignature key(Sharp, 2, Major);
	
	EXPECT_EQ(Sharp, key.GetSymbolType());
	EXPECT_EQ(2, key.GetNumberOfSymbols());
	EXPECT_EQ(Major, key.GetTonality()); 
}

TEST(KeySignatureTest, WhenAMajorKeySignatureIsCreatedWithZeroSymbolsThenItsTonicIsC)
{
	KeySignature key(Sharp, 0, Major);
	EXPECT_EQ("C", key.GetTonic());
}

TEST(KeySignatureTest, WhenAMajorKeySignatureIsCreatedWithOneSharpThenItsTonicIsG)
{
	KeySignature key(Sharp, 1, Major);
	EXPECT_EQ("G", key.GetTonic());
}

TEST(KeySignatureTest, WhenAMajorKeySignatureIsCreatedWithUptoSevenSharpsThenItHasTheCorrectTonic)
{
	KeySignature keyOfDMajor(Sharp, 2, Major);
	EXPECT_EQ("D", keyOfDMajor.GetTonic());
	
	KeySignature keyOfAMajor(Sharp, 3, Major);
	EXPECT_EQ("A", keyOfAMajor.GetTonic());
	
	KeySignature keyOfEMajor(Sharp, 4, Major);
	EXPECT_EQ("E", keyOfEMajor.GetTonic());
	
	KeySignature keyOfBMajor(Sharp, 5, Major);
	EXPECT_EQ("B", keyOfBMajor.GetTonic());
	
	KeySignature keyOfFSharpMajor(Sharp, 6, Major);
	EXPECT_EQ("F#", keyOfFSharpMajor.GetTonic());
	
	KeySignature keyOfCSharpMajor(Sharp, 7, Major);
	EXPECT_EQ("C#", keyOfCSharpMajor.GetTonic());	
}

TEST(KeySignatureTest, WhenAMajorKeySignatureIsCreatedWithOneFlatThenItsTonicIsF)
{
	KeySignature key(Flat, 1, Major);
	EXPECT_EQ("F", key.GetTonic());
}

TEST(KeySignatureTest, WhenAMajorKeySignatureIsCreatedWithUptoSevenFlatsThenItHasTheCorrectTonic)
{
	KeySignature keyOfBFlatMajor(Flat, 2, Major);
	EXPECT_EQ("Bb", keyOfBFlatMajor.GetTonic());
	
	KeySignature keyEFlatMajor(Flat, 3, Major);
	EXPECT_EQ("Eb", keyEFlatMajor.GetTonic());
	
	KeySignature keyOfAFlatMajor(Flat, 4, Major);
	EXPECT_EQ("Ab", keyOfAFlatMajor.GetTonic());
	
	KeySignature keyOfDFlatMajor(Flat, 5, Major);
	EXPECT_EQ("Db", keyOfDFlatMajor.GetTonic());
	
	KeySignature keyOfGFlatMajor(Flat, 6, Major);
	EXPECT_EQ("Gb", keyOfGFlatMajor.GetTonic());
	
	KeySignature keyOfCFlatMajor(Flat, 7, Major);
	EXPECT_EQ("Cb", keyOfCFlatMajor.GetTonic());	
}

TEST(KeySignatureTest, WhenAMinorKeySignatureIsCreatedWithZeroSymbolsThenItsTonicIsA)
{
	KeySignature sharpKey(Sharp, 0, Minor);
	EXPECT_EQ("A", sharpKey.GetTonic());

	KeySignature flatKey(Sharp, 0, Minor);
	EXPECT_EQ("A", flatKey.GetTonic());
}

TEST(KeySignatureTest, WhenAMinorKeySignatureIsCreatedWithUptoSevenSharpsThenItHasTheCorrectTonic)
{
	KeySignature keyOfEMinor(Sharp, 1, Minor);
	EXPECT_EQ("E", keyOfEMinor.GetTonic());
	
	KeySignature keyOfBMinor(Sharp, 2, Minor);
	EXPECT_EQ("B", keyOfBMinor.GetTonic());
	
	KeySignature keyOfFSharpMinor(Sharp, 3, Minor);
	EXPECT_EQ("F#", keyOfFSharpMinor.GetTonic());
	
	KeySignature keyOfCSharpMinor(Sharp, 4, Minor);
	EXPECT_EQ("C#", keyOfCSharpMinor.GetTonic());
	
	KeySignature keyOfGSharpMinor(Sharp, 5, Minor);
	EXPECT_EQ("G#", keyOfGSharpMinor.GetTonic());
	
	KeySignature keyOfDSharpMinor(Sharp, 6, Minor);
	EXPECT_EQ("D#", keyOfDSharpMinor.GetTonic());
	
	KeySignature keyOfASharpMinor(Sharp, 7, Minor);
	EXPECT_EQ("A#", keyOfASharpMinor.GetTonic());	
}

TEST(KeySignatureTest, WhenAMinorKeySignatureIsCreatedWithUptoSevenFlatsThenItHasTheCorrectTonic)
{
	KeySignature keyOfDMinor(Flat, 1, Minor);
	EXPECT_EQ("D", keyOfDMinor.GetTonic());
	KeySignature keyOfGMinor(Flat, 2, Minor);
	EXPECT_EQ("G", keyOfGMinor.GetTonic());
	KeySignature keyOfCMinor(Flat, 3, Minor);
	EXPECT_EQ("C", keyOfCMinor.GetTonic());
	KeySignature keyOfFMinor(Flat, 4, Minor);
	EXPECT_EQ("F", keyOfFMinor.GetTonic());
	KeySignature keyOfBFlatMinor(Flat, 5, Minor);
	EXPECT_EQ("Bb", keyOfBFlatMinor.GetTonic());
	KeySignature keyOfEFlatMinor(Flat, 6, Minor);
	EXPECT_EQ("Eb", keyOfEFlatMinor.GetTonic());
	KeySignature keyOfAFlatMinor(Flat, 7, Minor);
	EXPECT_EQ("Ab", keyOfAFlatMinor.GetTonic());	
}




