/*
 * Mp3_ModuleCommand.h
 */ 


#ifndef MP3_MODULECOMMAND_H_
#define MP3_MODULECOMMAND_H_



//-------------------------------------------------------------------------------------//
// Packet Values
//-------------------------------------------------------------------------------------//
#define  STACK_SIZE       0x0A   //total number of bytes in a stack/packet (same for cmds and queries)
#define  SB               0x7E //start byte
#define  VER              0xFF //version
#define  LEN              0x06  //number of bytes after "LEN" (except for checksum data and EB)
#define  FEEDBACK         0x01    //feedback requested
#define  NO_FEEDBACK      0x00    //no feedback requested
#define  EB               0xEF //end byte
#define  Diactivate       0x00 //deactivate command

//-------------------------------------------------------------------------------------//
// Control Command Values
//-------------------------------------------------------------------------------------//
#define NEXT             0x01
#define PREV             0x02
#define PLAY             0x03
#define INC_VOL          0x04
#define DEC_VOL          0x05
#define VOLUME           0x06
#define EQ               0x07
#define PLAYBACK_MODE    0x08
#define PLAYBACK_SRC     0x09
#define STANDBY          0x0A
#define NORMAL           0x0B
#define RESET            0x0C
#define PLAYBACK         0x0D
#define PAUSE            0x0E
#define SPEC_FOLDER      0x0F
#define VOL_ADJ          0x10
#define REPEAT_PLAY      0x11
#define USE_MP3_FOLDER   0x12
#define INSERT_ADVERT    0x13
#define SPEC_TRACK_3000  0x14
#define STOP_ADVERT      0x15
#define STOP             0x16
#define REPEAT_FOLDER    0x17
#define RANDOM_ALL       0x18
#define REPEAT_CURRENT   0x19
#define SET_DAC          0x1A

//-------------------------------------------------------------------------------------//
// Query Command Values
//-------------------------------------------------------------------------------------//
#define SEND_INIT         0x3F
#define RETRANSMIT        0x40
#define REPLY             0x41
#define GET_STATUS_       0x42
#define GET_VOL           0x43
#define GET_EQ            0x44
#define GET_MODE          0x45
#define GET_VERSION       0x46
#define GET_TF_FILES      0x47
#define GET_U_FILES       0x48
#define GET_FLASH_FILES   0x49
#define KEEP_ON           0x4A
#define GET_TF_TRACK      0x4B
#define GET_U_TRACK       0x4C
#define GET_FLASH_TRACK   0x4D
#define GET_FOLDER_FILES  0x4E
#define GET_FOLDERS       0x4F

//-------------------------------------------------------------------------------------//
// EQ Values
//-------------------------------------------------------------------------------------//
typedef enum{Normal,Pop,Rock,Jazz,Classic,Bass} Mp3_EQ;

//-------------------------------------------------------------------------------------//
// Mode Values
//-------------------------------------------------------------------------------------//

typedef enum {REPEAT,FOLDER_REPEAT,SINGLE_REPEAT,RANDOM}Mp3_ModeVal;      

//-------------------------------------------------------------------------------------//
// Playback Source Values
//-------------------------------------------------------------------------------------//

typedef enum {Disable,U,TF,AUX,SLEEP,FLASH}Mp3_PlaybackSourceVal;

//-------------------------------------------------------------------------------------//
// Base Volume Adjust Value
//-------------------------------------------------------------------------------------//
#define  VOL_ADJUST       0x10

//-------------------------------------------------------------------------------------//
// Repeat Play Values
//-------------------------------------------------------------------------------------//

typedef enum {STOP_REPEAT,START_REPEAT}Mp3_RpeatPlayVal;

#endif /* MP3_MODULECOMMAND_H_ */