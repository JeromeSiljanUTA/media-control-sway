#!/bin/bash

sudo -u $1 make

sudo mv media-control-sway /usr/bin/media-control-sway

echo "You should remove these lines:"
sudo -u $1 cat "/home/$1/.config/sway/config" | grep XF86AudioPlay
sudo -u $1 cat "/home/$1/.config/sway/config" | grep XF86AudioNext
sudo -u $1 cat "/home/$1/.config/sway/config" | grep XF86AudioPrev

sudo -u $1 echo "bindsym --locked XF86AudioPlay exec media-control-sway play-pause" >> "/home/$1/.config/sway/config"
sudo -u $1 echo "bindsym --locked XF86AudioNext exec media-control-sway next" >> "/home/$1/.config/sway/config"
sudo -u $1 echo "bindsym --locked XF86AudioPrev exec media-control-sway previous" >> "/home/$1/.config/sway/config"
