<?php
/**
 * --------------------------------------------------------------------
 * 					Analisador léxico
 * --------------------------------------------------------------------
 * 
 * Alunos: Silvana Trindade e Maurício A. Cinelli 
 * 
 * --------------------------------------------------------------------
 */

//Expressões regulares

// ( a|...|z|A|...|Z|_ )(a|...|z|_|0|...9|A|...|Z )
$identifier = "^[a-zA-Z\_][a-zA-Z0-9\_]*$";
// (0|...|9) + (. ( 0|...|9 )+ )?
$number = "^[0-9]+(\.[0-9]+)?$";
$string = "^\"[\w\W]*\"$";//w minusculo para qualquer caracter de palavra e W para o restante

/**
 * Operadores
 */

// greaters
$gt = "^>$";
$gte = "^>=$";

//less
$lt = "^<$";
$lte = "^<=$";

$eq = "^==$";
$not = "^!$";
$neq = "^!=$";
$ass = "^=$";
$mod = "^\%$";
$plus = "^+$";
$minus = "^-$";
$div = "^\/$";
$mult = "^*$";
$splat = "^...$";

/**
 * Palavras reservadas
 */
$begin = = "^begin$";
$end = "^end$";
$main = "^main$";
$integer = "^int$";
$float = "^float$";
$string = "^string$";
$print = "^print$";
$scan = "^scan$";
$while = "while";
$if = "if";
$for = "for";