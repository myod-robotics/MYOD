NO CAMBIAR NUNGÚN DEFINE EXCEPTO desCDG sin entender el funcionamiento. Un valor erroneo puedo provocar un mal funcionamiento o la avería del robot.

desCDG permite balancear el cuerpo del robot más hacia un lado que hacia a otro. Esta indicación permite corregir la desviación del centro de gravedad a derecha o izquierda
El rango de valores de este parámetro esta entre -1 y 1, recomendando no excederse de -0,1 y 0,1.
Para que el cambio surja efecto es necesario volver a compilar el fichero con un compilador, como por ejemplo DEV-C++ o QT creator.

PARA QUE EL PROGRAMA FUNCIONE CORRECTAMENTE necesita tener dos carpetas (config y exported) en la misma ubicación que el archivo ejecutable.
En estas carpetas de guardaran los movimientos generados asi como la configuración de motores del robot.
Para que sea más cómodo, dejo guardado la configuración de motores de MYOD en la carpeta config. Para usarla basta con cargarla al iniciar el programa con 
->0 (Enter) myod (Enter)