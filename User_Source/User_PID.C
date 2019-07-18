/********************* User_PID.C*******************
�ļ����ܣ�                        ���ڼ���DC-DC��������������ѹ��PID
Ӧ�ó��ϣ�    Ӧ����500W ��β������ղ�DC-DC�˲���
���ߣ�
����ʱ�䣺
�޸�ʱ�䣺  2019.07.13

����1: User_PID()
����1���ܣ���ѹ��PID
����1�����������ǰ�����ѹֵ��
                          �����ѹ������
                          ����ϵ����
                          ����ϵ��

����1�������������������
*********************************************************/
#include "User_all_include.h"
#pragma CODE_SECTION(User_PID, "ramfuncs");
void User_PID()
{
	_iq PIout;
	_iq DutyCycle_Correct;
	_iq DutyCycle_Int;
	_iq DutyCycle_Fra;
    //_iq PIout_Maximum = _IQ15(100);
    //_iq PIout_Minimum = _IQ15(0);

    Error_This_Time = _IQ15(Vo_Ref)-_IQ15(Vo);
   /******���ڲ����͵�����PI����******/
   PIout_This_Time = PIout_Last_Time + _IQ15mpy((Error_This_Time - Error_Last_Time) , Kp) + _IQ15mpy(Error_This_Time,Ki);  //��ɢPI��y(k+1)=y(k)+kp*[e(k+1)-e(k)]+ki*��t*e(k+1)������ȡKp=_IQ15(kp)��KI=_IQ15(ki*��t)����t��ָ��������
   if (PIout_This_Time >= PIout_Maximum) {PIout_Last_Time = PIout_Maximum;}//����ֵ��PI�����ֵ���ܳ�����ֵ��PI�ڲ��޷���
   else if (PIout_This_Time <= PIout_Minimum) {PIout_Last_Time = PIout_Minimum;}
   else PIout_Last_Time = PIout_This_Time;

  /*******************/

   /******����������******/
   if(SoftStart_Flag==1)  //����Ǵ����������׶�
   {
	   SoftStart_Period += _IQ15(0.0001);
   }
   if(SoftStart_Period>=_IQ15(1))  //���SoftStart_Period�Ѿ�����1�����������׶ν���
   {
	   SoftStart_Flag = 0;
	   SoftStart_Period = _IQ15(1);
   }
   PIout = _IQ15mpy(PIout_This_Time , SoftStart_Period);
   /*******************/

   /******�Ѽ�����ת��Ϊд��CMP�Ĵ�����ֵ******/
   DutyCycle_Correct = PIout;   //��������+CAU_SET+CAD_CLEAR�ķ������� DutyCycle_Correct = _IQ15(100) - PIout;
   DutyCycle_Int = _IQ15int(DutyCycle_Correct);
   DutyCycle_Fra = _IQ15int(_IQ15mpy(_IQfrac(DutyCycle_Correct),_IQ(256)) );

   if(DutyCycle_Int >= 190) EPwm1Regs.CMPA.half.CMPA = 190;   //HRPWMҪ����������ģʽ��ҪԤ��3��ʱ�����ڵ�ʱ��ԣ�ȡ���������ռ�ձ�����Ϊ0.05��0.95����������ģʽ��0.95ռ�ձȶ�Ӧ190,0.05ռ�ձȶ�Ӧ10
   else if(DutyCycle_Int <= 10) EPwm1Regs.CMPA.half.CMPA = 10;
   else EPwm1Regs.CMPA.half.CMPA = DutyCycle_Int;
   EPwm1Regs.CMPA.half.CMPAHR = DutyCycle_Fra << 8;

}

