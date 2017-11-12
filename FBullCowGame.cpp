#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	reset();
}

int32 FBullCowGame::GetCurrentTries() const 
{ 
	return MyCurrentTry; 
}

FString FBullCowGame::GetMyHiddenWord()
{
	return MyHiddenWord;
}

int32 FBullCowGame::GetMaxTries() const 
{ 
	return MyMaxTries; 
}


void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 10;
	const FString HIDDEN_WORD = "bode";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

bool FBullCowGame::IsGameWon() const 
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HiddenWordLenght = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
					BullCowCount.BullCount++;
				else
					BullCowCount.CowCounts++;
			}

		}
	}

	return BullCowCount;
}