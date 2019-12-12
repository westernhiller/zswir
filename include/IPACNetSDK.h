///////////////////////////////////////////////////////////////////
//File:			WWADevSDK.h
//ver:			1.0
//Date:			2011-11-12
//Description:	Interface for WWADevSDK.dll
///////////////////////////////////////////////////////////////////

#ifndef IPAC_DEVSDK_H_
#define IPAC_DEVSDK_H_

// #ifdef __cplusplus
// extern "C" {
// #endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef IPAC_DEVSDK_H_
#define IPAC_API extern "C" __declspec(dllexport) 
#else 
#define IPAC_API extern "C" __declspec(dllimport) 
#endif

//�궨��
#define NAME_LEN		    	16      //���Ƴ���
#define PASSWD_LEN			    16      //���볤��
#define SERIALNO_LEN		    16      //���кų���

/*******************ȫ�ִ����� begin**********************/	
#define IPAC_DEV_NOERROR				 0	//û�д���
#define IPAC_DEV_PASSWORD_ERROR			1	//�û����������ע��ʱ������û��������������
#define IPAC_DEV_NOENOUGHPRI			2	//Ȩ�޲��㡣��ע���û�û��Ȩ��ִ�е�ǰ���豸�Ĳ�����������Զ���û������������Աȡ�
#define IPAC_DEV_NOINIT     			3	//SDKδ��ʼ����
#define IPAC_DEV_CHANNEL_ERROR			4	//ͨ���Ŵ����豸û�ж�Ӧ��ͨ���š�
#define IPAC_DEV_OVER_MAXLINK			5	//���ӵ��豸���û������������
#define IPAC_DEV_VERSIONNOMATCH			6	//�汾��ƥ�䡣SDK���豸�İ汾��ƥ�䡣
#define IPAC_DEV_NETWORK_FAIL_CONNECT	7	//�����豸ʧ�ܡ��豸�����߻�����ԭ����������ӳ�ʱ�ȡ�
#define IPAC_DEV_NETWORK_SEND_ERROR		8	//���豸����ʧ�ܡ�
#define IPAC_DEV_NETWORK_RECV_ERROR		9	//���豸��������ʧ�ܡ�
#define IPAC_DEV_NETWORK_RECV_TIMEOUT	10	//���豸�������ݳ�ʱ��
#define IPAC_DEV_NETWORK_ERRORDATA		11	//���͵��������󡣷��͸��豸���ߴ��豸���յ������ݴ�����Զ�̲�������ʱ�����豸��֧�ֵ�ֵ��
#define IPAC_DEV_ORDER_ERROR			12	//���ô������
#define IPAC_DEV_OPERNOPERMIT			13	//�޴�Ȩ�ޡ�
#define IPAC_DEV_COMMANDTIMEOUT			14	//�豸����ִ�г�ʱ��
#define IPAC_DEV_ERRORSERIALPORT		15	//���ںŴ���ָ�����豸���ںŲ����ڡ�
#define IPAC_DEV_ERRORALARMPORT			16	//�����˿ڴ���ָ�����豸��������˿ڲ����ڡ�
#define IPAC_DEV_PARAMETER_ERROR		17	//��������SDK�ӿ��и����������������Ϊ�ա�
#define IPAC_DEV_CHAN_EXCEPTION			18	//�豸ͨ�����ڴ���״̬
#define IPAC_DEV_NODISK					19	//�豸��Ӳ�̡����豸��Ӳ��ʱ�����豸��¼���ļ���Ӳ�����õȲ���ʧ�ܡ�
#define IPAC_DEV_ERRORDISKNUM			20	//Ӳ�̺Ŵ��󡣵����豸����Ӳ�̹������ʱ��ָ����Ӳ�̺Ų�����ʱ���ظô���
#define IPAC_DEV_DISK_FULL				21	//�豸Ӳ������
#define IPAC_DEV_DISK_ERROR 			22	//�豸Ӳ�̳���
#define IPAC_DEV_NOSUPPORT				23	//�豸��֧�֡�
#define IPAC_DEV_BUSY					24	//�豸æ��
#define IPAC_DEV_MODIFY_FAIL			25	//�豸�޸Ĳ��ɹ���
#define IPAC_DEV_PASSWORD_FORMAT_ERROR	26	//���������ʽ����ȷ
#define IPAC_DEV_DISK_FORMATING			27	//Ӳ�����ڸ�ʽ������������������
#define IPAC_DEV_DVRNORESOURCE			28	//�豸��Դ���㡣
#define IPAC_DEV_DVROPRATEFAILED		29	//�豸����ʧ�ܡ�
#define IPAC_DEV_OPENHOSTSOUND_FAIL		30	//�����Խ��������㲥�����вɼ�������Ƶ�����Ƶ���ʧ�ܡ�
#define IPAC_DEV_DVRVOICEOPENED			31	//�豸�����Խ���ռ�á�
#define IPAC_DEV_TIMEINPUTERROR			32	//ʱ�����벻��ȷ��
#define IPAC_DEV_NOSPECFILE 			33	//�ط�ʱ�豸û��ָ�����ļ���
#define IPAC_DEV_CREATEFILE_ERROR		34	//�����ļ���������¼�񡢱���ͼƬ����ȡ�����ļ���Զ������¼��ʱ�����ļ�ʧ�ܡ�
#define IPAC_DEV_FILEOPENFAIL			35	//���ļ��������������ļ����豸�������ϴ���Ѷ�ļ�ʱ���ļ�ʧ�ܡ�
#define IPAC_DEV_OPERNOTFINISH			36	//�ϴεĲ�����û����ɡ�
#define IPAC_DEV_GETPLAYTIMEFAIL		37	//��ȡ��ǰ���ŵ�ʱ�����
#define IPAC_DEV_PLAYFAIL				38	//���ų���
#define IPAC_DEV_FILEFORMAT_ERROR		39	//�ļ���ʽ����ȷ��
#define IPAC_DEV_DIR_ERROR				40	//·������
#define IPAC_DEV_ALLOC_RESOURCE_ERROR	41	//SDK��Դ�������
#define IPAC_DEV_AUDIO_MODE_ERROR		42	//����ģʽ���󡣵�ǰ����������ģʽ��ʵ�����õ�ģʽ��������
#define IPAC_DEV_NOENOUGH_BUF			43	//������̫С�������豸���ݵĻ���������ͼƬ���������㡣
#define IPAC_DEV_CREATESOCKET_ERROR		44	//����SOCKET����
#define IPAC_DEV_SETSOCKET_ERROR		45	//����SOCKET����
#define IPAC_DEV_MAX_NUM				46	//�����ﵽ��󡣷����ע����������Ԥ������������SDK֧�ֵ��������
#define IPAC_DEV_USERNOTEXIST			47	//�û������ڡ�ע����û�ID��ע���򲻿��á�
#define IPAC_DEV_WRITEFLASHERROR		48	//дFLASH�����豸����ʱдFLASHʧ�ܡ�
#define IPAC_DEV_UPGRADEFAIL			49	//�豸����ʧ�ܡ�����������ļ����Բ�ƥ���ԭ������ʧ�ܡ�
#define IPAC_DEV_CARDHAVEINIT			50	//���뿨�Ѿ���ʼ������
#define IPAC_DEV_PLAYERFAILED			51	//���ò��ſ���ĳ������ʧ�ܡ�
#define IPAC_DEV_MAX_USERNUM			52	//��¼�豸���û����ﵽ���
#define IPAC_DEV_GETLOCALIPANDMACFAIL	53	//��ñ���PC��IP��ַ�������ַʧ�ܡ�
#define IPAC_DEV_NOENCODEING			54	//�豸��ͨ��û���������롣
#define IPAC_DEV_IPMISMATCH				55	//IP��ַ��ƥ�䡣
#define IPAC_DEV_MACMISMATCH			56	//MAC��ַ��ƥ�䡣
#define IPAC_DEV_UPGRADELANGMISMATCH	57	//�����ļ����Բ�ƥ�䡣
#define IPAC_DEV_MAX_PLAYERPORT			58	//������·���ﵽ���
#define IPAC_DEV_NOSPACEBACKUP			59	//�����豸��û���㹻�ռ���б��ݡ�
#define IPAC_DEV_NODEVICEBACKUP			60	//û���ҵ�ָ���ı����豸��
#define IPAC_DEV_PICTURE_BITS_ERROR		61	//ͼ����λ����������24ɫ��
#define IPAC_DEV_PICTURE_DIMENSION_ERROR	62	//ͼƬ��*���ޣ���128*256��
#define IPAC_DEV_PICTURE_SIZ_ERROR			63	//ͼƬ��С���ޣ���100K��
#define IPAC_DEV_LOADPLAYERSDKFAILED		64	//���뵱ǰĿ¼��Player Sdk����
#define IPAC_DEV_LOADPLAYERSDKPROC_ERROR	65	//�Ҳ���Player Sdk��ĳ��������ڡ�
#define IPAC_DEV_LOADDSSDKFAILED			66	//���뵱ǰĿ¼��DSsdk����
#define IPAC_DEV_LOADDSSDKPROC_ERROR		67	//�Ҳ���DsSdk��ĳ��������ڡ�
#define IPAC_DEV_DSSDK_ERROR				68	//����Ӳ�����DsSdk��ĳ������ʧ�ܡ�
#define IPAC_DEV_VOICEMONOPOLIZE			69	//��������ռ��
#define IPAC_DEV_JOINMULTICASTFAILED		70	//����ಥ��ʧ�ܡ�
#define IPAC_DEV_CREATEDIR_ERROR			71	//������־�ļ�Ŀ¼ʧ�ܡ�
#define IPAC_DEV_BINDSOCKET_ERROR			72	//���׽���ʧ�ܡ�
#define IPAC_DEV_SOCKETCLOSE_ERROR			73	//socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ
#define IPAC_DEV_USERID_ISUSING				74	//ע��ʱ�û�ID���ڽ���ĳ������
#define IPAC_DEV_SOCKETLISTEN_ERROR			75	//����ʧ�ܡ�
#define IPAC_DEV_PROGRAM_EXCEPTION			76	//�����쳣��
#define IPAC_DEV_WRITEFILE_FAILED			77	//д�ļ�ʧ�ܡ�����¼��Զ������¼������ͼƬ�Ȳ���ʱд�ļ�ʧ�ܡ�
#define IPAC_DEV_FORMAT_READONLY			78	//��ֹ��ʽ��ֻ��Ӳ�̡�
#define IPAC_DEV_WITHSAMEUSERNAME			79	//Զ���û����ýṹ�д�����ͬ���û�����
#define IPAC_DEV_DEVICETYPE_ERROR			80	//�������ʱ�豸�ͺŲ�ƥ�䡣
#define IPAC_DEV_LANGUAGE_ERROR				81	//�������ʱ���Բ�ƥ�䡣
#define IPAC_DEV_PARAVERSION_ERROR			82	//�������ʱ����汾��ƥ�䡣
#define IPAC_DEV_IPCHAN_NOTALIVE			83	//Ԥ��ʱ���IPͨ�������ߡ�
#define IPAC_DEV_RTSP_SDK_ERROR				84	//���ر�׼Э��ͨѶ��StreamTransClientʧ�ܡ�
#define IPAC_DEV_CONVERT_SDK_ERROR			85	//����ת���ʧ�ܡ�
#define IPAC_DEV_IPC_COUNT_OVERFLOW			86	//��������IP����ͨ������
#define IPAC_DEV_PARAMMODE_ERROR			88	//ͼ����ǿ�ǣ�����ģʽ��������Ӳ������ʱ���ͻ��˽����������ʱ����ֵ����
#define IPAC_DEV_CODESPITTER_OFFLINE		89	//��Ƶ�ۺ�ƽ̨������������ߡ�
#define IPAC_DEV_BACKUP_COPYING				90	//�豸���ڱ��ݡ�
#define IPAC_DEV_CHAN_NOTSUPPORT			91	//ͨ����֧�ָò�����
#define IPAC_DEV_OLD_VERSIONS				92  //�����Ͼɣ��������


/*************************�豸���������� OP*******************************/
#define IPAC_DEV_UP_SOCKET					200	//���ͻ�������ݳ���
#define IPAC_DEV_UP_OPENFILE_ERROR			201	//�����ļ���ʧ��
#define IPAC_DEV_UP_FILE_ERROR				202	//�����ļ�����ȷ
#define IPAC_DEV_UP_SENDFILE				203	//�������豸�����ļ�ʧ��
#define IPAC_DEV_UP_SENDFILE_ERROR			204	//�����ļ�ʧ��
#define IPAC_DEV_UP_DEVUP					205	//�����豸����ʧ��
#define IPAC_DEV_UP_DEVUP_ERROR				206	//�豸����ʧ��
#define IPAC_DEV_UP_ENOTSUP					207 //�豸��֧�ָ�������ʽ
#define IPAC_DEV_UP_ERROR					208 //����
/*************************�豸���������� ED*******************************/



/*************************�����Խ������� OP*******************************/
#define IPAC_DEV_VOICE_OPEN					230	//�豸��Ƶû�д�
#define IPAC_DEV_VOICE_GETINFO				231	//�豸��Ƶû�д�
#define IPAC_DEV_VOICE_CONNECT				232 //�����豸�Խ�ʧ��
/*************************�����Խ������� ED*******************************/


/*************************�豸����״̬�� OP*******************************/
#define IPAC_DEV_UPSTATE_ERROR				0	//�������̳���
#define IPAC_DEV_UPSTATE_SENDFILE           1	//���ڷ����ļ�
#define IPAC_DEV_UPSTATE_SENDFILEEND		2	//�����ļ�����
#define IPAC_DEV_UPSTATE_UP					3	//���������豸
#define IPAC_DEV_UPSTATE_UPEND				4	//�豸�������
#define IPAC_DEV_UPSTATE_REBOOTFAIL			5	//�豸����ʧ��
/*************************�豸����״̬�� ED*******************************/



/**********************��̨�������� begin*************************/	

#define SET_PRESET		8	/* ����Ԥ�õ� */
#define CLE_PRESET		9	/* ���Ԥ�õ� */

#define PTZ_ZOOM_IN		11	/* �������ٶ�SS���(���ʱ��) */
#define PTZ_ZOOM_OUT	12	/* �������ٶ�SS��С(���ʱ�С) */
#define FOCUS_NEAR      13  /* �������ٶ�SSǰ�� */
#define FOCUS_FAR       14  /* �������ٶ�SS��� */
#define IRIS_OPEN       15  /* ��Ȧ���ٶ�SS���� */
#define IRIS_CLOSE      16  /* ��Ȧ���ٶ�SS��С */

#define TILT_UP			21	/* ��̨��SS���ٶ����� */
#define TILT_DOWN		22	/* ��̨��SS���ٶ��¸� */
#define PAN_LEFT		23	/* ��̨��SS���ٶ���ת */
#define PAN_RIGHT		24	/* ��̨��SS���ٶ���ת */
#define UP_LEFT			25	/* ��̨��SS���ٶ���������ת */
#define UP_RIGHT		26	/* ��̨��SS���ٶ���������ת */
#define DOWN_LEFT		27	/* ��̨��SS���ٶ��¸�����ת */
#define DOWN_RIGHT		28	/* ��̨��SS���ٶ��¸�����ת */
#define PAN_AUTO		29	/* ��̨��SS���ٶ������Զ�ɨ�� */

#define FILL_PRE_SEQ	30	/* ��Ԥ�õ����Ѳ������ */
#define SET_SEQ_DWELL	31	/* ����Ѳ����ͣ��ʱ�� */
#define SET_SEQ_SPEED	32	/* ����Ѳ���ٶ� */
#define CLE_PRE_SEQ		33	/* ��Ԥ�õ��Ѳ��������ɾ�� */
#define STA_MEM_CRUISE	34	/* ��ʼ��¼�켣 */
#define STO_MEM_CRUISE	35	/* ֹͣ��¼�켣 */
#define RUN_CRUISE		36	/* ��ʼ�켣 */
#define RUN_SEQ			37	/* ��ʼѲ�� */
#define STOP_SEQ		38	/* ֹͣѲ�� */
#define GOTO_PRESET		39	/* ����ת��Ԥ�õ� */


#define CLE_ALL_PRE_SEQ	44	/* ɾ��ָ����Ѳ������*/

/**********************��̨�������� end*************************/	



/*************************������������ begin*******************************/
//����IPAC_DEV_SetConfig��IPAC_DEVR_GetConfig,ע�����Ӧ�����ýṹ

#define IPAC_DEV_GET_DEVICECFG		100		//��ȡ�豸��������
#define IPAC_DEV_SET_DEVICECFG		101		//�����豸��������
#define IPAC_DEV_GET_NETCFG			102		//��ȡ�������
#define IPAC_DEV_SET_NETCFG			103		//�����������

#define IPAC_DEV_GET_CODERCFG		104		//��ȡ�������
#define IPAC_DEV_SET_CODERCFG		105		//���ñ������
#define IPAC_DEV_GET_CODER1CFG		106		//��ȡ�߼��������
#define IPAC_DEV_SET_CODER1CFG		107		//���ø߼��������

#define IPAC_DEV_GET_VIDEOCFG		108		//��ȡͼ�����
#define IPAC_DEV_SET_VIDEOCFG		109		//����ͼ�����
#define IPAC_DEV_GET_VIDEO1CFG		110		//��ȡ�߼�ͼ�����
#define IPAC_DEV_SET_VIDEO1CFG		111		//���ø߼�ͼ�����

#define IPAC_DEV_GET_AUDIOCFG		112		//��ȡ��Ƶ����
#define IPAC_DEV_SET_AUDIOCFG		113		//������Ƶ����

#define IPAC_DEV_GET_SYSCFG			114		//��ȡϵͳ����
#define IPAC_DEV_SET_SYSCFG			115		//����ϵͳ����

#define IPAC_DEV_GET_TIMECFG 		116		//��ȡ�豸ʱ��
#define IPAC_DEV_SET_TIMECFG		117		//�����豸ʱ��

#define IPAC_DEV_GET_OSDCFG 		120		//��ȡOSD����
#define IPAC_DEV_SET_OSDCFG			121		//����OSD����

#define IPAC_DEV_GET_RECORDYTPE		122		//��ȡ¼���ʽ
#define IPAC_DEV_SET_RECORDTYPE		123		//����¼���ʽ
#define IPAC_DEV_GET_RECORDCFG 		124		//��ȡ¼�����
#define IPAC_DEV_SET_RECORDCFG		125		//����¼�����

#define IPAC_DEV_GET_PTZCFG 		126		//��ȡPTZ����
#define IPAC_DEV_SET_PTZCFG			127		//����PTZ����

#define IPAC_DEV_GET_ALARMCFG 		128		//��ȡ�澯����
#define IPAC_DEV_SET_ALARMCFG		129		//���ø澯����

#define IPAC_DEV_GET_FTPCFG 		130		//��ȡFTP����
#define IPAC_DEV_SET_FTPCFG			131		//����FTP����

#define IPAC_DEV_GET_IDCFG 			140		//��ȡ�豸ID
#define IPAC_DEV_SET_IDCFG			141		//�����豸ID

#define IPAC_DEV_GET_CONFIGURECFG	142		//��ȡ�豸���ò���
#define IPAC_DEV_SET_CONFIGURECFG	143		//�����豸���ò���

#define IPAC_DEV_SET_PONTMAT		144		//����������
#define IPAC_DEV_GET_PONTMAT		145	    //��ȡ������

#define IPAC_DEV_SET_VMDCFG			146		//��ȡ�ƶ��������
#define IPAC_DEV_GET_VMDCFG			147	    //�����ƶ��������

#define IPAC_DEV_GET_NETCFGEX		148		//��ȡ�豸������չ��Ϣ
#define IPAC_DEV_SET_NETCFGEX		149		//�����豸������չ��Ϣ

#define IPAC_DEV_GET_P2PCFG			150		//��ȡ�豸P2P����������
#define IPAC_DEV_SET_P2PCFG			151		//�����豸P2P����������

#define IPAC_DEV_GET_DDNSCFG		152		//��ȡ�豸DDNS����������
#define IPAC_DEV_SET_DDNSCFG		153		//�����豸DDNS����������

#define IPAC_DEV_GET_28181CFG		154		//��ȡ�豸28181����
#define IPAC_DEV_SET_28181CFG		155		//�����豸28181����

#define IPAC_DEV_PTZ_PRESETPOINT_NAME 156	//Ԥ�õ���������
#define IPAC_DEV_PTZ_CONTROL		157		//�߼���������

#define IPAC_DEV_GET_WIFI			158		//��ȡwifi��Ϣ
#define IPAC_DEV_SET_WIFI			159		//����wifi

typedef enum  _ENCODE_VIDEO_TYPE
{
	FRAME_FLAG_VI=0x64,
	FRAME_FLAG_VP=0x65,
	FRAME_FLAG_VA=0x66,
}ENCODE_VIDEO_TYPE;

/*************************************************
�������ýṹ������
**************************************************/
#pragma pack(1)

/*
typedef struct Time_
{
	BYTE by;
	BYTE bM;
	BYTE bD;
	BYTE bH;
	BYTE bMm;
	BYTE bS;
}Time_;
*/

typedef struct _WW_FIELD_TIME
{
	unsigned int		nSecond : 6;	// ��: 0 ~ 59
	unsigned int		nMinute : 6;	// ��: 0 ~ 59
	unsigned int		nHour	: 5;	// ʱ: 0 ~ 23
	unsigned int		nDay	: 5;	// ��: 1 ~ 31
	unsigned int		nMonth  : 4;	// ��: 1 ~ 12
	unsigned int		nYear   : 6;	// ��: 2000 ~ 2063 
}WW_FIELD_TIME;

typedef union
{
	unsigned int	dwLongTime; // 32λ���η���
	WW_FIELD_TIME	stFieldTime; // �ṹ�������
}HH_TIME;

//size  64
typedef struct _RecodeHead
{
	char    szHead[4];//000002
	short	nVideoHeight; //��Ƶͼ���
	short	nVideoWidth;  //��Ƶͼ���

	HH_TIME  pStartTime;
	HH_TIME  pEndTime;
	char   szResd[48];//44];
}RecodeHead;


typedef struct _SetFontMat 
{
	unsigned char szText[20];
	unsigned char szData1[9][32];
	unsigned char szData2[9][128];
}SetFontMat;

//��Ƶ����֡ͷ  size = 16
typedef struct _IPAC_AVINFO
{
	//��Ƶ����
	char		  szHead[4];	//000003
	int			  nFrameSize;           //���ݴ�С
	char		  EncodeVideoType;
	char          szRese[7];
}IPAC_AVINFO,*pIPAC_AVINFO;

//�豸�������� , ���� 60
typedef struct
{
	BYTE sDEVName[NAME_LEN];     //�豸����
	//���²��ɸ���
	DWORD  dDEVType ;              //�豸����	
	BYTE   sDEVNO[SERIALNO_LEN];   //���к�
	DWORD  dAppVersion ;           //Ӧ�ð汾	
	DWORD  dAlgVersion ;           //�㷨�汾	
	DWORD  dWebVersion ;           //WEB�汾	
	DWORD  dKernelVersion ;        //�ں˰汾	
	DWORD  dBootVersion ;          //BOOT�汾			
	DWORD  dHardwareVersion ;      //Ӳ���汾

	char sAppVersionEx[60];			//Ӧ�ð汾��չ��Ϣ
	char sDEVTypeEx[16];
	BYTE sReserve[44];				//����
}IPAC_DEV_DEVICECFG, *LPIPAC_DEV_DEVICECFG;


typedef struct {		//��������� 28���£�58��
	DWORD IP;			//IP��ַ����λ��ǰ
	DWORD Mask;			//�������룬��λ��ǰ
	DWORD Gateway;		//���ص�ַ����λ��ǰ
	DWORD NameServer;	//������������ַ 
	WORD  HttpPort;		//Http�˿ں�
	WORD  RtspPort;		//RTSP�˿ں�
	UCHAR MAC[6];		//MAC��ַ����λ��ǰ (һ�㲻��Ҫ���ã����Ϊȫ0����)
	BYTE  Dhcp;			//Dhcp  =0 ��̬IP,  =1 ��̬
	BYTE  blank1;

	BYTE  blank2;
	BYTE  blank3;

	WORD  ControlPort;		//���ƶ˿�
	WORD  VideoPort;		//��Ƶ�˿�
	WORD  RtspPort2;		//Rtsp�˿�
	WORD  OnvifPort;		//Onvif�˿�

	BYTE  blank4[2];

	DWORD Dns;				//
	BYTE  Mode;				//Mode 
	BYTE  blank7;
	BYTE  blank8;
	BYTE  blank9;
	BYTE  blank5[10];
}IPAC_DEV_NETCFG, *LPIPAC_DEV_NETCFG;


/*
------------------------------------------------------------------------------------------
		 ���뷽ʽ	            ���ֱ���								�ӷֱ���
------------------------------------------------------------------------------------------
0x10     ��·H246			0	720(1280*720)						0	
0x11     ��·MPEG4     		1	D1(720*480)							0	
0x12	 ��·MJPEG     		2	SXGA(1280*1024)						0	
						 	3	1080(1920*1080)						0	
							4	3M									0	
------------------------------------------------------------------------------------------

0x23	H.264 + JPEG      	0	H264:720,JPEG:VGA					0	
							1	H264:D1,JPEG:D1						0	
							2	H264:720,JPEG:720					0	
------------------------------------------------------------------------------------------
                            0	H264:720,JPEG:VGA					0	
0x24	MPEG4 + JPEG     	1	H264:D1,JPEG:D1						0	
					    	2	H264:720,JPEG:720					0	
------------------------------------------------------------------------------------------
0x25	Dual H.264			0	H264:720, H264:CIF					0	
							1	H264:D1, H264:D1					0	
							2	H264:1080, H264:CIF					0	
------------------------------------------------------------------------------------------
0x26	Dual MPEG4 			0	MPEG4:720, MPEG4:CIF				0	
							1	MPEG4:D1, MPEG4:D1					0	
							2	MPEG4:1080, MPEG4:CIF				0	
------------------------------------------------------------------------------------------
0x27	H264 + MPEG4		0	H264:D1,MPEG4:D1					0	
------------------------------------------------------------------------------------------
0xA0	Dual H.264			0										0
0xA1	H.264 + JPEG		1	CIF									1	288*192
							2	VGA									2	320*192
							3	D1									3	QVGA
							4	720P								4	CIF
							5	960P								5	480*270
							6	1080P								6	640*360
							7	3M									7	VGA
							8	5M									8	D1
																	9	720P
																	10	1080P
------------------------------------------------------------------------------------------

*/
typedef struct {   // �豸����ģʽ  16
	UCHAR nEncode;		//���뷽ʽ, ����ѡ��·H246����·MPEG4��˫·H246��
	UCHAR Resolution;	//����ֱ���,����ѡ��720P��1280*960��D1��CIF��
	UCHAR ImageFlip;	//ͼ��ת��=0 Ϊ����ת��1 Ϊˮƽ����ת, 2Ϊ��ֱ��ʽ��ת��3Ϊˮƽ����ֱ����ת
	UCHAR Resolution2;	//����ֱ���,����ѡ��720P��1280*960��D1��CIF��

	UCHAR RateCtrol1;	//����һ���ʿ��ƣ�=0 Ϊ�رգ�=1 ΪVBR  =2ΪCBR
	UCHAR CodeRate1;	//����һ���ʣ���ΧΪ500-8000 kbps����������Ϊ��ʵ��ֵ/100��kbps
	UCHAR FrameRate1;	//����һ֡�ʣ�=0 Ϊ30��=1 Ϊ24  =2Ϊ15  =3Ϊ8
	UCHAR Quality1;		//����һ������=1-10 

	UCHAR RateCtrol2;	//���������ʿ��ƣ�=0 Ϊ�رգ�=1 ΪVBR  =2ΪCBR
	UCHAR CodeRate2;	//���������ʣ���ΧΪ500-8000 kbps����������Ϊ��ʵ��ֵ/100��kbps
	UCHAR FrameRate2;	//������֡�ʣ�=0 Ϊ30��=1 Ϊ24  =2Ϊ15  =3Ϊ8
	UCHAR Quality2;		//������������=1-10 

	//DWORD Blank2;
	UCHAR n264Encode;	//H264���뷽ʽ
	UCHAR IFrameGap;	//I֡���
	UCHAR Blank1;
	UCHAR Blank2;

	UCHAR MainMaxResolution; //���������֧�ֱַ���
	UCHAR SubMaxResolution;  //���������֧�ֱַ���
	UCHAR Blank3;
	UCHAR Blank4;

	UCHAR Blank5[26];
}IPAC_DEV_CODERCFG, *LPIPAC_DEV_CODERCFG;



typedef struct {     //�豸�߼�����ģʽ , 20
	UCHAR IpRatio1;	 //��1 IP Ratio, 1-30��30��
	UCHAR fIframe1;	 //��1 ǿ��I֡,   1Ϊѡ��,
	UCHAR qpInit1;	 //��1 QP ��ʼֵ��1-51��28��,
	UCHAR qpMin1;	 //��1 QP ��Сֵ��1-51��1��,
	UCHAR qpMax1;	 //��1 QP ���ֵ��1-51��51��,
	UCHAR meConfig1;	 //��1 Encode Preset , 0-AUTO  1-CUSTOM  2-SVC ��0,
	UCHAR packetSize1;	 //��1 Packet Size  1-100��100����λ��%��,
	UCHAR Blank1;
 	WORD Blank2;

	UCHAR IpRatio2;	 //��2 IP Ratio, 1-30��30��
	UCHAR fIframe2;	 //��2 ǿ��I֡,   1Ϊѡ��,
	UCHAR qpInit2;	 //��2 QP ��ʼֵ��1-51��28��,
	UCHAR qpMin2;	 //��2 QP ��Сֵ��1-51��1��,
	UCHAR qpMax2;	 //��2 QP ���ֵ��1-51��51��,
	UCHAR meConfig2;	 //��2 Encode Preset , 0-AUTO  1-CUSTOM  2-SVC ��0,
	UCHAR packetSize2;	 //��2 Packet Size  1-100��100����λ��%��,
	UCHAR Blank21;
 	WORD Blank22;
}IPAC_DEV_CODER2CFG, *LPIPAC_DEV_CODER2CFG;


typedef struct {    // �豸ͼ�����  17
	UCHAR nBright;		//���ȣ���ΧΪ1-100
	UCHAR nContrast;	//�Աȶȣ���ΧΪ1-100
	UCHAR nSaturat;		//���Ͷȣ���ΧΪ1-100
	UCHAR nSharpen;		//�����ȣ���ΧΪ1-100
	UCHAR bPAL;			//������ʽ��=0 ΪNTSC/60HZ��=1 ΪPAL/50HZ
	UCHAR bIRCut;		//�˹�Ƭģʽ = 0�Զ�  =1 ����  =2 ����  =3 ��ʱ�л�  =4 io_in����
	UCHAR bColor;		//����ͼ��  = 0��ɫ  =1 �ڰ�
    UCHAR bBLC;			//���ⲹ����=0 ��  =1 С  =2 ��  =3 ��
	UCHAR bOpenWB;		//��ƽ����أ�=0 Ϊ�رգ�	  =1 ΪAE      =2 ΪAEW    =3 ΪAEWB
	UCHAR bModeWB;		//��ƽ��ģʽ��=0 �Զ���	  
	UCHAR bIntelNoise;		//���ܽ��� 0 Ϊ�ر�           =1 SNF	=2 ΪTNF          =3 SNF+TNF
	UCHAR bWidedynamic;		//��̬���ܣ�=0 Ϊ�ر�           =1 Ϊ��

	UCHAR WidedynamicRange; //��̬��Χ     1-10
	UCHAR IntelNoiseLevel;  //���ܽ���ȼ�   10-13��Ӧ �Զ����͡��С���
	UCHAR Blank1;
	UCHAR Blank2;
	UCHAR Out;        //�������     =10�رգ�=11 NTSC =12 PAL

	UCHAR Noise;      //���    ��ΧΪ1-100
	UCHAR ExposureBiasValue;//�عⲹ��    ��ΧΪ1-100
	UCHAR Blank3;

	UCHAR ImageFlip;  //ͼ��ת   =10Ϊ����ת�� =11Ϊˮƽ����ת   =12Ϊ��ֱ��ʽ��ת��  =13Ϊˮƽ����ֱ����ת
	UCHAR Blank4;

	UCHAR NightToDay_hour;	//�ڰ�ת��ɫʱ���
	UCHAR NightToDay_minute;
	UCHAR DayToNight_hour;	//��ɫת�ڰ�ʱ���
	UCHAR DayToNight_minute;

	UCHAR LevelToNight;     //=11 �ߵ�ƽת�ڰ�  =12 �͵�ƽת�ڰ�

	UCHAR Blank5[20];

}IPAC_DEV_VIDEOCFG, *LPIPAC_DEV_VIDEOCFG;


//�澯��Ϣ
typedef struct AramInfo 
{
	BYTE bcameStat;
	BYTE bcamestat2;
	BYTE bAraminput;
	BYTE bAramoutput;//Ӳ���澯
	BYTE bAram1;//����澯��Ϣ
	BYTE bAram2;
}AramInfo;

/*
����ʱ��	ShutTime
1/50000	0
1/20000	1
1/10000	2
1/5000	3
1/2000	4
1/1000	5
1/500	6
1/250	7
1/200	8
1/125	9
1/100	10
1/50	11
1/25	12��Ĭ�ϣ�
1/20	13
1/15	14
1/13	15
1/10	16
1/5		17


*/

typedef struct {    // �豸�߼�ͼ�����  14
	UCHAR PriorMode;	//����ģʽ�� =0 Ϊ�ٶ����ȣ�		=1 Ϊ��������
	UCHAR ShutTime;		//������ʱ�� �����嶨��μ���
	UCHAR MaxGain;		//������棬0-100
	UCHAR Blank1;

    UCHAR Light_control; //ǿ������
	UCHAR RangeWDR;		//��̬��Χ����ΧΪ1-10
	UCHAR nNoise;		//������	��ΧΪ1-100
	UCHAR nEV;		    //EV��������ΧΪ1-100

 	WORD Blank2;
	DWORD Blank3;

}IPAC_DEV_VIDEO2CFG, *LPIPAC_DEV_VIDEO2CFG;



typedef struct {    // �豸��Ƶ����  12
	UCHAR audioON;	  //��Ƶ���� =0 Ϊ�ر���Ƶ��	=1 Ϊ����Ƶ
	UCHAR audiomode;		//��Ƶģʽ��=0 ����  =1 ���  =2��������
	UCHAR audioinvolume;		//�������棬0-100��85��
	UCHAR codectype;			//��Ƶ���룬1-G711, 2-AAC-LC��

    UCHAR samplerate; //����Ƶ�ʣ�0-8Khz, 1-16Khz
	UCHAR bitrate;		//�������ʣ�0-64Kbps
	UCHAR audiooutvolume;		//���������0-100��75��
	UCHAR alarmlevel;		    //�澯������0-100��50��

 	WORD Blank1;
	WORD Blank2;

}IPAC_DEV_AUDIOCFG, *LPIPAC_DEV_AUDIOCF;


typedef struct {     // �豸����ģʽ  12  2.0-new-42
	UCHAR AFMinDist;    //AF��С����  10-�Զ�
	UCHAR AFMaxDist;    //AF������  10-�Զ�
	UCHAR AFWorkMode1;	//AF����ģʽ1 
	                    //BIT0=0Ϊ�رգ�=1Ϊ�����Զ��Խ�
	                    //BIT1=0Ϊ�رգ�=1Ϊ��ת����ǿ�ƶԽ�
	                    //BIT2=0Ϊ�رգ�=1Ϊ��Ԥ��λ�󲻶Խ�
	                    //BIT3=0Ϊ�رգ�=1ΪѲ��ʱ���Խ�
	                    //BIT7=0Ϊ�رգ�=1Ϊ�������ַŴ�

	UCHAR AFWorkMode2;	//AF����ģʽ2
						//BIT0��1= �Խ�������
						//BIT2 �Խ�����ѡ��
						//BIT3 Ԥ��λ���÷�ʽ
						//BIT4 �Խ���ʽ
						//BIT7 IR-CUT��ת

	UCHAR BWSthPoint;	//��ɫ���ڰ׵��л��㣬��ΧΪ1-25
	UCHAR ClrSthPoint;	//�ڰ׵���ɫ���л���, ��ΧΪ5-35����һ��Ҫ����Data5��
	DWORD IP;			//������IP��ַ
	WORD  port;			//�������˿ں�

	UCHAR ControlMode;  //������Ʒ�ʽ      10 �Զ�  11 �����ڿ���ģʽ  12 ˫���ڿ���ģʽ
	UCHAR PTZCmdForward;//PTZ����ת������� 10 �ر�  11 ��
	UCHAR SpecialPreset;//����Ԥ��λ����    10 Ĭ��  11 ������

	UCHAR Blank1[4];

	UCHAR PWCutMemory;  //�ϵ���� 10�ر�   11��
	UCHAR PowerOnACT;   //�ϵ綯�� 10�ر�   11Ԥ�õ�  12 Ѳ��
	UCHAR PowerOnACT2;  //Ԥ�õ�� 1-128��Ѳ��ʱ1-8��
	UCHAR LeisureACT;   //���ж��� 10�ر�   11Ԥ�õ�  12 Ѳ��
	UCHAR LeisureACT2;  //Ԥ�õ�� 1-128��Ѳ��ʱ1-8��

	UCHAR Blank[18];
}IPAC_DEV_SYSCFG, *LPIPAC_DEV_SYSCFG;



typedef struct {     // �豸ʱ���豸  6
	UCHAR Second;		//������������ΧΪ0-59
	UCHAR Minute;		 //������������Χ0-59			
	UCHAR Hour;			//ʱ����������ΧΪ0-23
	UCHAR Day;			//��������Χ01-31
	UCHAR Month;		//�·ݣ���Χ��1-12
	UCHAR Year;			//��������1900 ���������������
}IPAC_DEV_TIMECFG, *LPIPAC_DEV_TIMECFG;



typedef struct {       //// �豸OSD   20
	UCHAR bShowTime;	//��ʾʱ�� =0 Ϊ����ʾ��=1 Ϊ��ʾ
	UCHAR TimeFormat;	//��ʾʱ���ʽ, =0 Ϊ��/��/��  =1 Ϊ��/��/�� =2 Ϊ��/��/��			
	UCHAR bShowStr1;	//��ʾ�ַ���1 =0 Ϊ����ʾ; =1 Ϊ��ʾ
	UCHAR bShowRate;	//��ʾ����, =0 Ϊ����ʾ;=1 Ϊ��ʾ
	
	char str1[32];
	char str2[32];

	char time_show_pos;      //timeλ��   10-Ĭ��  11-����  12-����  13-����   14-����   15-�Զ���
	char time_show_pos_x;    //timeλ���Զ���  x
	char time_show_pos_y;    //timeλ���Զ���  y
	char time_show_color;    //time��ɫ

	char str1_show_pos;      //str1λ��   10-Ĭ��  11-����  12-����  13-����   14-����   15-�Զ���
	char str1_show_pos_x;    //str1λ���Զ���  x
	char str1_show_pos_y;    //str1λ���Զ���  y
	char str1_show_color;    //str1��ɫ

	char rate_show_pos;      //rateλ��   10-Ĭ��  11-����  12-����  13-����   14-����   15-�Զ���
	char rate_show_pos_x;    //rateλ���Զ���  x
	char rate_show_pos_y;    //rateλ���Զ���  y
	char rate_show_color;    //rate��ɫ

	char blank[16];
}IPAC_DEV_OSDCFG, *LPIPAC_DEV_OSDCFG;


/*
typedef struct {	// �豸ID   20

}IPAC_DEV_IDCFG, *LPIPAC_DEV_IDCFG;
*/

typedef struct{		// �����¼���ʽ   6
	UCHAR bStream;      //=0 ��Ƶ��1��	=1 Ϊ��Ƶ��2 
	UCHAR Reserd[5];
}IPAC_DEV_RECORDTYPE, *LPIPAC_DEV_RECORDTYPE;

typedef struct{		// �����¼������  16
	UCHAR bRecord;      //�Ƿ񱣴�¼��SD��    =0 Ϊ�����棻		=1 Ϊ����
	UCHAR RecordNo;		//�ƻ��ŷ�Χ��0-6
	UCHAR RecordPloy;   // ¼����ԣ�=0 ��¼��  =1Ϊ���ƻ�¼��
	UCHAR RecordWeek;	//��ʼ����
	UCHAR beginHour;	//��ʼСʱ
	UCHAR beginMinute;	//��ʼ����
	UCHAR beginSecond;	//��ʼ����
	UCHAR endHour;
	UCHAR endMinute;
	UCHAR endSecond;
	UCHAR Reserd[6];
}IPAC_DEV_RECORDCFG, *LPIPAC_DEV_RECORDCFG;


typedef struct {	//ftp������ , 50
	DWORD IP;			//IP��ַ����λ��ǰ
	WORD  Port;			//�˿ںţ���λ��ǰ
	char  user[6];		//�û�������λ��ǰ
	char  Pwd[6];		//���룬��λ��ǰ
	UCHAR Reserd[2];

	char  sntp[30];    // SNTP ��������ַ����λ��ǰ
}IPAC_DEV_FTPCFG;



typedef struct {	// �澯����  40
    UCHAR IO_InAlarm;        //IO_IN�澯���� 10-�ر�  11-��
    UCHAR IO_InTriggerLevel; //IO_IN������ƽ 10-�͵�ƽ���� 11-�ߵ�ƽ����
    UCHAR VideoLose;         //��Ƶ��ʧ   =10�������� =11Ϊ����
    UCHAR NetLose;           //�������   =10�������� =11Ϊ����
    UCHAR MotionDetection;   //�ƶ����   =10�������� =11Ϊ����
    UCHAR IO_OutAlarm;       //IO�澯��� =10Ϊ�رգ� =11Ϊ��
    UCHAR IO_OutTriggerLevel;//IO_OUT 0-�澯����͵�ƽ 1�澯����ߵ�ƽ
    UCHAR OutputDelay;       //�����ʱ 10-5S 11-10S 12-30S 13-1M 14-5M 15=10M 16=һֱ
    UCHAR AlarmSound;        //�澯���� 10�رգ�11��
    UCHAR AlarmSave;         //�澯�洢 10�رգ�11��
    UCHAR AlarmSaveToFtp;    //�澯FTP  10�رգ�11��
    UCHAR AlarmSaveToSMTP;   //�澯SMTP 10�رգ�11��
    UCHAR AlarmPreset;       //�澯Ԥ�õ� 10�رգ�11��
    UCHAR AlarmPresetNumber; //Ԥ�õ��
    UCHAR AlarmCruise;       //�澯Ѳ�� 10�رգ�11��
    UCHAR AlarmCruiseNumber; //Ѳ����·

	UCHAR Blank[24];
}IPAC_DEV_ALARMCFG, *LPIPAC_DEV_ALARMCFG;


typedef struct {	// PTZ����  12
	UCHAR bNum;  // ���ں� 10.����0   1.����1   Ĭ�ϣ�����1
	UCHAR Baud;   // ���ڲ����� //115200 =10  57600 =9   38400=8,  19200=7,  9600=6, 4800=5, 2400 =4, 1200 = 3,  600=2  300=1
	UCHAR Begin;  // ������ʼλ��
	UCHAR End;	 //  ����ֹͣλ��  //0-1, 1-1.5 , 2-2
	UCHAR Check;		// 	����У��      //0-none ,1-odd , 2-even
	UCHAR Data;		//  ��������λ��  //5-8
	UCHAR qj_add;	//  �����ַ
	UCHAR Protocol1; // ���Э��
	UCHAR Protocol2; // �����չЭ��

	UCHAR Reserd[3];

	UCHAR Num0Mode;  //����0����ģʽ   10-Ĭ��
	UCHAR Num0Protocol; //����0Э��    10-SONYЭ��
	UCHAR Num0Baud;     //����0������  115200 =19  57600 =18   38400=17,  19200=16,  9600=15, 4800=14, 2400 =13, 1200 = 12,  600=11  300=10
	UCHAR Num0Begin;    //����0��ʼλ��
	UCHAR Num0End;      //����0ֹͣλ��  //0-1, 1-1.5 , 2-2
	UCHAR Num0Check;    //����0У��      //0-none ,1-odd , 2-even
	UCHAR Num0Data;     //����0����λ��  //5-8
	UCHAR Num0Blank;
	UCHAR Blank[12];
}IPAC_DEV_PTZCFG, *LPIPAC_DEV_PTZCFG;



typedef struct {	// SD����
	UCHAR DATA1;		//
	UCHAR DATA2;		//
	UCHAR DATA3[4];
}IPAC_DEV_SDCFG, *LPIPAC_DEV_SDCFG;

typedef struct {    // SD��������
	UCHAR Order;
	UCHAR Blank[63];
}IPAC_DEV_SDOPERATE, *LPIPAC_DEV_SDOPERATE;

typedef struct {   //SD���ļ��б�
	char FileName[50]; // �ļ���
	char FileDate[15]; // ����
	char FileTime[10]; // ʱ��
	char FileSize[20]; // ��С

}IPAC_DEV_SDFILEINFO, *LPIPAC_DEV_SDFILEINFO;

typedef struct {	// ��ȡSD����Ϣ
	BYTE State;		// =0û��SD����=1Ϊ�Ѳ��룬=2Ϊ�ѹ��أ�=3Ϊ�Ѳ��벢����
	BYTE Usage;		// ������0-100
	WORD Capacity;	// ����
	BYTE FileCount; // �ļ�����,IPAC_DEV_SDFILEINFO�ṹ

}IPAC_DEV_SDCARDINFO, *LPIPAC_DEV_SDCARDINFO;



typedef struct{  // �����������
	UCHAR Command1;
	UCHAR Command2;
	WORD Command3;
}IPAC_DEV_UPDATE, *LPIPAC_DEV_UPDATE;



typedef struct{		//��̨Ѳ���������� 
	UCHAR	Cmd;		//Cmd:  30-��Ԥ�õ����Ѳ������, 44-ɾָ����Ѳ��·��,33-��Ԥ�õ��Ѳ��������ɾ��,  37-��ʼѲ��, 38-ֹͣѲ��
	UCHAR	nLine;		//nLine: Ѳ����· 1-8
	UCHAR	nPoint;		//nPoint: Ѳ����  1-16
	UCHAR	nPreset;	//nPreset: ��Ӧ��Ԥ�õ� 1-127
	UCHAR	nSpeed;     //nSpeed:  �ٶ�  1-8
	UCHAR	nTime;		//nTime:   ʱ��  1-255
}IPAC_DEV_CRUISE, *LPIPAC_DEV_CRUISE;


typedef struct{		//����ͷ��ʼ������
	UCHAR	bZoomInit;	//Zomm: 0 Ϊ����ʼ����1 Ϊ��ʼ��
	UCHAR	nZoomType;	//Zoom: 1 Ϊ����㣻 2 Ϊ����СZOOM
	UCHAR	bAFInit;	//AF: 0 Ϊ����ʼ����1 Ϊ��ʼ��
	UCHAR	nAFType;	//AF��ʼ�����ͣ�=1 Ϊ����㣻 =2 Ϊ����СAF
}IPAC_DEV_LENSINIT;



typedef struct{		//��Ӧ��ͷ����
	UCHAR	bOK;		//���״̬ =0�ɹ���	=1 ����
	WORD	nZoomPos;	//ZOOM��ǰλ��
	WORD	nFocalPos;	//AF��ǰλ��
	UCHAR	nZSection;	//ZOOM��ǰλ�õĶ���
	UCHAR	aperPos:4;	//BIT4-1��ͷ��ǰ��Ȧλ�ã�
	UCHAR	nighPos:4;	//BIT8-5��ͷ��ǰ��ҹλ��
	UCHAR	state;		//��ͷ״̬ >0 ʱ����
}IPAC_DEV_LENSRESP;


typedef struct{		//�����Զ��Խ�����
	UCHAR	nType;		//�������ͣ�1-5Ϊָ����Ȧ��ǰ�򿪵Ĵ�С��0x10Ϊ����
	UCHAR	nHValue;
	UCHAR	nLValue;		//��������
}IPAC_DEV_LENSREQU;



//����ͷ������ҹģʽ
typedef struct{
	UCHAR  FilterMode;
	UCHAR  Reversed;
	UCHAR  ImageColor;
}IPAC_DEV_LENSIRCTU;




typedef struct {	//������Ӧ�� , 64+30

	DWORD IP;			//IP��ַ����λ��ǰ
	DWORD Mask;			//�������룬��λ��ǰ
	DWORD Gateway;		//���ص�ַ����λ��ǰ
	UCHAR MAC[6];		 //MAC��ַ��
	BYTE  sDEVName[NAME_LEN];     //�豸����
	DWORD dDEVType ;              //�豸����	
	BYTE  sDEVNO[SERIALNO_LEN];   //���к�
	DWORD dAppVersion ;           //Ӧ�ð汾
	DWORD dRunTime ;
	WORD  dPort;

	WORD  dVideoPort;	//
	BYTE  sBlank1[4];
	char  sDEVTypeEx[16];
	BYTE  sBlank2[8];
	
}IPAC_DEV_SEARCH;

#define MAX_CRUISE_POINT 16

typedef struct _CruisePoint
{
	BYTE Flag; //1 yes 0 no
	BYTE PresetNum;
	BYTE speed	;
	BYTE Time;
}tagCruisePoint;


typedef struct _tagCruiseGroup
{
	BYTE Flag;  //0
	BYTE Blank1; 
	tagCruisePoint stPoint[MAX_CRUISE_POINT];
}tagCruiseGroup;

typedef struct _tagBroadcaseChange
{
	DWORD dwDevIP;
	DWORD dwDevMask;
	DWORD dwGateway;
	DWORD dwDomainServer;
	WORD  httpPort;
	WORD  httpsPort;
	UCHAR szDevMAC[6];
	BYTE  byDHCP;

	char szRes[3];
	DWORD dwUpDevType;//ԭ����Ϣ
	BYTE  byUpDevNo[16];
	DWORD dwUpDevIP;
	UCHAR szUpDevMAC[6];
	WORD  szRevPort;
}tagBroadcaseChange;  

#pragma pack()
//==================================================================================================================================frank 


//ʵʱԤ�������ṹ
typedef struct{ 
	LONG    lChannel;   //1Ϊ��������2Ϊ������
	LONG    lLinkMode;  // ���ӷ�ʽ��0��TCP��ʽ��1��UDP��ʽ��2���ಥ��ʽ��3��RTP��ʽ
	HWND    hPlayWnd;   //���Ŵ���
    char    *sMultiCastIP;
	WORD    nVideoPort; //Ϊ0ʹ��Ĭ�ϣ� ���ӷ�ʽΪTCP��UDPʱ��Ч
} IPAC_DEV_CLIENTINFO, *LPIPAC_DEV_CLIENTINFO;


//��̨ͼ������λ����Ϣ
typedef struct{
  int    xTop;
  int    yTop;
  int    xBottom;
  int    yBottom;
  int    bCounter;
} IPAC_DEV_POINT_FRAME, *LPIPAC_DEV_POINT_FRAME;


//�ƶ�������
typedef struct{
	UCHAR bOpen;		//�Ƿ���
	UCHAR Sensitivity;	//������ѡ��0.���ȼ�  1.��ϸ�֣�
	UCHAR Rank;			//�����ȵȼ�
	UCHAR Subdivs;	//ϸ��������
			

	UCHAR sBlock[8];	//������ã�ÿ���ֽڶ�Ӧһ�к�飬ÿ��λ��Ӧһ����飩=1 ������ =0 �ر�
						//����ֻ֧��3��4�е�����
	UCHAR Blank[38];
} IPAC_DEV_VMDCFG, *LPIPAC_DEV_VMDCFG;

//�豸������չ��Ϣ
typedef struct{
	WORD  ContorlPort; //���ƶ˿�
	UCHAR bCheck;      //RTSP�����Ƿ���Ҫ��֤ 10-����Ҫ��11-��Ҫ
	UCHAR PacketSize;  //RTSP���ʰ���С�� 10-С����11-���
	UCHAR URL;	       //����URL�� 10-WWA,11-WWA1,12-HK,13-UC
	UCHAR Mode;        //RTSP�鲥ģʽ 10-������ 11 �鲥
	UCHAR NvrVendor;        //NVR���� 10-Ĭ�ϣ�11-������12-�󻪣�13���ΰҵ��14-����߿ƣ�15-������16-��ά
	UCHAR Blank[3];

	UCHAR bUPNP;       //UPNP���� 10-�رգ�11-��
	UCHAR Blank2[9];

	UCHAR bADSL;       //ADSL���� 10-�رգ�11-��
	UCHAR Blank3;
	char  Username[16];	//�û���
	char  Password[16];	//���� 
	UCHAR Blank4[6];

	UCHAR bSNTP;        //SNTP���� 10-�رգ�11-��
	UCHAR Blank5;
	char  SNTPServerAddr[32];  //��������ַ
	WORD  SNTPServerPort;	   //�˿�
	UCHAR SNTPTimingInterval;  //Уʱ���
	UCHAR Blank6[3];

	UCHAR bSMTP;               //SMTP���� 10-�رգ�11-��
	UCHAR Blank7;
	char  SMTPServerAddr[32];  //��������ַ
	char  SMTPSenderAddr[32];  //�ļ��˵�ַ
	char  SMTPRecverAddr[32];  //�ռ��˵�ַ
	char  SMTPUsername[16];    //�û���
	char  SMTPPassword[16];	   //����

	UCHAR Blank8[282];
}IPAC_DEV_NETCFGEX, *LPIPAC_DEV_NETCFGEX;


//P2P��������Ϣ
typedef struct{
	UCHAR Vender;
	UCHAR bOpen;

	char ServerAddr1[40];
	char ServerAddr2[40];
	char UserName[16];
	char Password[16];

	UCHAR ID[20];
	WORD  wPort;

	UCHAR Blank2[32];
}IPAC_DEV_P2PCFG, *LPIPAC_DEV_P2PCFG;

typedef struct
{
	BYTE Order;				//=1 ��ʼ�Խ��� =2 �����Խ���=3����
	BYTE VoiceFormat;		//=1 wav�� =2 G711
	BYTE MainDevType;		//=1 PC, =2 NVR, =3�ֻ�
	BYTE Protocol;			//=1  TCP,  =2 UDP

	UINT nSamplesPerSec;	//ȡ����
	UINT nBitsPerSample;	//ȡ��λ��
	WORD wPort;				//�˿ں�

	WORD wBlank;
}IPAC_DEV_VOICECOMCFG, *LPIPAC_DEV_VOICECOMCFG;

//DDNS��������Ϣ
typedef struct{
	BYTE bOpen;
	BYTE bUpdateInterval;
	BYTE bBlank1;
	BYTE bBlank2;

	char DDNSAddr[32];
	char UserName[16];
	char Password[16];
	
	char Blank[444];
}IPAC_DEV_DDNSCFG, *LPIPAC_DEV_DDNSCFG;


//28181  byte:320
typedef struct{
	BYTE Open; //10-�رգ�11-��
	BYTE Stream;//10-������, 11-������

	char sServerIP[32]; //������IP
	char wServerPort[2];   //�������˿�
	char sServerID[32]; //������ID

	char sRegisterDomain[32]; //ע����
	char sUsername[32];       //�û���
	char sPassword[32];       //����
	WORD wRegisterWaitTime;   //ע�ᳬʱ��s��
	WORD wHeartbeatCycle;     //�������ڣ�s��
	char sBlank[31];

	char sDevID[32];		  //�豸ID
	char wDevPort[2];			  //�豸�˿�
	char sAlarmID[32];		  //�����˿�

	char sBlank2[55];
}IPAC_DEV_28181CFG, *LPIPAC_DEV_28181CFG;

//Ԥ�õ�����   byte:40
typedef struct  
{
	BYTE Order;			//1.��ȡ  2.����
	BYTE PresetPoint;	//Ԥ�õ�
	char Blank[8];

	char Name[20];		//Ԥ�õ�����
	char Blank2[10];
}IPAC_DEV_PRESETPOINT_NAMECFG, *LPIPAC_DEV_PRESETPOINT_NAMECFG;

//��̨�߼���������  byte:30
typedef struct
{
	BYTE MainOrder;	//������
	BYTE SubOrder;	//������
	BYTE Speed;		//�ٶ� ȡֵ��Χ[1,8]
	BYTE Blank;

	BYTE PresetPoint1;	//Ԥ�õ�
	BYTE Order1;		//10-���ã�11-����
	BYTE PresetPoint2;	//Ԥ�õ�2
	BYTE Order2;		//10-���ã�11-����

	BYTE Blank2[22];
}IPAC_DEV_PTZ_HIGHERCFG, *LPIPAC_DEV_PTZ_HIGHERCFG;
/*
��ϸ���������
	10 ��ʾʱ��
	11 ����ʾʱ��
	12 ��ʾ����
	13 ����ʾ����
	25 ������ģʽ
	26 ˫����ģʽ
	30 ��ͷ��ʼ��
	31 ���Ԥ�õ�
	32 ��о�ָ���������
	33
	34 ��о����
	50 ��ɨ��
	51 ��ɨ��
	52 ��ɨ���
	53 ��ɨ�յ�
	55 �ƹ�ǿ
	56 �ƹ���
	57 �ƹ���
	60 ��ˢ��
	61 ��ˢ��
	70 ��ɫ�ڰ��Զ�
	71 ��ɫģʽ
	72 �ڰ�ģʽ
*/

typedef struct
{
	char  ssid[32]; //ssid 
	char  pwd[32];	//�ѱ�������
//64
	unsigned short speed;    //����
	unsigned char  wm; 		//����ģʽ01: manage�� 02: ad-hoc
	unsigned char  sm;	    //��ȫģʽ 01�������� 02��wep,  03:  wpa-psk  04: wpa-enterprise , 05: wpa2-psk 06: wpa2-enterprise
	unsigned char  cid;      //ͨ����
	unsigned char  strength; //�ź�ǿ��
	short  rev;
//72
}IPAC_DEV_WIFI_INFO, *LPIPAC_DEV_WIFI_INFO;

typedef struct
{
	char open;		//wifi����  10.��  11.��
	char dhcp;
	char wifi_count;	//���õ�wifi����
	char connect;	//wifi����״̬  10.δ����  11.������

	unsigned int ip;
	unsigned int mask;
	unsigned int gateway;
	unsigned int dns;
	
	unsigned char mac[6];
	char blank3[2];

	IPAC_DEV_WIFI_INFO info1; //�����ӵ�wifi

	IPAC_DEV_WIFI_INFO info2[20]; //wifi�б�
}IPAC_DEV_WIFI_GET, *LPIPAC_DEV_WIFI_GET;

typedef struct//180
{
	char open;		//wifi����   10.��  11.��
	char dhcp;
	char blank1[2];

	unsigned int ip;
	unsigned int mask;
	unsigned int gateway;
	unsigned int dns;
	char blank2[8];

	IPAC_DEV_WIFI_INFO info1;	//���ӵ�wifi

	char blank3[80];
}IPAC_DEV_WIFI_SET, *LPIPAC_DEV_WIFI_SET;


//--------------------------------------------------------------- ��ʼ��SDK����������SDK������ǰ��   
/*
//TRUE��ʾ�ɹ���FALSE��ʾʧ��
*/
IPAC_API  BOOL   WINAPI IPAC_DEV_Init();
IPAC_API  BOOL   WINAPI IPAC_DEV_Cleanup();


//----------------------------------------------------------------  �û�ע���豸
/*
Parameters
sDVRIP 
[in] �豸IP��ַ 
wServerPort 
[in] �豸�˿ں� 
sUserName 
[in] ��¼���û��� 
sPassword 
[in] �û����� 
lpDeviceInfo 
[out] �豸��Ϣ 
*/
IPAC_API  ULONG  WINAPI  IPAC_DEV_Login(const char *ip_addr, int port, const char *user_name, const char *user_pwd, UCHAR bRelay);
IPAC_API  BOOL   WINAPI  IPAC_DEV_Logout(ULONG    lUserID);

//--------------------------------------------------------------  �쳣��Ϣ�ص�
typedef BOOL (WINAPI *MESSAGE_CALLBACK)(int nType,void *pParam,int nLen,void *context);
typedef BOOL (WINAPI *STREAM_CALLBACK)(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
typedef BOOL (WINAPI *CHANNEL_STREAM_CALLBACK)(LONG lRealHandle,DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);

typedef struct _RtspRealStream
{
	DWORD dwPort;
	char  szDevIp[32];
	char  szDevUserName[32];
	char  szDevPwd[32];
	char  szRtspPath[MAX_PATH];
	STREAM_CALLBACK pCallback;
}RtspRealStream;

//---------------------------------------------------------------   ʵʱԤ��
/*
//typedef void(*fRealDataCallBack_V30)(  LONG     lRealHandle,  DWORD    dwDataType,  BYTE      *pBuffer,  DWORD     dwBufSize,  void      *pUser);
/* ʵʱԤ����
Parameters
lUserID 
[in] IPAC_DEV_Login�ķ���ֵ 
lpClientInfo 
[in] Ԥ������ 
cbRealDataCallBack 
[in] �������ݻص����� 
pUser 
[in] �û����� 
bBlocked 
[in] �������������Ƿ�������0����1���� 
*/

IPAC_API LONG  WINAPI IPAC_DEV_RealRtsp(RtspRealStream stRtspStream,void  *pUser);

IPAC_API LONG  WINAPI IPAC_DEV_RealPlay(ULONG UserID, LPIPAC_DEV_CLIENTINFO lpClientInfo, STREAM_CALLBACK callback, void  *pUser, BOOL  bBlocked);
//  lRealHandle    IPAC_DEV_RealPlay�ķ���ֵ 
IPAC_API BOOL  WINAPI IPAC_DEV_StopRealPlay( LONG    lRealHandle);

IPAC_API BOOL  WINAPI IPAC_DEV_ClientGetVideoEffect(LONG   lRealHandle,  DWORD  *pBrightValue,  DWORD  *pContrastValue,  DWORD   *pSaturationValue,  DWORD   *pHueValue);
IPAC_API BOOL  WINAPI IPAC_DEV_ClientSetVideoEffect(LONG   lRealHandle,  DWORD   dwBrightValue, DWORD   dwContrastValue, DWORD    dwSaturationValue, DWORD    dwHueValue);

IPAC_API BOOL  WINAPI IPAC_DEV_OpenSound( LONG  lLoginID, LONG lVolume);
IPAC_API BOOL  WINAPI IPAC_DEV_CloseSound( LONG  lLoginID);

//IPAC_API BOOL IPAC_DEV_SaveRealData(  LONG    lRealHandle,  char    *sFileName);
// IPAC_API BOOL IPAC_DEV_StopSaveRealData( LONG  lRealHandle);

IPAC_API ULONG WINAPI  IPAC_DEV_GetDecoderHandle( LONG    lRealHandle);
IPAC_API BOOL  WINAPI  IPAC_DEV_CapturePicture(LONG  lRealHandle,  char *sPicFileName);

IPAC_API BOOL  WINAPI IPAC_DEV_StartRecord(ULONG lRealHandle,const char *csFileName);
IPAC_API BOOL  WINAPI IPAC_DEV_StopRecord(ULONG lRealHandle);

IPAC_API BOOL  WINAPI IPAC_DEV_CheckPlayStatus(ULONG lRealHandle);


//--------------------------------------------------------  PTZ����
/*
lUserID 
[in] IPAC_DEV_Login�ķ���ֵ 
dwPTZCommand 
[in] ��̨����������±� 
ZOOM_IN 11 ������(���ʱ��) 
ZOOM_OUT 12 �����С(���ʱ�С) 
FOCUS_NEAR 13 ����ǰ�� 
FOCUS_FAR 14 ������ 
IRIS_OPEN 15 ��Ȧ���� 
IRIS_CLOSE 16 ��Ȧ��С 
TILT_UP 21 ��̨���� 
TILT_DOWN 22 ��̨�¸� 
PAN_LEFT 23 ��̨��ת 
PAN_RIGHT 24 ��̨��ת 
UP_LEFT 25 ��̨��������ת 
UP_RIGHT 26 ��̨��������ת 
DOWN_LEFT 27 ��̨�¸�����ת 
DOWN_RIGHT 28 ��̨�¸�����ת 
PAN_AUTO 29 ��̨�����Զ�ɨ�� 
dwStop 
[in] ��ֹ̨ͣ������ʼ������0����ʼ��1��ֹͣ 
dwSpeed 
[in] ��̨���Ƶ��ٶȣ��û�����ͬ���������ٶȿ���ֵ���á�ȡֵ��Χ[1,7] 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZControlWithSpeed_Other( LONG   lUserID,  DWORD   dwPTZCommand,  DWORD   dwStop,  DWORD    dwSpeed);

/*
lUserID 
[in] IPAC_DEV_Login�ķ���ֵ 
dwPTZPresetCmd 
[in] ������̨Ԥ�õ�������±� �궨�� �궨��ֵ ���� 
SET_PRESET 8 ����Ԥ�õ� 
CLE_PRESET 9 ���Ԥ�õ� 
GOTO_PRESET 39 ת��Ԥ�õ� 

dwPresetIndex 
[in] Ԥ�õ����ţ���1��ʼ�������֧��255��Ԥ�õ� 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZPreset_Other(  LONG     lUserID,  DWORD    dwPTZPresetCmd,  DWORD    dwPresetIndex);



/*  ---- ��̨Ѳ������
lUserID 
[in] IPAC_DEV_Login�ķ���ֵ 
lChannel 
[in] ͨ���� 
pPTZCodeBuf 
[in] �����̨Ѳ���������� 
dwBufSize 
[in]��̨Ѳ���������ݵĳ��� 
*/
IPAC_API BOOL  WINAPI IPAC_DVR_PTZCruise(   LONG   lUserID,  LONG     lChannel,  IPAC_DEV_CRUISE    *pPTZCodeBuf,  DWORD    dwBufSize);

/*
lUserID 
[in] IPAC_DEV_Login�ķ���ֵ 
lChannel 
[in] ͨ���� 
pPTZCodeBuf 
[in] �����̨�����뻺������ָ�� 
dwBufSize 
[in] ��̨������ĳ��� 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_TransPTZ_Other(  LONG     lUserID,  LONG     lChannel,  char     *pPTZCodeBuf,  DWORD    dwBufSize);
/*
lUserID 
[in] IPAC_DEV_Login�ķ���ֵ 
lChannel 
[in] ͨ���� 
pPTZCodeBuf 
[in] pStruPointFrame 
ѡ��ͼ������λ����Ϣ
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZSelZoomIn(  LONG     lUserID,  LONG     lChannel,  LPIPAC_DEV_POINT_FRAME     pStruPointFrame);

/*
��ȡ������Ԥ�õ�����
lLoginID 
[in] IPAC_DEV_Login�ķ���ֵ 
lChannel 
[in] ͨ���� 
info
[in] ��Ϣ
[out]���ջ����� (21*48) 
struct{
	BYTE number;
	char name[20];
}
*/
IPAC_API BOOL  WINAPI IPAC_DEV_PTZ_PresetPointName(LONG lLoginID, LONG lChannel, IPAC_DEV_PRESETPOINT_NAMECFG info, char *RevBuffer, short* pSize);

IPAC_API BOOL  WINAPI IPAC_DEV_PTZ_Config(LONG lLoginID, DWORD dwPTZCmd, LONG lChannel, void *SendBuffer, short SendSize, void *RevBuffer, short RevSize);

//---------------------------------------------------------ͨ�ò�������
/*
Parameters
lUserID 
[in] NET_DVR_Login��NET_DVR_Login_V30�ķ���ֵ 
dwCommand 
[in] �豸��������μ��������� 
lChannel 
[in] ͨ���ţ���������Ҫͨ���ţ��ò�����Ч����Ϊ0xFFFFFFFF���� 
lpOutBuffer 
[out] �������ݵĻ���ָ�� 
dwOutBufferSize 
[in] �������ݵĻ��峤��(���ֽ�Ϊ��λ)������Ϊ0 
lpBytesReturned 
[out] ʵ���յ������ݳ���ָ�룬����ΪNULL 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_GetConfig(  LONG     lUserID,  DWORD    dwCommand,  LONG     lChannel,  LPVOID   lpOutBuffer,  DWORD    dwOutBufferSize,  LPDWORD  lpBytesReturned);
/*
Parameters
lUserID 
[in] NET_DVR_Login��NET_DVR_Login_V30�ķ���ֵ 
dwCommand 
[in] �豸��������μ��������� 
lChannel 
[in] ͨ���ţ���������Ҫͨ���ţ��ò�����Ч����Ϊ0xFFFFFFFF���� 
lpInBuffer 
[in] �������ݵĻ���ָ�� 
dwOutBufferSize 
[in] �������ݵĻ��峤��(���ֽ�Ϊ��λ) 
*/
IPAC_API BOOL  WINAPI IPAC_DEV_SetConfig(  LONG     lUserID,  DWORD    dwCommand,  LONG     lChannel,  LPVOID   lpInBuffer,  DWORD    dwInBufferSize);


//---------------------------------------------------------  ά������
IPAC_API BOOL  WINAPI IPAC_DEV_RestoreConfig(  LONG    lUserID, LONG lType=1);// 1 ��ȫ  2 ��ͨ�ָ�������ip��  3 ɾ�������ļ�

IPAC_API BOOL  WINAPI IPAC_DEV_Reboot(  LONG   lUserID);

IPAC_API BOOL  WINAPI IPAC_DEV_GetConfigFile(  LONG    lUserID,  char    *sOutBuffer,  DWORD   dwOutSize,  DWORD   *pReturnSize);

IPAC_API BOOL  WINAPI IPAC_DEV_SetConfigFile(  LONG    lUserID,  char    *sInBuffer,  DWORD   dwInSize);

IPAC_API BOOL  WINAPI IPAC_DEV_SDOperate( LONG    lUserID, char    *sInBuffer ,char    *sOutBuffer);

enum
{
	SDRead_State=1,
	SDRead_FileList=2,
};
IPAC_API BOOL  WINAPI IPAC_DEV_SDRead( LONG    lUserID, char    *sInBuffer ,char    *sOutBuffer);
IPAC_API BOOL  WINAPI IPAC_DEV_SDReadFileList(ULONG lUserID, char* sInBuffer,char* sOutBuffer, LONG lSDFileCount);

IPAC_API BOOL  WINAPI IPAC_DEV_Update( LONG    lUserID ,char    *sInBuffer,  char    *sOutBuffer);

IPAC_API BOOL  WINAPI IPAC_DEV_GetCruisePoint( LONG    lUserID ,char    *sInBuffer,  char    *sOutBuffer, DWORD dwInSize);


IPAC_API BOOL  WINAPI IPAC_DEV_setMessageCallback(LONG    lUserID, MESSAGE_CALLBACK callback, void *pContext);


IPAC_API BOOL  WINAPI IPAC_DEV_GetAlmData(LONG lUserID,char    *sOutBuffer);

IPAC_API DWORD  WINAPI IPAC_DEV_GetNetVersion(long lLoginID);
//---------------------------------------------------------  ���þ�ͷ
IPAC_API BOOL  WINAPI IPAC_DEV_GetLensStatus( LONG    lUserID, IPAC_DEV_LENSRESP* pStatus, SHORT Channel);
IPAC_API BOOL  WINAPI IPAC_DEV_SetLensInit( LONG    lUserID, IPAC_DEV_LENSINIT* pInit, IPAC_DEV_LENSRESP *pGetInit, SHORT Channel);
IPAC_API BOOL  WINAPI IPAC_DEV_SetLensZoom( LONG    lUserIDn, SHORT nValue, SHORT Channel);
IPAC_API BOOL  WINAPI IPAC_DEV_GetStreamInfo( LONG    lUserIDn, int *nWidth, int *nHeight);

//---------------------------------------------------------  �豸����
typedef INT	(WINAPI *SearchHookFunc)(IPAC_DEV_SEARCH* pSearchData, void *pParam);
IPAC_API DWORD  WINAPI IPAC_DEV_SearchDevice(SearchHookFunc Func, void* pParam, int nType);

//---------------------------------------------------------- ͸������
enum SERIAL_TYPE
{
	RS232 = 0,
	RS485 = 1,
};

typedef void (WINAPI *fTransComCallBack) (long lLoginID, SERIAL_TYPE lTransComType, char *pBuffer, unsigned long dwBufSize, unsigned long dwUser);

IPAC_API BOOL  WINAPI IPAC_DEV_OpenTransComChannel(long lLoginID, fTransComCallBack cbTransCom, unsigned long lUser, SERIAL_TYPE nType=RS232);

IPAC_API BOOL  WINAPI IPAC_DEV_CloseTransComChannel(long lLoginID, SERIAL_TYPE nType);

IPAC_API BOOL  WINAPI IPAC_DEV_SerialWrite(long lLoginID, SERIAL_TYPE nType, char *pBuffer, int nBufLen);

IPAC_API BOOL  WINAPI IPAC_DEV_SerialRead(long lLoginID, SERIAL_TYPE nType, char *pBuffer, int nBufLen, int *pReadLen);

//-------------------------------------------------------�㲥�޸�
IPAC_API DWORD  WINAPI IPAC_DEV_BroadcaseChangeIP(tagBroadcaseChange stDevInfo);

//---------------------------------------------------------  SDK��Ϣ
IPAC_API DWORD  WINAPI IPAC_DEV_SetWriteLog(BOOL bflag);

IPAC_API DWORD  WINAPI IPAC_DEV_GetSDKVersion();
IPAC_API DWORD  WINAPI IPAC_DEV_GetLastError();


//----------------------------------------------------------�豸����
/*
nType	����״̬
nInfo	��ϸ��Ϣ�����ȣ�
lpUser  �û�����
*/
typedef DWORD (WINAPI *DevUpFunc)(unsigned int nType, unsigned int nInfo, void* pUser);
/*
lLoginID
[in] ��¼ID
szFileName
[in] �����ļ�������·��
Func
[in] ����״̬�ص�����
lpUser
[in] �ص���������
lSpeed
[in] �ٶ� 0������ ����Ϊ����Kb/s������Ҫ��Զ������ʹ�ã�
*/
IPAC_API BOOL  WINAPI IPAC_DEV_StartDevUp(long lLoginID, const char* szFileName, DevUpFunc Func, LPVOID lpUser, ULONG lSpeed=0);


//---------------------------------------------------------���ø澯��Ϣ�ص�
enum{
	Alarm_NOT_ONLINE	=0,				//�豸������
	Alarm_ONLINE		=1,				//�豸����
	Alarm_Device		=2,				//�豸����
};
// typedef struct  
// {
// 	BYTE btDevState1;
// 	BYTE btDevState2;
// 	BYTE btAlarmIn;
// 	BYTE btAlarmOut;
// 	BYTE btAlarmState;
// 
// 	BYTE btBlank1;
// 	BYTE btBlank2;
// 	BYTE btBlank3;
// }IPAC_AlarmInfo, *LPIPAC_AlarmInfo;

typedef struct  
{
	BYTE bMainboard;	//= 1 Ϊ���������й���
	BYTE bFLASH;		//= 1 ΪFLASH�й���
	BYTE bEEPROM;		//= 1 ΪEEPROM�й���
	BYTE bNET;			//= 1 Ϊ�����й���
	BYTE bIC;			//= 1 Ϊ�������IC�й���
	BYTE bSENSOR;		//= 1 Ϊû�з���SENSOR
	BYTE bSENSORImage;	//= 1 Ϊû��SENSORͼ��
	BYTE bZOOM;			//= 1 Ϊ��ͷZOOM����
	BYTE bAF;			//= 1 Ϊ��ͷAF����
	BYTE bAperture;		//= 1 Ϊ��ͷ��Ȧ����
	BYTE bDayNight;		//= 1 Ϊ��ͷ��ҹ����
	BYTE bIOIn;			//    �澯����״̬
	BYTE bIOOut;		//    �澯���״̬
	BYTE bVMD;			//= 1 Ϊ���ƶ����澯
	BYTE bIOInState;	//= 1 IO����澯
	BYTE bNetOut;       //= 1 �������
	BYTE bVideoLose;	//= 1 ��Ƶ��ʧ
 	BYTE bVideoShield;	//= 1 ��Ƶ�ڵ�

	BYTE bBlank1;
	BYTE bBlank2;
	BYTE bBlank3;
	BYTE bBlank4;
}AlarmInfoEX;

/*
	lLoginID: �豸��½ID
	lAlarmCode: ��������
	pInfo: ������Ϣ
	pUser: �û�����
*/
typedef void (WINAPI *AlarmCallFunc)(LONG lLoginID, LONG lAlarmCode, void* pInfo, void* pUser);

/*
	����ȫ�ֵı�����Ϣ�ص�
	func: �ص�����
	pUser: �û��������ص��������һ������
*/
IPAC_API BOOL  WINAPI IPAC_DEV_SetAlarmMessageCallback(AlarmCallFunc func,void* pUser);

/*
	�����豸�ı�����Ϣ
	lLoginID: �豸��½ID
*/
IPAC_API BOOL  WINAPI IPAC_DEV_SetListenDevAlarm(LONG lLoginID,BOOL bListen);



typedef void (CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle,char *pRecvDataBuffer,DWORD dwBufSize,BYTE byAudioFlag,void *pUser);
/*
[out] lVoiceComHandle   IPAC_DEV_StartVoiceCom �ķ���ֵ
[out] pRecvDataBuffer   �����Ƶ���ݵĻ�����ָ��
[out] dwBufSize         ��Ƶ���ݴ�С
[out] byAudioFlag       ��Ƶ�������ͣ�0-  ���زɼ������ݣ�1-  �豸���͹�������������
[out] pUser             �û�����ָ��
*/

IPAC_API LONG  WINAPI IPAC_DEV_StartVoiceCom(LONG lLoginID, DWORD dwVoiceChan, BOOL bNeedCBNoEncData, fVoiceDataCallBack cbVoiceDataCallBack, void* pUser);
/*
[in]  lUserID					IPAC_DEV_Login �ķ���ֵ
[in]  dwVoiceChan				����ͨ���ţ��� 1 ��ʼ
[in]  bNeedCBNoEncData		��Ҫ�ص��������������ͣ�0-  �������������ݣ�1-  ����ǰ��
[in]  cbVoiceDataCallBackPCM	ԭʼ������Ƶ���ݻص�����
[in]  pUser					 �û�����ָ��
*/

IPAC_API BOOL  WINAPI IPAC_DEV_SetVoiceComClientVolume(LONG lVoiceComHandle, WORD wVolume);
/*
[in]  lVoiceComHandle  IPAC_DEV_StartVoiceCom �ķ���ֵ
[in]  wVolume			 ����������ȡֵ��Χ[0,0xffff] 
*/



IPAC_API BOOL  WINAPI IPAC_DEV_StopVoiceCom(LONG lVoiceComHandle);
/*
[in]  lVoiceComHandle  IPAC_DEV_StartVoiceCom �ķ���ֵ
*/
// typedef void (CALLBACK *fVoiceDataCallBack)(char *pRecvDataBuffer,DWORD dwBufSize, void *pUser);
// /*
// [out]pRecvDataBuffer ��� PC ���زɼ�����Ƶ���ݣ�PCM���Ļ�����ָ��
// [out]dwBufSize       ��Ƶ���ݴ�С
// [out]pUser           �û�����ָ��
// */
IPAC_API BOOL  WINAPI IPAC_DEV_ClientAudioStart(fVoiceDataCallBack cbVoiceDataCallBack, void *pUser);
/*
��ʼ��������
*/

IPAC_API LONG  WINAPI IPAC_DEV_AddDEV(LONG lLoginID, DWORD dwVoiceChan);
/*
[in]lLoginID      IPAC_DEV_Login �ķ���ֵ
[in]dwVoiceChan   ����ͨ���ţ��� 1 ��ʼ
*/

IPAC_API LONG  WINAPI IPAC_DEV_DelDEV(LONG lLoginID);
/*
[in]lLoginID      IPAC_DEV_Login �ķ���ֵ
*/

IPAC_API BOOL  WINAPI IPAC_DEV_ClientAudioStop();
/*
ֹͣ��������
*/
enum
{
	INFO_P2PSERVER,
};

typedef struct 
{
	BYTE btState;
	BYTE btBlank1;
	BYTE btBlank2;
	BYTE btBlank3;

	int  nBlank1;
}P2PServerInfo, *LPP2PServerInfo;

IPAC_API BOOL  WINAPI IPAC_DEV_GetOtherInfo(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);



//SD��¼��ط�
IPAC_API BOOL  WINAPI IPAC_DEV_SDCard_RealPlay(LONG lLoginID, const char* szFileName, STREAM_CALLBACK callback, void  *pUser, BOOL  bBlocked);

IPAC_API BOOL  WINAPI IPAC_DEV_SDCard_SetPlayPercentage(LONG lPercentage);

IPAC_API BOOL  WINAPI IPAC_DEV_SDCard_StopRealPlay(LONG lLoginID);

IPAC_API BOOL  WINAPI IPAC_DEV_BroadcastSetConfig(DWORD    dwCommand,  LONG     lChannel,  LPVOID   lpInBuffer,  DWORD    dwInBufferSize);

// #ifdef __cplusplus
// }
// #endif

#endif