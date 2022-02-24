#!/bin/bash

gcc main.c -o media-control

sudo mv media-control /usr/bin/media-control

echo "You should remove these lines:"
sudo -u $1 cat "/home/$1/.config/sway/config" | grep XF86AudioPlay
sudo -u $1 cat "/home/$1/.config/sway/config" | grep XF86AudioNext
sudo -u $1 cat "/home/$1/.config/sway/config" | grep XF86AudioPrev

sudo -u $1 echo "bindsym --locked XF86AudioPlay exec media-control play-pause" >> "/home/$1/.config/sway/config"
sudo -u $1 echo "bindsym --locked XF86AudioNext exec media-control next" >> "/home/$1/.config/sway/config"
sudo -u $1 echo "bindsym --locked XF86AudioPrev exec media-control previous" >> "/home/$1/.config/sway/config"
