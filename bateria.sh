#!/bin/sh
echo -----------------lenna
./bin/desplazar 4 lenna.pgm le4.pgm
./bin/negativo lenna.pgm le2.pgm
./bin/ocultar lenna.pgm le3.pgm < mensa2.txt
./bin/revelar le3.pgm
echo -----------------hombro
./bin/desplazar 4 hombro.pgm ho4.pgm
./bin/negativo hombro.pgm ho2.pgm
./bin/ocultar hombro.pgm ho3.pgm < mensa2.txt
./bin/revelar ho3.pgm
echo -----------------almenas
./bin/desplazar 4 almenas.pgm al4.pgm
./bin/negativo almenas.pgm al2.pgm
./bin/ocultar almenas.pgm al3.pgm < mensa2.txt
./bin/revelar al3.pgm
echo -----------------error
./bin/desplazar 4 adf.pgm adfd.pgm
./bin/negativo adf.pgm adfd.pgm
./bin/ocultar adf.pgm adfd.pgm < mensa2.txt
./bin/revelar adf.pgm
echo -----------------generar
./bin/generar 1098 B p1098B.per
./bin/generar 1098 T p1098T.per
./bin/generar 1098 Z p1098Z.per
echo -----------------permutar
./bin/permutar hombro.pgm p1098B.per hop1.pgm
./bin/permutar hombro.pgm p1098T.per hop2.pgm
./bin/permutar hombro.pgm p1098A.per hop3.pgm
./bin/permutar lenna.pgm p1098B.per lep1.pgm
echo -----------------permutar -d
./bin/permutar -d hop1.pgm p1098B.per hop11.pgm
./bin/permutar -d hop2.pgm p1098T.per hop22.pgm
./bin/permutar -d hop3.pgm p1098B.per hop33.pgm
