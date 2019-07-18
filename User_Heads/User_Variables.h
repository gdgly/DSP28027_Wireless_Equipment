/*
 * User_variable.h
 *
 *  Created on: 2019��6��25��
 *      Author: JYW
 *�޸��ˣ�Jialin Luo
 * �޸����ڣ�2019��7��11��
 */  //ͷ�ļ���ֻ������ȫ�ֱ�������extern�����ܶ���ȫ�ֱ�������Ϊ��ȫ�ֱ���������h�ļ��У����c�ļ��������˸�ͷ�ļ�������������˶�Σ��ᱨ��������ȫ�ֱ���ֻ����Դ�ļ��ж��塣������ֻ��һ�Σ��������Ժܶ�Σ�

#ifndef USER_HEADS_USER_VARIABLES_H_
#define USER_HEADS_USER_VARIABLES_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TARGET_GLOBAL
   #define TARGET_EXT 	extern
#else
   #define TARGET_EXT
#endif


TARGET_EXT Uint16 RamfuncsLoadStart;
TARGET_EXT Uint16 RamfuncsLoadEnd;
TARGET_EXT Uint16 RamfuncsRunStart;



/*********����ϵͳ��ر����궨��********/
#define Flash_Open 1         //Flash ���з�ʽ�л�λ 0---RAM;1---Flash
#define SWITCH_FREQUENCY      300	//����Ƶ��(kHz)
#define DC_DUTY_INIT          0.5  //  ��ʼռ�ձ�
#define Drive_on_or_off       1    //  1 Ϊon    2 Ϊoff
#define pi 3.141592653
/*************************************/


/**********ϵͳ����ر���**************/
struct SYSTEMRunstate_Flag
{
	   Bool normal;//ϵͳ�������б�־λ
	   Bool error; //ϵͳ�ܹ��ϱ�־λ
};
TARGET_EXT volatile struct SYSTEMRunstate_Flag System_Runstate_Flag;
/*************************************/


/**********PWM������ر���************/
/*TARGET_EXT _iq dc_dc2_duty;
TARGET_EXT _iq dc_dc2_duty_correct;
TARGET_EXT _iq modulate_duty;
TARGET_EXT _iq modulate_duty_correct;

TARGET_EXT _iq epwm1_data;           //PWM�Ƚ�ֵ
TARGET_EXT Uint32 epwm1_data_int;   //PWM�Ƚ�ֵ ��������
TARGET_EXT Uint32 epwm1_data_fra;   //PWM�Ƚ�ֵ С������
TARGET_EXT Uint32 epwm2_data;

TARGET_EXT int SW_TBPRD;
TARGET_EXT _iq15 SW_TBPRD_IQ15;


TARGET_EXT Uint16 MEP_status;
TARGET_EXT Uint32 MEP_status_count;
*/
TARGET_EXT Uint32 MEP_ScaleFactor;
TARGET_EXT Uint32 ePWM;
/*************************************/

/*************AD������ر���**********/
//TARGET_EXT Uint16 Vi_ADC;
//TARGET_EXT Uint16 IL_ADC;
//TARGET_EXT Uint16 Vo_ADC;
//TARGET_EXT Uint16 Temperature_ADC;
typedef struct
   {
	Uint16 Record_0;
	Uint16 Record_1;
	Uint16 Record_2;
	Uint16 Record[3];
	Uint16 Median;
	Uint16 Minimum;
	Uint16 Maximum;
	Uint16 Average;
   }ADC_Sample;
TARGET_EXT ADC_Sample Vi_test;
TARGET_EXT ADC_Sample IL_test;
TARGET_EXT ADC_Sample Vo_test;
TARGET_EXT ADC_Sample Temperature_test;

/*************************************/

/*************�����㷨��ر���**********/
#define PIout_Maximum  _IQ15(200)   //������������#define PIout_Maximum  _IQ15(100)
#define PIout_Minimum  _IQ15(0)
#define Vo_Ref 3078  //�����ѹ�ο�ֵ220V���ͽ�DSP��ֵΪ2.48��ADC��Ϊ3078
#define Vo_max 3351  //�����ѹ�����ֵ240V���ͽ�DSP��ֵΪ2.48��ADC��Ϊ3351
TARGET_EXT _iq Kp;
TARGET_EXT _iq Ki;
TARGET_EXT _iq PIout_This_Time;
TARGET_EXT _iq PIout_Last_Time;
TARGET_EXT _iq Error_This_Time;
TARGET_EXT _iq Error_Last_Time;
TARGET_EXT Uint16 SoftStart_Flag;
TARGET_EXT _iq SoftStart_Period;
/*************************************/


/*************����ͨ����ر������궨��**********/
//#define SCI_BAUD_9600 0x00C2  //��Ӧ9600������
//#define SCI_BAUD_115200 0x000F  //��Ӧ115200������
//#define ASK_FOR_KP 0x6B70   //�û�����kp�Ķ�Ӧ�ַ�
//#define ASK_FOR_KI 0x6B69   //�û�����ki�Ķ�Ӧ�ַ�
//#define ASK_FOR_Vo 0x766F   //�û�����vo�Ķ�Ӧ�ַ�
//#define ASK_FOR_Io 0x696F   //�û�����io�Ķ�Ӧ�ַ�
//TARGET_EXT Uint16 ParameterH; //Parameter�ĸ�8λ
//TARGET_EXT Uint16 ParameterL; //Parameter�ĵ�8λ
TARGET_EXT Uint16 Parameter;  //�����жϵ���д�����Ϊkp����ki
//TARGET_EXT Uint16 PC_Input_Value;  //���Լ�¼�ɵ��Է��͹�����kp��kiֵ
TARGET_EXT Uint16 kp_sci;  //��ȡ���Է�������kpֵ
TARGET_EXT Uint16 ki_sci;  //��ȡ���Է�������kiֵ
TARGET_EXT Uint16 Vo;  //��ǰ�����ѹֵ
TARGET_EXT Uint16 IL;  //��ǰ��е���ֵ
TARGET_EXT Uint16 Vi;  //��ǰ�����ѹֵ
//TARGET_EXT Uint16 Temperature;  //��ǰ�¶�ֵ
//TARGET_EXT char *msg1;  //���1
//TARGET_EXT char *msg2;  //���2
//TARGET_EXT char *msg3;  //���3
//TARGET_EXT char *msg4;  //���4
/*************************************/



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* USER_HEADS_USER_VARIABLES_H_ */