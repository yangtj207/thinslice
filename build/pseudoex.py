import os

for i in range(20):
    os.system("./../install/bin/RunCrossSection -c ../json/config.json")
    os.system("./../install/bin/BackgroundFit -c ../json/bkgfit.json")
    os.system("./../install/bin/RunCalcXS -c ../json/xs.json")
    os.system("root -b -q ../macros/pion/plotXS_data.C")