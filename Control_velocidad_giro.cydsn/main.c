#include "project.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Declaración del variables de la comunicación serial (UART).
char bufferReceive[9];
char bufferToSend_PWM[20];
char bufferToSend_Time[20];
char RPM_value_String[3];
int16 RPM_receive = 0;
char Time_value_String[3];
int time_receive = 1;
int count = 0;

// Declaración de estado inicial de la LCD
char time_String[16] =     "Giro: Parado    ";
char RPM_String[16] =      "VEL : 0      rpm";

// Declaración de las variables necesarias para leer las interrupciones
float RPM;

char RPM_reading[6];
float PWM;
float PWM_final;
uint16 time;
char time_reading[20];

int secuence[4][4] = {{1,0,0,0} ,
                     { 0,1,0,0} ,
                     { 0,0,1,0} ,
                     { 0,0,0,1} };
float function_delay;
char string_function_delay[6];
double aceleration = 0.0;

void printLCD(int column, int row, char message[16]) {
    LCD_I2C_setCursor(column, row);
    LCD_I2C_print(message);
}

CY_ISR(isrSerial) {
    if (UART_Serial_GetRxBufferSize() > 0) {
        bufferReceive[count] = UART_Serial_GetChar();
        count++;

        if (count == 7) {            
            // Se extrae el valor de las RPM enviada por el puerto serial.
            RPM_receive = (bufferReceive[0]-'0')*100 + 
                          (bufferReceive[1]-'0')*10 + 
                          (bufferReceive[2]-'0');            
            //sprintf(bufferToSend_PWM, "Recibe Vel: %i|", RPM_receive);
            //UART_Serial_PutString(bufferToSend_PWM);
            sprintf(RPM_value_String, "%i    ", RPM_receive);
            printLCD(6, 1, RPM_value_String);

            // Se extrae el valor de la posición enviada por el puerto serial.
            time_receive = (bufferReceive[4]-'0')*100 +
                           (bufferReceive[5]-'0')*10 +
                           (bufferReceive[6]-'0');                            
            //sprintf(bufferToSend_Time, "Recibe Time: %i\n\r", time_receive);
            //UART_Serial_PutString(bufferToSend_Time);
            sprintf(Time_value_String, "%i  ", time_receive);
            printLCD(6, 0, "          ");
            printLCD(6, 0, Time_value_String);
            
            if (bufferReceive[3] == 'i') {
                printLCD(0, 0, "Giro: Izquierda ");
                aceleration = 0;
                //time = 0;
                RPM = 0;
            }
            if (bufferReceive[3] == 'd') {
                printLCD(0, 0, "Giro: Derecha   ");
                aceleration = 0;
                //time = 0;
                RPM = 0;
            }
            if (bufferReceive[3] == 'p') {
                printLCD(0, 0, "Giro: Parando   ");
            }

            UART_Serial_ClearRxBuffer();
            count = 0;
        }
    }
}

CY_ISR(isrTimer) {
    Counter_Stop();
    RPM = (60*Counter_ReadCounter()/50);
    sprintf(RPM_reading, "%.0f   ", RPM);
    printLCD(6, 1, RPM_reading);
    if (RPM_receive != 0) {
        sprintf(bufferToSend_PWM, "Envia Vel: %.0f|", RPM);
        UART_Serial_PutString(bufferToSend_PWM);
    }
    Counter_WriteCounter(0);
    Counter_Start();
    
    if (aceleration <= RPM_receive && bufferReceive[3] != 'p' && bufferReceive[3] != '\0') {
        aceleration = aceleration + (RPM_receive/time_receive);
        function_delay = pow(aceleration, -0.94);
        function_delay = 226.8 * function_delay;
        //sprintf(string_function_delay, "%.0f   ", function_delay);
        //printLCD(6, 0, string_function_delay);
        time = time + 1;
    }
    if (aceleration >= 5 && bufferReceive[3] == 'p') {
        aceleration = aceleration - (RPM_receive/time_receive);
        function_delay = pow(aceleration, -0.94);
        function_delay = 226.8 * function_delay;
        //sprintf(string_function_delay, "%.0f   ", function_delay);
        //printLCD(6, 0, string_function_delay);
        time = time + 1;
    }
    
    if (RPM_receive != 0) {
        sprintf(time_reading, "Envia Time: %i\n\r", time);
        UART_Serial_PutString(time_reading);
    }
    //printLCD(0, 0, time_reading);
}

int main(void) {
    CyGlobalIntEnable;
    isr_Serial_StartEx(isrSerial);
    isr_Timer_StartEx(isrTimer);
    
    UART_Serial_Start();
    Timer_Start();
    I2C_Start();
    LCD_I2C_start();
    
    printLCD(0, 0, time_String);
    printLCD(0, 1, RPM_String);

    for(;;) {
        if (bufferReceive[3] == 'd') {
            Trigger_Write(1u);
            for(int i=0; i<4; i++) {
                Out_1_Write(secuence[i][0]);
                Out_2_Write(secuence[i][1]);
                Out_3_Write(secuence[i][2]);
                Out_4_Write(secuence[i][3]);
                CyDelay(function_delay);
            }
            Trigger_Write(0u);
            CyDelay(1u);            
        }
        if (bufferReceive[3] == 'i') {
            Trigger_Write(1u);
            for(int i=3; i>=0; i--) {
                Out_1_Write(secuence[i][0]);
                Out_2_Write(secuence[i][1]);
                Out_3_Write(secuence[i][2]);
                Out_4_Write(secuence[i][3]);
                CyDelay(function_delay);
            }
            Trigger_Write(0u);
            CyDelay(1u);            
        }
        if (aceleration >= 5 && bufferReceive[3] == 'p') {
            Trigger_Write(1u);
            for(int i=3; i>=0; i--) {
                Out_1_Write(secuence[i][0]);
                Out_2_Write(secuence[i][1]);
                Out_3_Write(secuence[i][2]);
                Out_4_Write(secuence[i][3]);
                CyDelay(function_delay);
            }
            Trigger_Write(0u);
            CyDelay(1u);            
        }
        if (aceleration < 5 && bufferReceive[3] == 'p') {
            Out_1_Write(0);
            Out_2_Write(0);
            Out_3_Write(0);
            Out_4_Write(0);
        }
    }
}
