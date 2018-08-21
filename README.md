#Mini tester de bater�as con Arduino. 

Mini tester para bater�as de 1.5V maneja rango de 0-1.8V.

Los Led encender�n seg�n los siguientes valores.

�	voltaje es mayor o igual a 1.5V (Verde)

�	voltaje se encuentra en el rango entre 1.2 a 1.5V (Amarillo)
    
�	voltaje se encuentra en el rango entre 0.4 a 1.2V (Rojo)

En caso de querer modificarlos

//Valores de rangos de las luces en voltios 
float fValorParaLedVerde = 1.5;
float fValorParaLedAmarillo = 1.2;
float fValorParaLedRojo = 0.4;

***********************************************************************************

Archivo Fritzing con esquema del proyecto �tester.fzz�  

Descargar Fritzing:

http://fritzing.org/download/

***********************************************************************************

Video YouTube:

https://youtu.be/TmjDYarNfmA

***********************************************************************************

NOTAS IMPORTANTES:

�	Respetar las polaridades a la hora de probar la bater�a

�	El sistema est� dise�ado para voltajes de 0-1.8V. aunque una entrada anal�gica podr�a manejar hasta 5 voltios evitar sobrepasar el rango anteriormente mencionado. (Exceder podr�a da�ar la placa del Arduino)
