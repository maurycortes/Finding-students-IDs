#!/bin/bash
#suma los digitos de un numero
#d es la variable
#"$@" es el cin
# echo inicializa en 0
#bc es la calculadora
{ printf %d+ "$@"; echo 0; } | bc




#!/bin/bash
#promedio de 8 digitos
read a b c d e f g h 
sum=$(( $a + $b + $c + $d + $e + $f + $g + $h ))
count=8
result=$(echo "scale=2; 1.0 * $sum / $count" | bc -l)
echo "El promedio es " $result


#!/bin/bash
#promedio de n digitos
for (( i = 0 ; i <= $# ; i++ ))
do
read a
sum=$(( $a + $a ))
done
resultado={ printf %d+ "$@"; echo 0; } | bc
echo "El promedio es " $resultado


#!/bin/bash
sum=0
for arg in "$@"; do 
	sum=`expr $sum + $arg`
done
echo $sum
echo $#
echo "scale=2; $sum / $#" | bc