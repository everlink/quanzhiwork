/*
**************************************************************************************************************
*											         ePDK
*						            the Easy Portable/Player Develop Kits
*									           desktop system
*
* File    	: 	music_player.h
*
* By      	: 	Libaiao
* Func	:
* Version	: 	v1.0
* ============================================================================================================
* 2010-5-25 15:24:52  Libaiao  create this file, implements the fundemental interface;
**************************************************************************************************************
*/

#ifndef __VOLUMEBAR_H__
#define __VOLUMEBAR_H__

#include "apps.h"
#define MUSIC_VOLBAR_WIN "volume bar win"

//VolumeBar UI ����
typedef struct VolumeBarUI_s
{
    RECT Background;		//���������С.(����VolumeBar�������С)
    //VolumeBar����ݸò�������ͼ��
    __u32 BG_bmp_id;		//����ͼƬid
    //��������������������Background.(����0,0��ʼ)
    RECT LeftSpeaker;		//���Icon����,
    __u32 LS_bmp_id;		//���iconͼƬID

    RECT BarBody;			//������body������Ϣ
    __u32 BB_bmp_id;		//������bodyͼƬid,, ע��body���Ȼ�߶�Ӧ��point��������.

    RECT Point;				//���������ȵ�������Ϣ
    __u32 PO_bmp_id;		//���ȵ�ͼƬID

    RECT RightSpeaker;		//�ұ�����������Ϣ
    __u32 RS_bmp_id;		//�ұ�����ͼƬid

    RECT MuteSpeaker;		//����ͼ��
    __u32 MS_bmp_id;		//����ͼ��id����

    RECT VolNumber;			//������ֵ
    //for volume bar private, user doesn't have to initial.
} VolumeBarUI_t;

//VolumeBar���Ʊ�������
typedef struct VolumeBarCtrlVar_s
{
    __u32 ViewAlign;					//GUI_TA_HORIZONTAL = ˮƽ��ʾ������
    //GUI_TA_VERTICAL   = ��ֱ��ʾ������
    __u32 vol_max;						//�������ֵ.(��С�ڵ�ǰϵͳ�������������Ը�����Ϊ׼).
    __u32 AutoExitTime;					//�Զ��˳�ʱ�䣬��SecondΪ��λ

    H_WIN hParent;						//�����ھ��, should be manager win.
    H_LYR UserLayer;					//�û�ͼ��,��ϵͳ�Ѿ�û�п���ͼ��ͨ��ʱ����Ҫ���ݸò�����VolumeBar(Ϊ��͸����ʾ)
    __s32 Pipe;							//�û�����ָ��VolumeBarͼ���ͨ��.
    void *attr;							//�û�����ָ��
} VolumeBarCtrlVar_t;

//�¼����Ʋ���
typedef struct VolumeBarEvent_s
{
    __u32 VolAddKey;					//�û�ָ�����Ǹ�����Ӧ�����Ӷ���. ���� = GUI_MSG_KEY_RIGHT
    __u32 VolAddRepeatKey;				//��Ӧ�ظ���
    __u32 VolDecKey;					//�û�ָ�����Ǹ�����Ӧ����������. ���� = GUI_MSG_KEY_LEFT
    __u32 VolDecRepeatKey;				//��Ӧ�ظ���
    __u32 VolExitKey;					//�˳��������Ƽ�

    __s32 (*OnVolAdd)(void *Handle); 	//������ʱ,�û����¼���������
    __s32 (*OnVolDec)(void *Handle);	//������ʱ,�û����¼�������?
    __s32 (*OnExit)(void *Handle);		//

} VolumeBarEvent_t;

typedef struct  VolumeBarPara_s
{
    VolumeBarUI_t  			UI;				//����������  UI����
    VolumeBarCtrlVar_t		CtrlVar;		//����������  �������Ʋ���
    VolumeBarEvent_t        Event;			//����������  �¼���������
} VolumeBarPara_t;


typedef struct VolumeBar_s
{
    VolumeBarPara_t  Para;				//User���ݽ����Ĳ���


    //����ΪVoluemBar��˽�в���

    H_WIN   H_Framewin;					//frame window
    H_LYR 	VB_Layer;					//VolumeBarͼ�㣬�û������ʼ��

    __u32   TimerID;
    HTHEME 	BG_Handle;					//����ͼƬ���
    void   *BG_bmp;					//����ͼƬ��ַ

    HTHEME 	LS_Handle;					//LeftSpeakerͼƬ���
    void   *LS_bmp;						//�������iconͼƬ��ַ

    HTHEME 	BB_Handle;					//������bodyͼƬ���
    void   *BB_bmp;						//������bodyͼƬbuffer��ַ

    HTHEME 	PO_Handle;					//���ȵ���
    void   *PO_bmp; 					//���ȵ�ͼƬ��Ϣ

    HTHEME 	RS_Handle;					//RightSpeaker icon ���
    void   *RS_bmp;						//�ұ�����ͼƬ��ַ

    HTHEME 	MS_Handle;					//mute speaker icon ���
    void   *MS_bmp;						//����ͼ���ַ
} VolumeBar_t;

#define C_VOLUMEBAR_FRAMEWIN_ID			(APP_MUSIC_ID + 20)

#define	C_VB_AUTO_EXIT_TIME				100

extern VolumeBar_t *VolumeBarCreate(VolumeBarPara_t *Para);
extern __s32 VolumeBarDelete(VolumeBar_t *This);
extern __s32 VolumeBarSetFocus(VolumeBar_t *This);
extern __s32 VolumeBarShow(VolumeBar_t *This);

#endif