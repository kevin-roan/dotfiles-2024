#! /bin/bash
echo "Welcome to LudanDWM Install Script"
echo "You will be prompted to enter sudo password, do enter password when prompted"
ls
cd dmenu
sudo make clean install
cd ../dwm
sudo make clean install
cd ../dwmblocks
sudo make clean install
cd ../slock
sudo make clean install
cd ../st
sudo make clean install
pwd 
cd ../.. 
sudo cp tlp.conf /etc/
mv ./config ~/.config
