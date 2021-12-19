// All Rights reserved I Love IceCream LTD.


#include "Actors/BALevelSequenceActor.h"

ABALevelSequenceActor::ABALevelSequenceActor(const FObjectInitializer& Init) : Super(Init)
{
	bReplicates = false;//Directly setting bReplicates is the correct procedure for pre-init actors.
	
	bReplicatePlayback = false;

	PlaybackSettings.bAutoPlay = false;
	PlaybackSettings.bHideHud = true;
	PlaybackSettings.bRestoreState = true;
}