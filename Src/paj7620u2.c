#include "paj7620u2.h"
#include "paj7620u2_cfg.h"

////ѡ��PAJ7620U2 BANK����
//void paj7620u2_selectBank(bank_e bank)
//{
//	switch(bank)
//	{
//		case BANK0: GS_Write_Byte(PAJ_REGITER_BANK_SEL,PAJ_BANK0);break;//BANK0�Ĵ�������
//		case BANK1: GS_Write_Byte(PAJ_REGITER_BANK_SEL,PAJ_BANK1);break;//BANK1�Ĵ�������
//	}
//			
//}

////PAJ7620U2����
//u8 paj7620u2_wakeup(void)
//{ 
//	u8 data=0x0a;
//	GS_WakeUp();//����PAJ7620U2
//	delay_ms(5);//����ʱ��>400us
//	GS_WakeUp();//����PAJ7620U2
//	delay_ms(5);//����ʱ��>400us
//	paj7620u2_selectBank(BANK0);//����BANK0�Ĵ�������
//	data = GS_Read_Byte(0x00);//��ȡ״̬
//	if(data!=0x20) return 0; //����ʧ��
//	
//	return 1;
//}

////PAJ7620U2��ʼ��
////����ֵ��0:ʧ�� 1:�ɹ�
//u8 paj7620u2_init(void)
//{
//	u8 i;
//	u8 status;
//	
//	GS_i2c_init();//IIC��ʼ��
//    status = paj7620u2_wakeup();//����PAJ7620U2
//	if(!status) return 0;
//	paj7620u2_selectBank(BANK0);//����BANK0�Ĵ�������
//	for(i=0;i<INIT_SIZE;i++)
//	{
//		GS_Write_Byte(init_Array[i][0],init_Array[i][1]);//��ʼ��PAJ7620U2
//	}
//    paj7620u2_selectBank(BANK0);//�л���BANK0�Ĵ�������
//	
//	return 1;
//}

//////���˵�
////void paj7620u2_test_ui(void)
////{
////	POINT_COLOR=BLUE;//��������Ϊ��ɫ
////	LCD_Fill(30,170,300,300,WHITE);
////	LCD_ShowString(30,170,200,16,16,"KEY1:   Gesture test");//����ʶ�����
////	LCD_ShowString(30,190,200,16,16,"KEY0:   Ps test     ");//�ӽ�������
////	
////}

//////����ʶ�����
////void Gesture_test(void)
////{
////	u8 i;
////    u8 status;
////	u8 key;
////	u8 data[2]={0x00};
////	u16 gesture_data;
////	u8 ledflash=0;
////	
////	paj7620u2_selectBank(BANK0);//����BANK0�Ĵ�������
////	for(i=0;i<GESTURE_SIZE;i++)
////	{
////		GS_Write_Byte(gesture_arry[i][0],gesture_arry[i][1]);//����ʶ��ģʽ��ʼ��
////	}
////	paj7620u2_selectBank(BANK0);//�л���BANK0�Ĵ�������
////	i=0;
////	POINT_COLOR=BLUE;//��������Ϊ��ɫ
////	LCD_Fill(30,170,300,300,WHITE);
////	LCD_ShowString(30,180,200,16,16,"KEY_UP: Exit the test");
////	LCD_ShowString(30,210,200,16,16,"Gesture test");
////	POINT_COLOR=RED;//��������Ϊ��ɫ
////	while(1)
////	{
////        key = KEY_Scan(0);
////		if(key==WKUP_PRES)
////		{
////			GS_Write_Byte(PAJ_SET_INT_FLAG1,0X00);//�ر�����ʶ���ж����
////			GS_Write_Byte(PAJ_SET_INT_FLAG2,0X00);
////			break;
////		}			
////        status = GS_Read_nByte(PAJ_GET_INT_FLAG1,2,&data[0]);//��ȡ����״̬			
////		if(!status)
////		{   
////			gesture_data =(u16)data[1]<<8 | data[0];
////			if(gesture_data) 
////			{
////				switch(gesture_data)
////				{
////					case GES_UP:               LCD_ShowString(110,250,200,16,24,"UP          ");
////					                           printf("Up\r\n");            ledflash=1;      break; //����
////					case GES_DOWM:             LCD_ShowString(100,250,200,16,24,"Dowm        ");      
////               						           printf("Dowm\r\n");          ledflash=1;      break; //����
////					case GES_LEFT:             LCD_ShowString(100,250,200,16,24,"Left        ");           
////  						                       printf("Left\r\n");          ledflash=1;      break; //����
////					case GES_RIGHT:            LCD_ShowString(100,250,200,16,24,"Right       ");       
////                						       printf("Right\r\n");         ledflash=1;      break; //����
////					case GES_FORWARD:          LCD_ShowString(80,250,200,16,24,"Forward     ");        
////						                       printf("Forward\r\n");       ledflash=1;      break; //��ǰ
////					case GES_BACKWARD:         LCD_ShowString(80,250,200,16,24,"Backward    ");    
////            						           printf("Backward\r\n");      ledflash=1;      break; //���
////					case GES_CLOCKWISE:        LCD_ShowString(70,250,200,16,24,"Clockwise   ");     
////                						       printf("Clockwise\r\n");     ledflash=1;      break; //˳ʱ��
////					case GES_COUNT_CLOCKWISE:  LCD_ShowString(50,250,200,16,24,"AntiClockwise");  
////                   						       printf("AntiClockwise\r\n"); ledflash=1;      break; //��ʱ��
////					case GES_WAVE:             LCD_ShowString(100,250,200,16,24,"Wave         ");    
////						                       printf("Wave\r\n");          ledflash=1;      break; //�Ӷ�
////					default:  ledflash=0; break;
////					
////				}	
////                if(ledflash)//DS1��˸
////				{   
////					LED1=0;delay_ms(80);LED1=1;delay_ms(80);
////					LED1=0;delay_ms(80);LED1=1;delay_ms(80);
////					LCD_ShowString(40,250,200,16,24,"                        ");
////					ledflash=0;
////				}						
////			}
////			
////		}
////		delay_ms(50);
////		i++;
////		if(i==5)
////		{
////			LED0=!LED0;//��ʾϵͳ��������	
////			i=0;
////		}		   
////	}
////}

////�ӽ�������
//void Ps_test(void)
//{
//	u8 i;
//	u8 data[2]={0x00};
//	u8 obj_brightness=0;
//	u16 obj_size=0;
//	paj7620u2_selectBank(BANK0);//����BANK0�Ĵ�������
//	for(i=0;i<PROXIM_SIZE;i++)
//	{
//		GS_Write_Byte(proximity_arry[i][0],proximity_arry[i][1]);//�ӽ����ģʽ��ʼ��
//	}
//    paj7620u2_selectBank(BANK0);//�л���BANK0�Ĵ�������
//	while(1)
//	{	
//		
//		obj_brightness = GS_Read_Byte(PAJ_GET_OBJECT_BRIGHTNESS);//��ȡ��������
//		data[0] = GS_Read_Byte(PAJ_GET_OBJECT_SIZE_1);//��ȡ�����С
//		data[1] = GS_Read_Byte(PAJ_GET_OBJECT_SIZE_2);
//		obj_size = ((u16)data[1] & 0x0f)<<8 | data[0];
//		printf("b%d",obj_brightness);
//        printf("%d\r\n",obj_size);
//		delay_ms(100);
//		
//	}
//	
//}
//////PAJ7620U2����������
////void paj7620u2_sensor_test(void)
////{   
////	 u8 i=0;
////	 u8 key;
////	
////     paj7620u2_test_ui();//���˵���ʾ
////	 while(1)
////	 {
////		key = KEY_Scan(0);//����ɨ��
////		if(key)
////		{
////			 switch(key)
////			 {
////				 case KEY1_PRES:  Gesture_test();   break;//���Ƽ��ģʽ
////				 case KEY0_PRES:  Ps_test();        break;//�ӽ����ģʽ  
////			 }
////			 paj7620u2_test_ui();
////		}
////		delay_ms(50);
////		i++;
////		if(i==5)
////		{
////		    LED0=!LED0;//��ʾϵͳ��������	
////			i=0;
////		}
////		 
////	 }
////}
