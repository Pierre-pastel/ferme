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

char niv_reserv[3]; // Niveau d'eau du réservoir 
char message[35];   // Pour la réception de la réponse SIGFOX
char begin[15],resp[35];
uint8 cptcar;       // Compteur caractère reçu de réponse SIGFOX
uint8 phase,j;        // Phase réception Sigfox

  
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


/********************************************START Initialisation Sigfox********************************************/
void sigfox_init()
    {
     //initialisation du module sigfox
    UART_SIG_Start();
    CyDelay(100);
    UART_SIG_PutString("ATE1\r");
    UART_SIG_PutString("ATQ0\r");
    CyDelay(1000);
    }
/********************************************START Initialisation GSM********************************************/
//Initialisation du GSM
void gsm_init()
    {
    UART_GSM_Start();     
    CyDelay(1000);
    UART_GSM_ClearTxBuffer();                //Efface le buffer de Tx
    UART_GSM_PutString("AT\n\r");
    CyDelay(500);
    //UART_GSM_PutString("AT+CSQ\r");        //Demande du niveau de réception
    //CyDelay(500);
    UART_GSM_PutString("AT+CMGF=1\n\r");       //Choix du mode texte
    CyDelay(500);
    UART_GSM_PutString("AT+CSMP=17,0,0\n\r");  //Paramètrage du mode texte
    CyDelay(500);
    UART_GSM_PutString("AT+CMGD=1,1\n\r");     //Efface les messages
    }

/********************************************START Envoi Sigfox********************************************/
void sigfox_send()
 {
    //Cas de fonctionement normal : disjoncteur OK
    if(disjon > 40){
        UART_SIG_PutString("AT$SF=");
        UART_SIG_PutChar('0');              
        UART_SIG_PutString(strdis);
        //UART_SIG_PutChar('0');
        UART_SIG_PutString(strpan);
        //UART_SIG_PutChar('0');
        UART_SIG_PutString(strbat);
        UART_SIG_PutString("00");           //Niveau eau puits
        UART_SIG_PutString(niv_reserv);     //Niveau eau réservoir
        UART_SIG_PutChar('\r');
    }
    //Cas de fonctionement anormal : disjoncteur déclenché
    else{
        UART_SIG_PutString("AT$SF=");
        UART_SIG_PutChar('0');              
        UART_SIG_PutString(strdis);
        //UART_SIG_PutChar('0');
        UART_SIG_PutString(strpan);
        //UART_SIG_PutChar('0');
        UART_SIG_PutString(strbat);
        UART_SIG_PutString("00");           //Niveau eau puits
        UART_SIG_PutString(niv_reserv);     //Niveau eau réservoir
       
        UART_SIG_PutString(",1,1");
        UART_SIG_PutChar('\r');
        
        //début traitement réception
        CyDelay(5000);
        cptcar=0;
        phase=0;
        UART_SIG_ClearRxBuffer();    //Efface le buffer de Rx
        isr_serial_Start();
        while(phase<2);              //Attente réponse message
        isr_serial_Stop();
    //reception message du serveur sigfox
    }
  }
        /********************************************END Envoi Sigfox********************************************/
/********************************************START Reception Sigfox********************************************/
/********************************************END Envoi Sigfox********************************************/

/*-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-VOID MAIN-XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX-*/
int main(void)
{
    CyGlobalIntEnable; 
    sigfox_init();
    gsm_init();
    //Initialisation pour éviter déclenchement disjoncteur
    Relais_Write(0); 
    resp[4]='0';
    resp[5]='0';
    for(;;)
    {       
    lecture_reserv();
    lecture_leds();
    sigfox_send();
    
    //Vérification ré - enclenchement a effectuer ?
    if ((resp[4]=='1')||(resp[5]=='1')) {
        Relais_Write(1);   //Disjoncteur à enclencher
        CyDelay(1000);
        Relais_Write(0);
        resp[4]='0';
        resp[5]='0';
        }
    
    //Tempo entre 2 transmissions
    if(disjon > 40) {  //Non disjoncté
        CyDelay(660000); //Toutes les ?? minutes
    }
    else {  //Disjoncté
        UART_GSM_ClearTxBuffer();           //Efface le buffer de Tx
        UART_GSM_PutString("AT+CMGS=\"+33630702827\"\r\n");     //Sélection du destinataire
        CyDelay(500);
        UART_GSM_PutString("Regulateur disjonte !");
        UART_GSM_PutChar(26);                         //Envoi du message par un Ctrl+z (0x1A en hexa )
        CyDelay(660000); //Toutes les 11 minutes
    };                        
    }
}

   
/* [] END OF FILE */