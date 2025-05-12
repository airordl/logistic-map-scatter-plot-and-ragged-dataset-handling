RUN () {
rm *.dat
touch logi.dat
g++ logistic.C
./a.out && rm a.out
python plot.py
}
