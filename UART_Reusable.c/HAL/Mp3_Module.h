/*
 * Mp3_Module.h
 *
 */ 


#ifndef MP3_MODULE_H_
#define MP3_MODULE_H_

#include "ATMEGA32A_UART.h"
#include "Mp3_ModuleCommand.h"

/* Index  Evaluation For  Mp3Module_CmdFormat */ 
 enum {     
	Mp3_indStartByte,                     
    Mp3_indVER,                           
    Mp3_indLEN,                           
    Mp3_indCMD,                           
    Mp3_indFeedBack,                      
    Mp3_indPara_MSB,                    
	Mp3_indPara_LSB,                    
    Mp3_indCheck_MSB,                     
    Mp3_indCheck_LSB,                    
    Mp3_indEndByte,                     
};


typedef struct
{ 
	
			Mp3_EQ					EQMode;
			Mp3_ModeVal				ModeVal;
			Mp3_PlaybackSourceVal	playbackSourceVal;
			Mp3_RpeatPlayVal		Repeatval;
			
			
	   /*API OF MY Mp3 Module*/		
			void (*Mp3Module_Init)(void);
			void (*playNext)(void);
			void (*playPrevious)(void);
			void (*play)(uint16 trackNum);
			void (*stop)(void);
			void (*playFromMP3Folder)(uint16 trackNum);
			void (*playAdvertisement)(uint16 trackNum);
			void (*stopAdvertisement)(void);
			void (*incVolume)(void);
			void (*decVolume)(void);
			void (*Setvolume)(uint8 volume);
			void (*EQSelect)(uint8 setting);
			void (*loop)(uint16 trackNum);
			void (*playbackSource)(uint8 source);
			void (*standbyMode)(void);
			void (*normalMode)(void);
			void (*reset)(void);
			void (*resume)(void);
			void (*pause)(void);
			void (*playFolder)(uint8 folderNum, uint8 trackNum);
			void (*volumeAdjustSet)(uint8 gain);
			void (*startRepeatPlay)(void);
			void (*stopRepeatPlay)(void);
			void (*repeatFolder)(uint16 folder);
			void (*randomAll)(void);
			void (*startRepeat)(void);
			void (*stopRepeat)(void);
			void (*startDAC)(void);
			void (*stopDAC)();
			void (*sleep)(void);
			void (*wakeUp)(void);

			boolean (*isPlaying)(void);
			sint16 (*currentVolume)(void);
			sint16 (*currentEQ)(void);
			sint16 (*currentMode)(void);
			sint16 (*currentVersion)(void);
			sint16 (*numUsbTracks)(void);
			sint16 (*numSdTracks)(void);
			sint16 (*numFlashTracks)(void);
			sint16 (*currentUsbTrack)(void);
			sint16 (*currentSdTrack)(void);
			sint16 (*currentFlashTrack)(void);
			sint16 (*numTracksInFolder)(uint8 folder);
			sint16 (*numFolders)(void);
	 
	
	
	
}Mp3_API;


extern Mp3_API      Mp3M0 ;


#endif /* MP3_MODULE_H_ */