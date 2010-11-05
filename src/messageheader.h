#ifndef P2P_MSGHDR_H
#define P2P_MSGHDR_H
#include<stdio.h>
#include<stdint.h>
#define packed_data __attribute__((__packed__))
#define NAME_LEN 20


//NOTE:
//Control Mesg ==> magic_no = 0xCC
//Data Msg => magic_no = 0xDD

typedef struct _ResourceName
{
	char name[NAME_LEN];
	uint8_t separator;//0x00
}packed_data ResourceName;

typedef struct _ControlMsgSign
{
	uint8_t magic_no;
	uint8_t selector_value;
}packed_data ControlMsgSign;

typedef struct _ListingMsg
{
	ControlMsgSign control_msg;
	//uint8_t magic_no; //0xCC
	//uint8_t selector_value;//0x4C
	uint16_t message_count;
	ResourceName res_name[56]; //56 * 26
}packed_data ListingMsg;

typedef struct _DataMsg
{
	uint8_t magic_no; //0xDD
	char content_name[NAME_LEN];
	uint8_t separator;//0x00
	uint16_t content_len;
	char content[512];
}packed_data DataMsg;

typedef struct _ReqMsg
{
	ControlMsgSign control_msg;
	//uint8_t magic_no; //0xCC
	//uint8_t selector_value;//0x52
	char name[NAME_LEN];
	uint8_t separator;//0x00
}packed_data ReqMsg;

typedef struct _Pair
{
	unsigned int ip_addr; // 4 bytes
	uint16_t port; //2 bytes
}packed_data Pair;

typedef struct _TryMsg
{
	ControlMsgSign control_msg;
	//uint8_t magic_no;//0xCC
	//uint8_t selector_value;//0x54
	char name[NAME_LEN];
	uint8_t separator;//0x00
	uint16_t count;
	Pair pair[6]; //6*6 = 36
}packed_data TryMsg;

typedef union _GenericMsg
{
	char ntwbytes[400];
	union
	{
		uint8_t magic_no;
		ControlMsgSign ctrlmsgsign;
		TryMsg trymsg;
		DataMsg datamsg;
		ListingMsg lstmsg;
		ReqMsg reqmsg;
	};
}GenericMsg;

void print_ntwkbytes(char *,int);

#endif
