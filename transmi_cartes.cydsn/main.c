/* ========================================
 *
 * Copyright Couderc Pierre, 2019
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "string.h"
#include "stdio.h"    //Pour Sprintf

uint16 batverte, batrouge,panneau,disjon;
char strbat[2],strdis[2],strpan[2];

//char strbatv[5],strbatr[5];

char niv_reserv[3]; // [RESERV]
  
/********************************************START lecture niveau d'eau********************************************/
void lecture_reserv(){
    uint8 niv;
    niv=niveau_Read(); 
    
    if ( niv==0xFF) strcpy (niv_reserv,"00");
    if ( niv==0xFE) strcpy (niv_reserv,"02");
    if ( niv==0xFC) strcpy (niv_reserv,"04");
    if ( niv==0xF8) strcpy (niv_reserv,"06");
    if ( niv==0xF0) strcpy (niv_reserv,"08");
    if ( niv==0xE0) strcpy (niv_reserv,"10");
    if ( niv==0xC0) strcpy (niv_reserv,"12");
    if ( niv==0x80) strcpy (niv_reserv,"14");
    if ( niv==0x00) strcpy (niv_reserv,"16"); 
    if((niv!=0xFF)&&(niv!=0xFE)&&(niv!=0xFC)&&(niv!=0xF8)&&(niv!=0xF0)&&(niv!=0xE0)&&(niv!=0xC0)&&(niv!=0x80)&&(niv!=0x00))strcpy (niv_reserv,"99");
}
/********************************************END lecture niveau d'eau********************************************/


/********************************************START lecture LEDS********************************************/
void lecture_leds(){ 
/*<---LECTURE ETATS DES LEDS--->*/
    batverte=0;
    batrouge=0;
    panneau=0;
    disjon=0;
    isr_rbat_Start();
    isr_vbat_Start();
    isr_rch_Start();
    isr_vpan_Start();
    CyDelay(1000);
    isr_vbat_Stop();
    isr_rbat_Stop();
    isr_rch_Stop();
    isr_vpan_Stop();
    //var=compteur;
/*<---TEST LED ROUGE DISJONCTEUR--->*/
    if(disjon>40  && disjon<60){    //Rouge fixe
        strcpy (strdis,"0");
    }
    if(disjon>10  && disjon<30){    //Rouge clignote
        strcpy (strdis,"2");
    }
    if(disjon<10){                  //Rouge éteint
        strcpy (strdis,"3"); 
    }    
/*<---TEST LED BICOLORE VERT/ROUGE BATTERIE--->*/
    strcpy (strbat,"0");           //Erreur
    if(batverte>40  && batverte<60  && batrouge<10){                //Verte fixe
        strcpy (strbat,"1");
    }
    if(batverte>10  && batverte<30 && batrouge<10){                 //Verte clignote
        strcpy (strbat,"3");
    }
    if(batverte>40  && batverte<60  && batrouge>40  && batrouge<60){//Orange fixe
        strcpy (strbat,"4");
    }
    if(batrouge>40  && batrouge<60 && batverte<10){                 //Rouge fixe
        strcpy (strbat,"5");
    }

/*<---TEST LED VERTE PANNEAU--->*/
    if(panneau>40  && panneau<60){   //Verte fixe
        strcpy (strpan,"2");
    }
    if(panneau>10  && panneau<30){   //Verte clignote
        strcpy (strpan,"3");
    }
    if(panneau<10){                  //Verte éteint
        strcpy (strpan,"1"); 
    } 
}
/********************************************END lecture LEDS********************************************/


/********************************************START Envoi Sigfox********************************************/
void sigfox_init()
    {
     //initialisation du module sigfox
    UART_SIG_Start();
    CyDelay(1000);
    UART_SIG_PutString("ATE1\r");
    UART_SIG_PutString("ATQ0\r");
    CyDelay(1000);
    }



/********************************************START Envoi Sigfox********************************************/
void sigfox_send()
 {
    //Cas de fonctionement normal : disjoncteur OK
    if(disjon > 40){
        UART_SIG_PutString("AT$SF=");
        UART_SIG_PutChar('0');              
        UART_SIG_PutString(strdis);
        UART_SIG_PutChar('0');
        UART_SIG_PutString(strpan);
        UART_SIG_PutChar('0');
        UART_SIG_PutString(strbat);
        UART_SIG_PutString(niv_reserv);
        UART_SIG_PutChar('\r');
    }
    //Cas de fonctionement anormal : disjoncteur déclenché
    else{
        UART_SIG_PutString("AT$SF=");
        UART_SIG_PutChar('0');              
        UART_SIG_PutString(strdis);
        UART_SIG_PutChar('0');
        UART_SIG_PutString(strpan);
        UART_SIG_PutChar('0');
        UART_SIG_PutString(strbat);
        UART_SIG_PutString(niv_reserv);
        UART_SIG_PutString(",1,1\r");
        UART_SIG_PutChar('\r');
    }
        
    
        //début traitement réception
        /*cptcar=0;
        isr_1_Start();
        
        nb=0;
        do{
            sigfox[nb]=UART_SIG_GetChar();
            nb++;
            
        }while(sigfox[nb-1]!=0x2b);
       Relais_Write(1);
       CyDelay(3000);
       Relais_Write(0);*/
    //reception message du serveur sigfox
    //}
  }
/********************************************END Envoi Sigfox********************************************/
/********************************************START Reception Sigfox********************************************/
/********************************************END Envoi Sigfox********************************************/

/*-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-VOID MAIN-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-*/
int main(void)
{
    CyGlobalIntEnable; 
    sigfox_init();
    Relais_Write(0); 
    for(;;)
    {       
    lecture_reserv();
    lecture_leds();
    sigfox_send();
     
    /*UART_SIG_PutString("AT$SF=");
    sprintf(strbatv, "%u", batverte);
    sprintf(strbatr, "%u", batrouge);
    sprintf(strdis, "%u", disjon);
    sprintf(strpan, "%u", panneau);
    UART_SIG_PutString(strbatv);
    UART_SIG_PutString(",");
    UART_SIG_PutString(strbatr);
    UART_SIG_PutString(",");
    UART_SIG_PutString(strdis);
    UART_SIG_PutString(",");
    UART_SIG_PutString(strpan);
    UART_SIG_PutString("\r");*/
    CyDelay(10000);    
    }
}

   
/* [] END OF FILE */