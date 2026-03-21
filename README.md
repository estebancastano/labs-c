## Laboratorio # 1: Introducción al lenguaje C
### Nombres, correos y números de documento:
- Esteban Andres Castaño Gallo, esteban.castano1@udea.edu.co, 1001967876
- Jorge Luis Rodriguez, jorge.rodriguezj@udea.edu.co, 1027941053

---

### Documentación del código:
#### wcat.c:
<img width="575" height="376" alt="image" src="https://github.com/user-attachments/assets/9ebb9ac8-1911-46f8-873c-3db429c61d61" />

En este wcat hacemos un for que abre el archivo con fopen y se guarda en la variable fp, luego con un if comprobamos si encontró algún archivo o no y retorna el mensaje: wcat: cannot open file y retorna 1 y sale de la ejecución.

En el ciclo while lo que queremos hacer es que con fgets obtener caracter por caracter e irlo imprimiendo hasta el tamaño del buffer.

#### wgrep.c:
<img width="595" height="282" alt="image" src="https://github.com/user-attachments/assets/bfad0527-bd9b-4d8a-8dc7-13d011ebc8d0" />


#### wzip.c:
<img width="641" height="583" alt="image" src="https://github.com/user-attachments/assets/4f3cee55-5f9c-4d73-a15d-b563f91476e0" />

En este ciclo for lo que hacemos es comparar en el while si el primer caracter del archivo guardado en fp es diferente de EOF que es una variable entera de la librería <stdio.h> y equivale a -1, luego se busca si es el primer caracter del archivo
si así es, se guarda en el contador, en el else if se busca si el caracter actual es igual al anterior y si es así se suma al contador sino son iguales entonces escribimos en binario cuántos llevábamos (contador) y qué letra era (caracter_anterior).
Actualizamos caracter_anterior con la nueva letra y reiniciamos el contador a 1 para empezar de nuevo.

#### wunzip:
<img width="613" height="466" alt="image" src="https://github.com/user-attachments/assets/e66ffd24-c90a-435a-82ed-78c40643a092" />

### Problemas presentados durante el desarrollo de la práctica y sus soluciones:
- **Comprensión de funciones de C:** al ser un lenguaje nuevo, entender el funcionamiento de funciones como `fread`, `fwrite`, `fgets`, `strstr` y `fopen` resultó complejo al inicio. Se consultaron las páginas del manual (`man`) y documentación en línea para entender los parámetros que recibe cada función, qué retorna y cómo manejar los errores correctamente.

- **Archivo guardado en UTF-16 en lugar de UTF-8:** al crear archivos de prueba desde PowerShell, estos se guardaban en UTF-16 causando que los programas no leyeran el contenido correctamente. Solución: crear los archivos directamente desde VSCode verificando que el encoding fuera UTF-8.

### Pruebas realizadas a los programas que verificaron su funcionalidad:

#### wcat.c:
<img width="1434" height="271" alt="image" src="https://github.com/user-attachments/assets/1504ddb1-e265-4104-af96-5c2bc02cf729" />

#### wgrep.c:
<img width="1447" height="220" alt="image" src="https://github.com/user-attachments/assets/4cfc1ca1-372b-4461-bc91-bcc0a65558c8" />
La función `buscar_en_flujo` recibe un término de búsqueda y un flujo de archivo. Lee línea por línea con `fgets` y usa `strstr` para verificar si la línea contiene el término. Si lo encuentra, imprime la línea. En el `main` se valida que se pasen argumentos; si solo se pasa el término sin archivo, lee desde `stdin`; si se pasan archivos, los abre uno por uno y llama a `buscar_en_flujo`.

#### wzip.c:
<img width="1412" height="254" alt="image" src="https://github.com/user-attachments/assets/95285c11-e2ab-44a5-a689-bd6d051ec722" />

#### wunzip.c: 
<img width="885" height="251" alt="image" src="https://github.com/user-attachments/assets/13df7a53-0e74-43d6-b9ce-ba5a437d6cb9" />
Lee el archivo comprimido en bloques de 5 bytes usando `fread`: primero 4 bytes como entero (`contador`) y luego 1 byte como carácter. Repite el carácter `contador` veces con un ciclo `for` imprimiéndolo con `printf`. Continúa hasta llegar al final del archivo.

### Enlace al vídeo:

---

### Manifiesto de transparencia:
