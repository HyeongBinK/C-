#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<vector>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<math.h>

using namespace std;

//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////

#define BASEWIDTH 30//����
#define BASEHEIGHT 30 //����

enum CLASS
{
	CLASS_eCIVILIAN = 1,
	CLASS_eWARRIOR,
	CLASS_eHERO,
	/*m_eARCHER,
	m_eRANGER,
	m_eMAGICIAN,
	m_eARCHMAGE, */
	CLASS_eMONSTER, //����
	CLASS_eBOSSMONSTER //��������
};

enum LIFESTATUS
{
	LIFESTATUS_eNORMAL = 0, //�⺻����
	LIFESTATUS_eDEAD, //(�������)
	LIFESTATUS_eON_POISON, //�ڽ��̰����ҋ�����(�ڽ������̵ɋ�����) �ִ�ü���� 5���������ӵ�����
	LIFESTATUS_eON_PARALYSIS, //���ݼӵ��� �ſ������ ������ �İ�
};

enum SPECIALEFFECT
{
	SPECIALEFFECT_eNONE_EFFECT = 0, //�߰�ȿ������
	SPECIALEFFECT_ePOISON_EFFECT, //��ȿ���ο�
	SPECIALEFFECT_ePARAIYSIS_EFFECT, //����ȿ���ο� 
	//m_ePOISON_RESISTANCE, //������
	//m_ePARALYSIS_RESISTANCE, //��������
};

enum KEY
{
	KEY_LEFT = 75,  
	KEY_RIGHT = 77,
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_ESC = 27, //��������Ű
	KEY_ENTER = 13, //�޴�Ű
};

enum WEAPONNAME
{
	WEAPONNAME_eSHORTSWORD =1,
	WEAPONNAME_eLONGSWORD,
	WEAPONNAME_eBUSTERSWORD,
	WEAPONNAME_eGOBKINGSWORD,
	WEAPONNAME_eMISRILLSWORD,
	WEAPONNAME_eDEMONKINGSWORD,
	WEAPONNAME_eDRAGONSWORD,
	WEAPONNAME_eRETURN, //�ǵ��ư���
	WEAPONNAME_eETERNALSWORD = 999
};

enum SKILLNAME
{
	//��Ƽ��
	SKILLNAME_eNORMALATTACK =0,
	SKILLNAME_ePOWERSLASH,
	SKILLNAME_eCOMBOASSULT,
	SKILLNAME_eCOMBOEXTINGSION,
	SKILLNAME_eRETURN //�ǵ��ư���
	//����
	//SKILLNAME_eRAGE,
	//�нú�
	//SKILLNAME_eSWORDMASTER
};

enum MOBNAME
{
	MOBNAME_eGOB = 1,
	MOBNAME_eKINGGOB,
	MOBNAME_eMINOTAURS,
	MOBNAME_eMINOTARUSKING,
	MOBNAME_eDEVIL,
	MOBNAME_eDEMONKING,
	MOBNAME_eWYVERN,
	MOBNAME_eHORNTAIL
};

enum WEAPONPRIDE
{
	WEAPONPRIDE_eSHORTSWORD = 100,
	WEAPONPRIDE_eLONGSWORD = 1000,
	WEAPONPRIDE_eBUSTERSWORD = 10000,
	WEAPONPRIDE_eGOBKINGSWORD = 7777,
	WEAPONPRIDE_eMISRILLSWORD = 20000,
	WEAPONPRIDE_eDEMONKINGSWORD = 50000,
	WEAPONPRIDE_eDRAGONSWORD = 99999,
	WEAPONPRIDE_eETERNALSWORD = 9999999
};

enum WEAPONTYPE
{
	WEAPONTYPE_eONEHANDSWORD =1, //�Ѽհ� 
	WEAPONTYPE_eTWOHANDSWORD, //�μհ�
};
