#! /bin/bash
echo "Welcome to LudanDWM Install Script"
echo "You will be prompted to enter sudo password, do enter password when prompted"
#Added Minimal dependencies for LudanDWM
sudo pacman -S libx11 libxft imagemagick feh libxinerama xorg-server xorg-xinit ttf-jetbrains-mono noto-fonts python-pip trash-cli --noconfirm 
## Installing Pywal for Wallpaper color support
pip install pywal --break
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
