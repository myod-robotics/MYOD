Este programa utiliza la memoria eeprom de la placa arduino. 
La vida útil de esta memoria es de 100k escrituras.
Por defecto toda la memoria viene grabada en cada una de sus celdas con el valor 255. Por lo que
ES OBLIGATORIO BORRARLAR antes de usar este programa por primera vez. En el caso de no hacelo
se pueden originar daños graves en los motores o en los elementos estructurales al llevar al motor
a una posicón límite.
Para borrar esta memoria hay que usar el archivo: ejemplo->EEPROM->eeprom-clear.
