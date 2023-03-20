#include "project.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Declaración del variables de la comunicación serial (UART).
char bufferReceive[9];
char bufferToSend_PWM[20];
char bufferToSend_Pos[20];
int count = 0;
char RPM_value_String[3];
int16 RPM_receive;
char Pos_value_String[3];
int16 position_receive;

char position_String[16] = "Pos: 0      mm";
char RPM_String[16] =      "Vel: 0.00   rpm";

CYBIT int_Capture_flag = 0;
uint32 interruptions_a;
uint32 capture = 0;
float RPM =      0.0;


char RPM_reading[6];
float PWM;
float PWM_final;


float distance;
float distance_final = 0.0;
char PUL_reading[10];

void printLCD(int column, int row, char message[16]) {
    LCD_I2C_setCursor(column, row);
    LCD_I2C_print(message);
}

int j = 0;
CY_ISR(isrSerial) {
    if (UART_Serial_GetRxBufferSize() > 0) {
        bufferReceive[count] = UART_Serial_GetChar();
        count++;

        if (count == 7) {
            // Se limpia la LCD, desde la columna 5, desde la cuál se publica los números.
            printLCD(5, 0, "       ");
            printLCD(5, 1, "       ");
            
            // Se extrae el valor de las RPM enviada por el puerto serial.
            RPM_receive = (bufferReceive[0]-'0')*100 + 
                          (bufferReceive[1]-'0')*10 + 
                          (bufferReceive[2]-'0');            
            sprintf(bufferToSend_PWM, "Recibe Vel: %i ", RPM_receive);
            UART_Serial_PutString(bufferToSend_PWM);
            sprintf(RPM_value_String, "%i", RPM_receive);
            printLCD(5, 1, RPM_value_String);

            // Se extrae el valor de la posición enviada por el puerto serial.
            position_receive = (bufferReceive[4]-'0')*100 + 
                               (bufferReceive[5]-'0')*10 + 
                               (bufferReceive[6]-'0');                            
            sprintf(bufferToSend_Pos, "Recibe Pos: %i\n\r", position_receive);
            UART_Serial_PutString(bufferToSend_Pos);
            sprintf(Pos_value_String, "%i", position_receive);
            printLCD(5, 0, Pos_value_String);
            
            // Ecuación que relaciona los PWMs con las RPM.
            // PWM = 39.154ln(RPM) - 58.056
            PWM = 39.154*log(RPM_receive)-58.056;
            PWM_final = (65535*PWM)/(39.154*log(120)-58.056);
            PWM_WriteCompare(PWM_final);
            
            CyDelay(1000);
            sprintf(RPM_reading, "PWM: %.2f", (float)PWM);
            //sprintf(RPM_reading, "PWM: %.2f", (float)PWM_final);
            printLCD(0, 1, RPM_reading);
            printLCD(12, 1, "    ");

            if (bufferReceive[3] == 'i') {
                left_Write(1);
                rigth_Write(0);
            }
            if (bufferReceive[3] == 'd') {
                left_Write(0);
                rigth_Write(1);
            }
            if (bufferReceive[3] == 'p') {
                left_Write(0);
                rigth_Write(0);
                PWM_WriteCompare(0);
            }
            
            UART_Serial_ClearRxBuffer();
            count = 0;
        }
    }
}

CY_ISR(isrTimer) {
    RPM = (float)interruptions_a/160.0*60.0 - 48.0;
    if (RPM < 0) {
        RPM = 0;
    }
    
    //sprintf(RPM_reading, "RPM: %.2f", (float)RPM);
    //printLCD(0, 0, RPM_reading);
    //sprintf(PUL_reading, "PUL: %lu", interruptions_a);
    //printLCD(0, 1, PUL_reading);
    //CyDelay(20);
    //printLCD(0, 1, "");
    //if (RPM == 0) printLCD(0, 1, "RPM: 0.00   rpm");
    
    /* distancia = (paso_del_tornillo / relacion_de_transmision) * revoluciones_del_motor */
    distance = (1 / 80) * RPM;
    distance_final = distance_final + distance;
    
    outTimer_Write(!outTimer_Read());
    
    interruptions_a = 0;
    
    Timer_Stop();
    Timer_WritePeriod(7500);
    Timer_Start();
}

CY_ISR(isrEncoder_A) {
    interruptions_a++;
}

int main(void) {
    CyGlobalIntEnable;
    isr_Serial_StartEx(isrSerial);
    isr_Encoder_A_StartEx(isrEncoder_A);
    isr_Timer_StartEx(isrTimer);
    
    UART_Serial_Start();
    Timer_Start();
    I2C_Start();
    LCD_I2C_start();
    Clock_Start();
    PWM_Start();
    
    printLCD(0, 0, position_String);
    printLCD(0, 1, RPM_String);
    PWM_WriteCompare(0);

    for(;;)
    {
        
    }
}
